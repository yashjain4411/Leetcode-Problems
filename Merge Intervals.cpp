#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
				vector<vector<int> > ans;
				if(intervals.empty()){
					return ans;
				}
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int>b){
					if(a[0] < b[0]){
						return true;
					}
					if(a[0] == b[0]){
						return a[1] > b[1];
					}
					return false;
				});
				int currStart = intervals[0][0];
				int maxReach = intervals[0][1];
				for(int i=0;i<intervals.size();i++){
					if(intervals[i][0] <= maxReach){
						maxReach = max(maxReach,intervals[i][1]);
					}
					else{
						ans.push_back(vector<int>{currStart,maxReach});
						currStart = intervals[i][0];
						maxReach = intervals[i][1];
					}
				}
				ans.push_back(vector<int>{currStart,maxReach});
				return ans;
    }
};