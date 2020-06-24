/**
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 * Example:
 * Input:
 * [
 *  1->4->5,
 *  1->3->4,
 *  2->6
 * ]
 * Output:1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x): val(x), next(NULL){}
 * };
 */
/**
 * Approach 1: Brute Force
 * Intuition & Algorithm
 *  Traverse all the linked lists and collect the values of the nodes into an array.
 *  Sort and iterate over this array to get the proper value of nodes.
 *  Create a new sorted linked list and extend it with the new nodes.
 *
 * Complexity Analysis
 *  Time complexity: O(NlogN) where N is the total number of nodes.
 *      Collecting all the values costs O(N) time.
 *      A stabel sorting algorithm costs O(NlogN) time.
 *      Iterating for creating the linked list costs O(N) time.
 *  Space complexity:O(N)
 *      Sorting cost O(N) space (depends on the algorithm you choose).
 *      Creating a new linked list costs O(N) space.
 */
class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode*>& lists) {
            vector<int> array = {};
            for (int i = 0; i < lists.size(); i++) {
                ListNode *tmp = lists[i];
                while (tmp != nullptr) {
                    arry.push_back(tmp->val);
                    tmp = tmp->next;
                }
            }

            sort(arry.begin(), arry.end());

            ListNode *res  = new ListNode();
            ListNode *node = res;

            for (int i = 0; i < arry.size(); i++) {
                ListNode *tmp = new ListNode(arry[i]);

                node->next = tmp;
                node = node->next;
            }

            return res->next;
        }
};
