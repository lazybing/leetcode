// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * Given an array of integers, return indices of tow numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example: given nums = [2, 7, 11, 15], target = 9
 * because nums[0] + nums[1] == 9;
 * return [0, 1]
 *
 * Test Case && Boundary Test : 
 * 1.nums empty  (nums = [], taregt = 9) return vector<int>{}
 * 2.only has one element (nums = [9], target = 9) return vector<int>{}
 * 3.no nums[i] + nums[j] == target (nums = [2, 7, 11, 15], target = 100) return vector<int>{}
 * 4.only the same element twice equals to target 2 * nums[i] == target (nums = [2, 7, 11, 15], taregt = 4) return vector<int>{}
 *
 * Think more: 
 * 1.If nums[2, 2, 7, 11, 15], target = 4, return [0, 1]. Because both nums[0] and nums[1] are equal to 2. Does this res have the same element twice?
 * 2.If the given array is sorted. Does it have a more efficency solution?
 * 3.If the given array has duplicated elements, how can you store the all solutions?
 * 4.If it has a solution [idx1, idx2], how can you guarantee the idx1 less than idx2?
 *
 */
class Solution {
    public:
        /*
         * Brute Force Solution
         *
         * Time complexity: O(n^2)
         * Space complexity: O(1)
         */
        vector<int> twoSum1_ans1(vector<int>& nums, int target) {
            if (nums.size() <= 1)
                return vector<int>{};

            for (int i = 0; i < nums.size() - 1; i++)
                for (int j = i + 1; j < nums.size(); j++)
                    if (nums[i] + nums[j] == target)
                        return vector<int>{i, j};

            return vector<int>{};
        }

        /*
         * Two-pass Hash Table solution
         *
         * Time complexity: O(n)
         * Space complexity: O(n)
         */
        vector<int> twoSum_ans2(vector<int>& nums, int target) {
            unordered_map<int, int> mapping;

            for (int i = 0; i < nums.size(); i++) {
                mapping.insert({nums[i], i});
                //mapping[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); i++) {
                auto j = mapping.find(target - nums[i]);
                if (j != mapping.end() && j->second != i)
                    return vector<int>{i, j->second};
            }

            return vector<int>{};
        }

        /*
         * One-pass Hash Table solution
         *
         * Time complexity: O(n)
         * Space complexity: O(n)
         */
        vector<int> twoSum_ans3(vector<int>& nums, int target) {
            unordered_map<int, int> mapping;
            for (int i = 0; i < nums.size(); i++) {
                //mapping[nums[i]] = i;
                mapping.insert({nums[i], i});
                auto j = mapping.find(target - nums[i]);
                if (j != mapping.end() && j->second != i)
                    return vector<int>{i, j->second};
            }

            return vector<int>{};
        }

        void swap(vector<int>& nums, int i, int j, int *index){
            // Swap indices at the same time, to keep track of the origin indices.
            int temp = nums[i];
            nums[i]  = nums[j];
            nums[j]  = temp;

            temp     = index[i];
            index[i] = index[j];
            index[j] = temp;
        }

        int partition(vector<int>& nums, int start, int end, int * index) {
            // choose a random position
            int p = start + rand() % (end - start);
            swap(nums, p, end, index);

            // Now nums[end] is some random value in nums[start, end]
            int r = nums[end];
            int i = start - 1, j = start;
            for (; j < end; j++) {
                if (nums[j] < r) {
                    i++;
                    swap(nums, i, j, index);
                }
            }
            swap(nums, i + 1, end, index);

            return i + 1;
        }

        void quickSort(vector<int>& nums, int start, int end, int* index) {
            if (start < end) {
                int q = partition(nums, start, end, index);
                quickSort(nums, start, q - 1, index);
                quickSort(nums, q + 1, end, index);
            }
        }

        /*
         * Sort and two pointer Solution
         * 1. Sort the vector(nums), and index[k] represents the original position of the kth number in sorted vector
         * 2. Use two pointer(=index number), one for the smaller number(start), the other for the larger(end), and compare numbers[start] + numbers[end] with target:
         *      1. If nums[start] + nums[end] = target, index[start] and index[end] are the answer.
         *      2. Else If nums[start] + nums[end] < target, move start to larger one (start++) so that nums[start] + nums[end] becomes larger.
         *      3. Else If nums[start] + nums[end] > target, move end to smaller one (end--) so that nums[start] + nums[end] becomes smaller.
         */
        vector<int> twoSum_ans4(vector<int>& nums, int target) {
            int size = nums.size();
            int *index = new int[size + 1];

            //Initialize the origin index to be [0, size]
            for (int i = 0; i < size; i++)
                index[i] = i;

            //Sort the vector: nums, and maintain their original indices.
            quickSort(nums, 0, size - 1, index);

            //Two pointers, start and end, look for two numbers add up to the target
            int start = 0, end = size - 1;
            while (start < end) {
                if (nums[start] + nums[end] == target) break;
                else if (nums[start] + nums[end] < target) start++;
                else end--;
            }

            return vector<int>{index[start], index[end]};
        }
};
