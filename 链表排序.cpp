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
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        auto cur = &dummy;
        auto p1 = l1, p2 = l2;
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
        if(p1)
            cur->next = p1;
        if(p2)
            cur->next = p2;
        
        return dummy.next;
    }       
    ListNode * sortListhelper(ListNode * head, const int length){
        if(head == NULL || length <= 0){
            return head;
        }
        auto mid = head;
        int cnt = 1;
        while(cnt < (length >> 1)){
            ++cnt; 
            mid = mid->next;
        }
        auto rList = sortListhelper(mid->next, length - (length >> 1));
        mid->next = NULL;
        auto lList = sortListhelper(head, length >> 1);
        
        return mergeTwoLists(lList, rList);
    }
    ListNode *sortList(ListNode *head) {
        if(head == NULL){
            return head;
        }
        
        int len = 0;
        auto p = head;
        while(p){
            ++len;
            p = p->next;
        }
        return sortListhelper(head, len);
        
    }
};



