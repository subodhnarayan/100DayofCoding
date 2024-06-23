// Print Bracket Number
// Difficulty: EasyAccuracy: 51.19%Submissions: 47K+Points: 2
// Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string.

//  Examples:

// Input:  str = "(aa(bdc))p(dee)"
// Output: 1 2 2 1 3 3
// Explanation: The highlighted brackets in
// the given string (aa(bdc))p(dee) are
// assigned the numbers as: 1 2 2 1 3 3.
// Input:  str = "(((()("
// Output: 1 2 3 4 4 5
// Explanation: The highlighted brackets in
// the given string (((()( are assigned
// the numbers as: 1 2 3 4 4 5
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 <= |str| <= 105
// str contains lowercase English alphabets, and '(', ')' characters
// At any index, the number of opening brackets is greater than or equal to closing brackets

class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        vector<int> ans;
        stack<int> st;
        int cnt = 0;

        for (char c : str)
        {

            if (c == '(')
            {
                cnt++;
                st.push(cnt);
                ans.push_back(cnt);
            }

            else if (c == ')')
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};