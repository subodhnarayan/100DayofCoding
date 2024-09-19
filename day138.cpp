-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 18 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Parenthesis Checker
Difficulty: EasyAccuracy: 28.56%Submissions: 596K+Points: 2
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".

Examples :

Input: {([])}
Output: true
Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.
Input: ()
Output: true
Explanation: (). Same bracket can form balanced pairs,and here only 1 type of bracket is present and in balanced way.
Input: ([]
Output: false
Explanation: ([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 105

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
          stack<char>s;
     for(auto &i:x){
         if(i=='(' || i=='[' || i=='{'){
             s.push(i);
         }
         else{
             if(s.empty()) return false;
             char ch=s.top();
             s.pop();
             if(ch=='(' && i!=')' || ch=='{' && i!='}' || ch=='[' && i!=']'){
                 return false;
             }
             
         }
     }
     if(!s.empty()) return false;
     return true;
    }

};

-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

179. Largest Number
Solved
Medium
Topics
Companies
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109


class Solution {
public:
    string largestNumber(vector<int>& nums) {
           // Convert integers to strings
        vector<string> array;
        for (int num : nums) {
            array.push_back(to_string(num));
        }

        // Custom comparator for sorting
        sort(array.begin(), array.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        // Handle the case where the largest number is "0"
        if (array[0] == "0") {
            return "0";
        }

        // Build the largest number from the sorted array
        string largest;
        for (const string &num : array) {
            largest += num;
        }

        return largest;
    }
}

