#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        /*
        int i = 0, b = -1, r = 0;
        while (i < s.length()) {
            if (m.count(s[i])) 
                b = max(b, m[s[i]]);

            m[s[i]] = i;
            r = max(r, i - b);
            i++;
        }
        int i = 0, r = 0, len = 0;
        while (i < s.length()) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
                len++;
                i++;
            } else {
                r = (r > len) ? r : len;
                i = m[s[i]] + 1;
                len = 0;
                m.clear();
            }
            r = (r > len) ? r : len;
        }
        */
        int i = 0, r = 0, b = -1;
        while (i < s.length()) {
            if (m.count(s[i])) {
                b = max(b, m[s[i]]);
            }
            m[s[i]] = i;
            r = (r > i - b) ? r : i - b;
            i++;
        }
        if (r == 0)
            r = s.length();
        return r;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<string> strs = {"aab", "abcabcbb", "bbbbb", "pwwkew", "abcdefgha", "abcdefghqwrty"};
    for (int i = 0; i < strs.size(); i++) {
        cout << s.lengthOfLongestSubstring(strs[i]) << endl;
    }
    return 0;
}
