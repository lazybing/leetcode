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

/**
 * Algorithm
 *  Compare every k nodes (head of every linked list) and get the node with the smallest value.
 *  Extend the final sorted linked list with the selected nodes.
 * Complexity Analysis:
 *  Time complexity: O(kN) where k is the number of linked lists.
 *      Almost every selection of node in final linked costs O(k)(k - 1 times comparison).
 *      There are N nodes in the final linked list.
 *  Space complexity:
 *      O(n) Creating a new linked list costs O(n) space.
 *      O(1) It's not hard to apply in-place method-connect selected nodes instead of creating new nodes to fill the new linked list.
 */


/**
 * Merge lists one by one
 * Algorithm
 * Convert merge k lists problem to merge 2 lists(k - 1) times.
 * Complexity Analysis
 *  Time complexity:O(kN) where k is the number of linked lists.
 *      We can merge two sorted linked list in O(n) time where n is the total number of nodes in two lists.
 *      Sum up the merge process and we can get O(kN).
 *  Space complexity:O(1)
 *      We can merge two sorted linked list in O(1) space.
 */
class Solution {
    private:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if (l1 == nullptr) return l2;
            if (l2 == nullptr) return l1;

            if (l1->val <= l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    public:
        ListNode *mergeKLists(vector<ListNode*>&lists) {
            if (lists.empty()) return nullptr;

            while (lists.size() > 1) {
                lists.push_back(mergeTwoLists(lists[0], lists[1]));
                lists.erase(lists.begin());
                lists.erase(lists.begin());
            }

            return lists.front();
        }
};
