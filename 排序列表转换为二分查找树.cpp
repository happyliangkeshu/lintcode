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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:

     TreeNode * helper(ListNode * head, int len){
          if(head == NULL || len <= 0){
              return NULL;
          }
          int cnt = 1;
          
          auto mid = head;
          int m = 0, leftlen = 0, rightlen = 0;
          if(len % 2 == 1){
              m = len / 2 + 1;
              leftlen = (len - 1 )/2;
              rightlen = leftlen;
          }
          else{
              m = len / 2;
              leftlen  = (len/2 - 1);
              rightlen = (len)/2;
          }
          while(cnt < m){
              mid = mid->next;
              ++cnt;
          }
          auto root = new TreeNode(mid->val);
          
          root->right = helper(mid->next, rightlen);
          mid->next = NULL;
          root->left = helper(head, leftlen );
          
          return root;
     }
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(head == NULL){
            return NULL;
        }
        int len = 0;
        auto p = head;
        while(p){
            ++len;
            p = p->next;
        }
        return helper(head, len);
    }
};



