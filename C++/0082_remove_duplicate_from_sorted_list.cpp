/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct number from the original list.
 *
 * Return the linked list sorted as well.
 *
 * Example 1:
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 *
 * Example 2:
 * Input: 1->1->1->2->3
 * Output: 2->3
 */
class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (head == nullptr || head->next == nullptr) 
                return head;
            
            //TODO
        }
}
