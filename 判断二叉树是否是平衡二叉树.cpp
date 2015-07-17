平衡二叉树

    int depth(TreeNode * root){
        int leftdepth = 0;
        int rightdepth = 0;
        if(root){
         leftdepth = depth(root->left) + 1;
        rightdepth = depth(root->right) + 1;
        }
        return max(leftdepth, rightdepth);
    }
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(root == NULL) return true;
        
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);
        int abs_dep = abs(ldepth - rdepth);
        return (abs_dep <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }