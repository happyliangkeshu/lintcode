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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // if(lists.empty()){
        //     return NULL;
        // }
        ListNode dummy(INT_MIN);
        auto cur = &dummy;
        int k = lists.size();
        // int flag = 1;
        // int minval = , mink = -1;
        while(true){
            // flag = 0;
           int minval = INT_MAX, mink = -1;
            for(int i = 0; i < k; ++i){
                if(lists[i]){
                    if(minval > lists[i]->val){
                        minval = lists[i]->val;
                        mink = i;
                    }
                    // flag = 1;
                }
            }
            if(mink >= 0){
                cur->next = lists[mink];
                cur = cur->next;
                lists[mink] = lists[mink]->next;
            }
            else{
                break;
            }

        } 
        return dummy.next;
    }
};



