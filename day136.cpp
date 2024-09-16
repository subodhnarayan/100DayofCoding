- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 16 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Longest valid Parentheses
Difficulty: HardAccuracy: 26.13%Submissions: 123K+Points: 8
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105  

class Solution {
  public:
    int maxLength(string& str) {
        // stack<char> st;
        // int count=0;
        // for(int i=0;i<str.size();i++){
        //     if(st.empty()){
        //         st.push(str[i]);
        //     }
        //     else if(str[i]==')'){
        //         if(st.top()=='('){
        //             count+=2;
        //             st.pop();
        //         }
        //         else{
        //             st.push(str[i]);
        //         }
        //     }
        //     else{
        //         st.push(str[i]);
        //     }
        // }
        // return count;
        
        int max1=0,max2=0,op=0,cl=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                op++;
            }
            else{
                cl++;
            }
            if(op<cl){
                op=cl=0;
            }
            if(op==cl){
                max1=max(max1,2*op);
            }
        }
        op=cl=0;
        
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='('){
                op++;
            }
            else{
                cl++;
            }
            if(op>cl){
                op=cl=0;
            }
            if(op==cl){
                max2=max(max2,2*op);
            }
            
        }
        return max(max1,max2);
    }
};



 -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 16 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

539. Minimum Time Difference
Solved
Medium
Topics
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".


class Solution {
public:
    int dist(string a,string b){
        // int h1=stoi(a.substr(0,2));
        // int m1=stoi(a.substr(3,5));
        // int h2=stoi(b.substr(0,2));
        // int m2=stoi(a.substr(3,5));

        // if(h2<h1){
        //     m2=60+m2;
        // }

        // if(h2>h1 and m2<m1){
        //     m2=60+m2;
        // }
        // return m2-m1;

        int h1 = stoi(a.substr(0, 2));
        int m1 = stoi(a.substr(3, 2));
        int h2 = stoi(b.substr(0, 2));
        int m2 = stoi(b.substr(3, 2));

        int t1 = h1 * 60 + m1;  // total minutes for time a
        int t2 = h2 * 60 + m2;  // total minutes for time b

        // Calculate the difference in minutes
        int diff = abs(t1 - t2);
        // Consider the circular nature of time (1440 minutes in a day)
        return min(diff, 1440 - diff);

    }
    int findMinDifference(vector<string>& timePoints) {
        // int ans=INT_MAX;
        // int n=time.size();
        // for(int i=0;i<n-1;i++){
        //   for(int j=i+1;j<n;j++){
        //     string a=time[i];
        //     string b=time[j];
        //     ans=min(ans,dist(a,b));
        //   }
        // }
        // return ans;

           int n = timePoints.size();
        if (n > 1440) return 0; // There are only 1440 minutes in a day, so duplicate times must give 0 difference

        // Sort the time points to make comparison easier
        sort(timePoints.begin(), timePoints.end());

        // Initialize the minimum difference as the max possible (1440 minutes)
        int ans = INT_MAX;

        // Compare adjacent times
        for (int i = 1; i < n; i++) {
            ans = min(ans, dist(timePoints[i], timePoints[i - 1]));
        }

        // Don't forget to compare the first and last time (because of circular nature of time)
        ans = min(ans, dist(timePoints[0], timePoints[n - 1]));

        return ans;
    }
};