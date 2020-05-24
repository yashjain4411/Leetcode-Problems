#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(1, k, curr, ans, n);
        return ans;
    }
    void helper(int start, int rem, vector<int> curr, vector<vector<int>> &ans, int n) {
        if (rem == 0) {
            ans.push_back(curr);
        } else {
            for (int i = start; i <= n - rem + 1; i++) {
                curr.push_back(i);
                helper(i + 1, rem - 1, curr, ans, n);
                curr.pop_back();
            }
        }
    }
};