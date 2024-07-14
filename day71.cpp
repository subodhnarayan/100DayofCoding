// //Gfg POTD 15/07/2024

// Segregate 0s and 1s
// Difficulty: EasyAccuracy: 54.25%Submissions: 99K+Points: 2
// Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

// Examples :

// Input: arr[] = [0, 0, 1, 1, 0]
// Output: [0, 0, 0, 1, 1]
// Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].
// Input: arr[] = [1, 1, 1, 1]
// Output: [1, 1, 1, 1]
// Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int n = arr.size();
        int zc = 0;
        int oc = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zc++;
            }
            else
            {
                oc++;
            }
        }
        for (int i = 0; i < zc; i++)
        {
            arr[i] = 0;
        }
        for (int i = zc; i < n; i++)
        {
            arr[i] = 1;
        }
    }
};

//LEETCODE POTD 

// 726. Number of Atoms
// Solved
// Hard
// Topics
// Companies
// Hint
// Given a string formula representing a chemical formula, return the count of each atom.

// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.

// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.

// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

// The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

// Example 1:

// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.
// Example 2:

// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
// Example 3:

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 

// Constraints:

// 1 <= formula.length <= 1000
// formula consists of English letters, digits, '(', and ')'.
// formula is always valid.

class Solution {
public:
    string countOfAtoms(string form) {
        //same name ke liye na wo 
         stack<unordered_map<string, int>> st;
    st.push(unordered_map<string, int>());
    int n = form.size();
    int i = 0;

    while (i < n) {
        if (form[i] == '(') {
            st.push(unordered_map<string, int>());
            i++;  // Move past the '('
        } else if (form[i] == ')') {
            unordered_map<string, int> curr = st.top();
            st.pop();
            i++;  // Move past the ')'
            string mul;
            while (i < n && isdigit(form[i])) {
                mul += form[i];
                i++;
            }
            int multiplier = mul.empty() ? 1 : stoi(mul);

            // Multiply counts in the current map
            for (auto& ig : curr) {
                ig.second *= multiplier;
            }

            // Merge current map into the previous map on the stack
            for (const auto& it : curr) {
                st.top()[it.first] += it.second;
            }
        } else {
            string str;
            str.push_back(form[i]);
            i++;
            while (i < n && islower(form[i])) {
                str += form[i];
                i++;
            }

            string mul;
            while (i < n && isdigit(form[i])) {
                mul += form[i];
                i++;
            }
            int cnt = mul.empty() ? 1 : stoi(mul);
            st.top()[str] += cnt;
        }
    }

    // Sort the elements alphabetically
    map<string, int> ans(begin(st.top()), end(st.top()));
    string result;

    for (const auto& it : ans) {
        result += it.first;
        if (it.second > 1) {
            result += to_string(it.second);
        }
    }

    return result;
    }
};