/*
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums
 * such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 *  [-1, 0,  0, 1],
 *  [-2, -1, 1, 2],
 *  [-2, 0,  0, 2],
 * ]
 */
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> total;
            int n = nums.size();
            if (n < 4) return total;

            sort(nums.begin(), nums.end());

            for (int i = 0; i < n - 3; i++) {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;
                if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                    break;
                if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                    continue;

                for (int j = i + 1; j < n - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) 
                        break;
                    if (nums[i] + nums[j] + nums[n - 2] + nums[n - 2] < target)
                        continue;

                    int left = j + 1, right = n - 1;
                    while (left < right) {
                        int sum = nums[left] + nums[right] + nums[i] + nums[j];
                        if (sum < target) left++;
                        else if (sum > target) right--;
                        else {
                            total.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                            do {left++;} while(nums[left] == nums[left - 1] && left < right);
                            do {right--;} while(nums[right] == nums[right + 1] && left < right);
                        }
                    }
                }
            }
            return total;
        }
};

class Solution {
    public:

        vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
            vector<vector<int>> res;
            unordered_set<int> s;

            for (auto i = start; i < nums.size(); i++) {
                if (res.empty() || res.back()[1] != nums[i])
                    if (s.count(target - nums[i]))
                        res.push_back({target - nums[i], nums[i]});
                s.insert(nums[i]);
            }

            return res;
        }

        vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
            vector<vector<int>> res;

            if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
                return res;

            if (k == 2)
                return twoSum(nums, target, start);

            for (int i = start; i < nums.size(); i++) {
                if (i == start || nums[i - 1] != nums[i]) {
                    for (auto & set: kSum(nums, target - nums[i], i + 1, k - 1)) {
                        res.push_back({nums[i]});
                        res.back().insert(end(res.back(), begin(set), end(set));)
                    }
                }
            }

            return res;
        }

        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), sort.end());

            return kSum(nums, target, 0, 4);
        }
};
