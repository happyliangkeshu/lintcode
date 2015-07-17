TreeNode* insertNode(TreeNode* root, TreeNode* node) {
	
	if(root == NULL ) {
		root = node;
		return root;
	}
	
	auto p = root;
	auto q = p;
	while(p){
		q = p;
		if(p->val > node->val){
			p = p->left;
		}
		else if(p->val < node->val){
			p = p->right;
		}
		else{
			return root;
		}
	}
	
	if(q->val < node->val)
		q->right = node;
	if(q->val > node->val)
		q->left = node;
		
	return root;
}