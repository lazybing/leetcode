// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * You are given two non-empty linked lists representing two non-negative integers. The
 * digits are stored in reverse order and each of their nodes contain a single digits. Add the 
 * two number and return it as a linked list.
 *
 * You may assume two numbers do not contain any leading zero, except th enumber 0 itself.
 *
 * Eaxmple:
 * Input: (2->4->3) + (5->6->4)
 * Output: 7->0->8
 * Explanation: 342 + 465 = 807
 */

/**
 * Definitioin for singly-linked list.
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x): val(x), next(NULL){}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode* l2) {
            ListNode preHead(0), *p = &preHead;
            char carray  =0;

            while (l1 != NULL || l2 != NULL || carray) {
                int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carray;
                carray = sum >= 10;
                p->next = new ListNode(sum % 10);
                p = p->next;
                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;
            }
            return preHead.next;
        }
};
