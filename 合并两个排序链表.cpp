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
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL ){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        auto p1 = l1, p2 = l2;
        ListNode dummy(INT_MIN);
        auto cur = &dummy;
        
        while(p1 && p2){
            
            if(p1->val < p2->val){
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
        }
        if(p2 == NULL){
            cur->next = p1;
        }
        else {
            cur->next = p2;
        }
        
        return dummy.next;
        
    }
};
