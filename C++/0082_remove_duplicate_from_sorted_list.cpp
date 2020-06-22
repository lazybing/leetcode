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
            
            ListNode dummy(0);
            dummy.next = head;
            ListNode *p  = &dummy;
            ListNode *p1 = head;
            ListNode *p2 = head;

            while (p1) {
                while (p2->next && p1->val == p2->next->val)
                    p2 = p2->next;

                if (p1 == p2)
                    p = p1;
                else
                    p->next = p2->next;

                p1 = p2 = p->next;
            }

            return dummy.next;
        }
}
