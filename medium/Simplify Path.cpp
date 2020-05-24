#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> splitString;
        string curr = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (!curr.empty()) {
                    if (curr.compare(".") != 0) {
                        splitString.push_back(curr);
                    }
                    curr = "";
                }
                if (!splitString.empty() && splitString.back().compare("/") == 0) {
                    continue;
                } else {
                    splitString.push_back("/");
                }
            } else {
                curr += path[i];
            }
        }
        if (!curr.empty()) {
            if (curr.compare(".") != 0) {
                splitString.push_back(curr);
            }
        }
        stack<string> directory;
        for (int i = 0; i < splitString.size(); i++) {
            if (splitString[i].compare("/") == 0) {

            } else if (splitString[i].compare("..") == 0) {
                if (!directory.empty()) {
                    directory.pop();
                }
            } else {
                directory.push(splitString[i]);
            }
        }
        string ans = directory.empty() ? "/" : "";
        while (!directory.empty()) {
            if (ans.empty()) {
                ans = "/" + directory.top();
            } else {
                ans = "/" + directory.top() + ans;
            }
            directory.pop();
        }
        return ans;
    }
};