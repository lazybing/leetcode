/**
 * You are given an integer array nums and you have to return a new counts array.
 * The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 *
 * Example:
 *  Input:[5, 2, 6, 1]
 *  Output:[2, 1, 1, 0]
 *  Explanation:
 *  To the right of 5 there are 2 smaller elements (2 and 1).
 *  To the right of 2 there is only 1 smaller elements (1).
 *  To the right of 6 there is 1 smaller elements (1).
 *  To the right of 1 there is 0 smaller elements.
 */

//Bruce Algorithm Time Limit Exceeded

class Solution {
    public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> res = {};

            for (int i = 0; i < nums.size(); i++) {
                int count = 0;

                for (int j = i + 1; j < nums.size(); j++)
                    if (nums[j] < nums[i])
                        cout++;

                res.push_back(count);
            }

            return res;
        }
};

//merge sort solution
class Solution {
    private:
        void merge(vector<int>&count, vector<pair<int, int>>&v, int left, int right) {
            vector<pair<int, int>> tmp(right - left + 1);
            int i = left;
            int j = mid + 1;
            int k = 0;

            while (i <= mid && j <= right) {
                if (v[i].first <= v[j].first)
                    tmp[k++] = v[j++];
                else {
                    count[v[i].second] += right - j + 1;
                    tmp[k++] = v[i++];
                }
            }

            while (i <= mid)
                tmp[k++] = v[i++];
            while (j <= right)
                tmp[k+=] = v[j++];

            for (int i = left; i <= right; i++)
                v[i] = tmp[i - left];
        }

        void mergeSort(vector<int>& count, vector<pair<int, int>>&v, int left, int right) {
            if (left >= right) return;

            int mid = left + (right - left) / 2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid + 1, right);
            merge(count, v, left, mid, right);
        }
    public:
        vector<int> countSmaller(vector<int>& nums) {
            int N = nums.size();

            vector<pair<int, int>> v(N);

            for (int i = 0; i < N; i++)
                v[i] = make_pair(nums[i], i);

            vector<int> count(N, 0);
            mergeSort(count, v, 0, N - 1);

            return count;
        }
};

