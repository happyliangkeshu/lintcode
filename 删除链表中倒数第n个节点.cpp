/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
 // 给出链表1->2->3->4->5->null和 n = 2.

// 删除倒数第二个节点之后，这个链表将变成1->2->3->5->null.
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL || n <= 0){
            return head;
        }
        
        auto fast = head, slow = fast;
        
        while(fast && n ){
            fast = fast->next;
            --n;
        }
        if(fast == NULL){
            return head->next;
        }
        auto slow_prev = slow;
        while(fast){
            slow_prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        slow_prev->next = slow_prev->next->next;
        return head;
    }
};



