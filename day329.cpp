-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Stickler Thief
Difficulty: MediumAccuracy: 37.98%Submissions: 242K+Points: 4Average Time: 20m
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
Determine the maximum amount he can loot.

Examples:

Input: arr[] = [6, 5, 5, 7, 4]
Output: 15
Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6 + 5 + 4 = 15.
Input: arr[] = [1, 5, 3]
Output: 5
Explanation: Loot only 2nd house and get maximum amount of 5.
Input: arr[] = [4, 4, 4, 4]
Output: 8
Explanation: The optimal choice is to loot every alternate house. Looting the 1st and 3rd houses, or the 2nd and 4th, both give a maximum total of 4 + 4 = 8.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

Time Complexity: O(n)Auxiliary Space: O(1)


class Solution {
    public:
      int findMaxSum(vector<int>& arr) {
          // code here
      int n=arr.size();
      if (n == 0) {
          return 0;
      } else if (n == 1) {
          return arr[0];
      }
  
      // Create an array to store the maximum loot up to the i-th house
      int dp[n];
  
      // Base cases
      dp[0] = arr[0];
      dp[1] = max(arr[0], arr[1]);
  
      // Calculate the maximum loot for each house
      for (int i = 2; i < n; i++) {
          dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
      }
  
      // The last element of dp[] will contain the maximum loot
      return dp[n - 1];
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 21 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Given Supplies
Medium
Topics
Companies
Hint
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.


class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_set<string> available_supplies(supplies.begin(), supplies.end());
            unordered_map<string, vector<string>> ingredient_to_recipes;
            unordered_map<string, int> in_degree;
            unordered_map<string, vector<string>> recipe_to_ingredients;
    
            for (int i = 0; i < recipes.size(); i++) {
                string recipe = recipes[i];
                recipe_to_ingredients[recipe] = ingredients[i];
                in_degree[recipe] = ingredients[i].size();
    
                for (const string& ingredient : ingredients[i]) {
                    ingredient_to_recipes[ingredient].push_back(recipe);
                }
            }
    
            queue<string> q;
            for (const string& supply : supplies) {
                q.push(supply);
            }
    
            vector<string> result;
    
            while (!q.empty()) {
                string current = q.front();
                q.pop();
    
                if (recipe_to_ingredients.find(current) != recipe_to_ingredients.end()) {
                    result.push_back(current);
                }
    
                if (ingredient_to_recipes.find(current) != ingredient_to_recipes.end()) {
                    for (const string& dependent_recipe : ingredient_to_recipes[current]) {
                        in_degree[dependent_recipe]--;
                        if (in_degree[dependent_recipe] == 0) {
                            q.push(dependent_recipe);
                        }
                    }
                }
            }
    
            return result;
        }
    };