

// 从底向上遍历二叉树
vector<vector<int>> levelOrderBottom(TreeNode *root) {
		vector<vector<int> > vec;
		vector<int> level;
		if(root == NULL ) return vec;
		queue<TreeNode * >q; 
		stack<int> s; 
		stack<int> slen;
		q.push(root);
		// 先从上向下层次遍历二叉树
		// 将每层的数字 和 每层的长度 分别存入一个栈中。
		while(!q.empty() ){
			int size = q.size();
			slen.push(size);
			for(int i = 0; i < size; ++i){
				auto p = q.front();
				s.push(p->val);
				q.pop();
				
				if(p->right)
				   q.push(p->right);
				if(p->left)
				   q.push(p->left);
			}
		}
		// 将数字栈中的数据 按照长度栈中的长度 分别取出。
		while(!s.empty()){
			int len = slen.top();
			slen.pop();
			for(int i = 0; i < len; ++i){
				auto a = s.top();
				level.push_back(a);
				s.pop();
			}
			vec.push_back(level);
			level.clear();
		}
		
		
		return vec;
		
}