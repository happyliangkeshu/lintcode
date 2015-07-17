vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int> > vec;
		vector<int> level;
		if(root == NULL ) return vec;
		queue<TreeNode *> q;
		q.push(root);
		
		while(!q.empty() ){
			int size = q.size();
			for(int i = 0; i < size; ++i){
				
				auto p = q.front();
				level.push_back(p->val);
				q.pop();
				
				if(p->left)
				   q.push(p->left);
				if(p->right)
				   q.push(p->right);
			}
			vec.push_back(level);
			level.clear();
		}
		return vec;
	}