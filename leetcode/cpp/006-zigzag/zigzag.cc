#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = numRows;
        if (n <= 1) return s;
        int l = s.length();
        int x = l / (n - 1) + 1;
        string r = "";
        if (n == 2) {
            for (int j = 0; j < l; j++)
                if (j % 2 == 0)
                    r += s[j];
            for (int j = 0; j < l; j++)
                if (j % 2 == 1)
                    r += s[j];
            return r;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= x; j++) {
                if ((j % 2 == 0) && (j * (n - 1) + i < l) && (i != n - 1)) {
                    r += s[j * (n - 1) + i];
                } else if ((j % 2 == 1) && ((j + 1) * (n - 1) - i < l) && (i != 0)) {
                    r += s[(j + 1) * (n - 1) - i];
                }
            }
        }
        return r;
    }
};

int main(int argc, char *argv[])
{
    string strs = "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";

    Solution s;
    cout << s.convert(strs, 0) << endl;
    cout << s.convert(strs, 1) << endl;
    cout << s.convert(strs, 2) << endl;
    cout << s.convert(strs, 3) << endl;
    cout << s.convert(strs, 4) << endl;
    cout << s.convert(strs, 5) << endl;
    /*
    for (int j = 0; j <= x; j++) {
        if (j % 2 == 0)
            cout << s[j * (n - 1)];
    }
    */
    /*
    if (n == 2) {
        for (int j = 0; j < l; j++)
            if (j % 2 == 0)
                cout << s[j];
        for (int j = 0; j < l; j++)
            if (j % 2 == 1)
                cout << s[j];
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if ((j % 2 == 0) && (j * (n - 1) + i < l) && (i != n - 1)) {
                cout << s[j * (n - 1) + i];
            } else if (((j + 1) * (n - 1) - i < l) && (i != 0)) {
                cout << s[(j + 1) * (n - 1) - i];
            }
        }
    }
    */

    /*
    for (int j = 0; j <= x; j++) {
        if (j % 2 == 1)
            cout << s[j * (n - 1)];
    }
    */

    cout << endl;
    return 0;
}
