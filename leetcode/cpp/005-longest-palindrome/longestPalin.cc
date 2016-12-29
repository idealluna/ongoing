#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int v = 0, p = 0, m = 0, l = 1;
        while (p < s.length() - 1) {
            if (s[p] == s[p + 1]) {
                while ((p - v) >= 0 && (p + v + 1) < s.length()
                        && s[p - v] == s[p + v + 1]) {
                    v++;
                }
                if (l < 2 * v) {
                    m = p - (v - 1);
                    l = 2 * v;
                }
                v = 0;
            }
            if (s[p - v] == s[p + v]) {
                while ((p - v) >= 0 && (p + v) < s.length()
                        && s[p - v] == s[p + v]) {
                    v++;
                }
                if (l < 2 * (v - 1) + 1) {
                    m = p - (v - 1);
                    l = 2 * (v - 1) + 1;
                }
                v = 0;
            }
            p++;
            v = 0;
        }

        //cout << m << "\t" << l << endl;
        return  s.substr(m, l);
    }
};

string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}

int main()
{
    vector<string> strs = {/*"esabadc",
                            "a",
                            "aa",
                            "aaa",
                            "aaaa",
                            "aaaaa",
                            "aaaaasaaaa",
                            "aaaaasaaaaa",
                            "asasasasa",
                            "asasaqwe",
                            "qweasasa",
                            "aaaaqwer", */
                            "asdyyvvyfsd",
                            "asdyyvvvvyfsd",
                            "asdyyvvvyfsd",
                            "asaaaaqwer",
                            "aaqwer",
                            "qweraaaa"
    };

    Solution s;
    for (unsigned int i = 0; i < strs.size(); i++) {
        //OBfor (int j = 0; j < 1000000; j++)
        //    //longestPalindrome(strs[i]);
        //    s.longestPalindrome(strs[i]);
        cout << s.longestPalindrome(strs[i]) << endl;
        //cout << longestPalindrome(strs[i]) << endl;
    }

    return 0;
}
