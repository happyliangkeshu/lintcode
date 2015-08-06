把排序数组转换为高度最小的二叉搜索树
/**
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
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
     typedef TreeNode * TreeLink;
     void sortedArrayToBST(vector<int> &A, int first, int last, TreeLink & root){
         if(first > last){ // 注意循环结束条件
             return;
         }
         auto mid = first + ( (last - first) >> 1);
         root = new TreeNode(A[mid]);
         sortedArrayToBST(A, first, mid - 1, root->left);
         sortedArrayToBST(A, mid + 1, last, root->right);
         
     }
    TreeNode *sortedArrayToBST(vector<int> &A) {
        if(A.empty()){
            return NULL;
        }
        TreeNode * root;
        sortedArrayToBST(A,0, A.size() - 1, root);
        return root;
    }
        
};



