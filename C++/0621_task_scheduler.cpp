/*
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z
 * where different letters represent different tasks. Tasks could be done without original
 * order. Each task could be done in one interval. For each interval, CPU could finish one
 * task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same
 * tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will task to finish all the given tasks.
 *
 * Example:
 * Input: tasks = ["A", "A", "A", "B", "B", "B", "B"], n = 2
 * Output:8
 * Explanation: A->B->idle->A->B->idle->A->B
 *
 * Constraints:
 *  The number of tasks is in the range [1, 10000].
 *  The integer n is in the range [0, 100]
 */
class Solution {
    public:
        int leastInterval(vector<char>&tasks, int n) {
            int counts[26] = {0};
            int max = 0;
            int numMax = 0;

            for (int i = 0; i < tasks.size(); i++) {
                counts[tasks[i] - 'A']++;
                if (counts[tasks[i] - 'A'] > max) {
                    max = counts[tasks[i] - 'A'];
                    numMax = 1;
                } else if (counts[tasks[i] - 'A'] == max) {
                    numMax++;
                }
            }

            //check to see if there's enought task to fill up the idles
            if (tasks.size() - max > n * (max - 1)) {
                return tasks.size();
            }

            return max + n * (max - 1) + numMax - 1;
        }
};
