#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[target - nums[i]] = i;
            } else {
                result.push_back(m[nums[i]]);
                result.push_back(i);
            }
        }

        return result;

    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v = {2, 7, 13, 4, 11, 5, -2};
    int target = 9;
    vector<int> r = s.twoSum(v, target);
    for (vector<int>::iterator iter = r.begin(); iter != r.end(); iter++) {
        cout << *iter << "\t";
    }

    cout << endl;

    return 0;
}
