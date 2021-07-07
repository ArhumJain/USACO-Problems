#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int numIndex1 {0};
    int numIndex2 {0};
    for (auto i: nums)
    {
        for (auto j: nums)
        {
            if (i + j == target && &nums[numIndex1] != &nums[numIndex2])
            {
                return vector<int> {numIndex1, numIndex2};
            }
            numIndex2++;
        }
        numIndex1++;
        numIndex2 = 0;
    }
    return vector<int> {-1,-1};
}
int main()
{
    vector<int> nums {2,7,11,15};
    int target {9};
    vector<int> result{twoSum(nums, target)};
    cout << result[0] << " " << result[1] << endl;
}