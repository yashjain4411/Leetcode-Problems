#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int maximumArea = 0;
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                int currHeight = heights[st.top()];
                st.pop();
                maximumArea = max(maximumArea, (i - 1 - (st.empty() ? 0 : st.top() + 1) + 1) * currHeight);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int currHeight = heights[st.top()];
            st.pop();
            maximumArea = max(maximumArea, ((int)heights.size() - 1 - (st.empty() ? 0 : st.top() + 1) + 1) * currHeight);
        }
        return maximumArea;
    }
};