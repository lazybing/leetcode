/*
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *  Each child must have at least one candy.
 *  Children with a higher rating get more candies than their neighbors.
 *
 * What is the minimum candies you must give?
 *
 * Example 1:
 *  Input: [1, 0, 2]
 *  Output: 5
 *  Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 *
 * Example 2:
 *  Input: [1, 2, 2,]
 *  Output: 4
 *  Explanation: you can allocate to the first, second and third child with 1, 2, 1 candies respectively.
 *              The third child gets 1 candy because it satisfies the avove two conditions.
 */
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int count = 0;
            vector<int> left, right;

            for (int i = 0; i < ratings.size(); i++) {
                left.push_back(1);
                right.push_back(1);
            }

            for (int i = 1; i < ratings.size(); i++)
                if (ratings[i] > ratings[i - 1])
                    left[i] = left[i - 1] + 1;

            for (int j = ratings.size() - 1; j > 0; j--)
                if (ratings[j - 1] > ratings[j])
                    right[j - 1] = right[j] + 1;

            for (int i = 0; i < ratings.size(); i++)
                cout += max(right[i], left[i]);

            return count;
        }
};
