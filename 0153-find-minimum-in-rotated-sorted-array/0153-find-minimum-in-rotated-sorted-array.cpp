
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int res = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[l]) 
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};
// @lc code=end
