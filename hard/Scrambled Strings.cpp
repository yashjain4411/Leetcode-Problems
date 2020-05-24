#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() == 0) {
            return true;
        }
        return helper(s1, s2, 0, s1.length() - 1);
    }
    bool helper(string s1, string s2, int i, int j) {
        if (!isAnagram(s1, s2)) {
            return false;
        }
        if (i == j) {
            return true;
        }
        bool ans = false;
        for (int len1 = 1; len1 <= j - i + 1 - 1; len1++) {
            int len2 = j - i + 1 - len1;
            ans = (ans || ((helper(s1.substr(0, len1), s2.substr(0, len1), 0, len1 - 1) && helper(s1.substr(len1, len2), s2.substr(len1, len2), len1, len1 + len2 - 1)) ||
                           (helper(s1.substr(0, len1), s2.substr(len2, len1), 0, len1 - 1) && helper(s1.substr(len1, len2), s2.substr(0, len2), len1, len1 + len2 - 1))));
        }
        return ans;
    }
    bool isAnagram(string s1, string s2) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            cnt[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            cnt[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                return false;
            }
        }
        return true;
    }
};