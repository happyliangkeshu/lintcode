    
	
	
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
       
        if(root == NULL || root == A || root == B){
			return root;
		} 
        
        auto left = lowestCommonAncestor(root->left, A, B);
        auto right = lowestCommonAncestor(root->right, A, B);
        
        if(left == NULL) {
            return right;
        }
        if(right == NULL){
            return left;
        }
        return root;
        
    }