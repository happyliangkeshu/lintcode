// 二叉树中的最大路径和

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
    struct ResultType {
        // singlePath: 从root往下走到任意点的最大路径，这条路径可以不包含任何点
        // maxPath: 从树中任意到任意点的最大路径，这条路径至少包含一个点
        int singlePath, maxPath; 
        ResultType(int singlePath, int maxPath) {
            this->singlePath = singlePath;
            this->maxPath = maxPath;
        }
    };
public:
   ResultType helper( TreeNode * root) {
        if (root == NULL) {
            return  ResultType(0, INT_MIN);
        }
        // Divide
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);

        // Conquer
        int singlePath = max(left.singlePath, right.singlePath) + root->val;
        singlePath = max(singlePath, 0);

        int maxPath = max(left.maxPath, right.maxPath);
        maxPath = max(maxPath, left.singlePath + right.singlePath + root->val);

        return ResultType(singlePath, maxPath);
    }
    int maxPathSum(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        ResultType result = helper(root);
        return result.maxPath;
       
    }
};
