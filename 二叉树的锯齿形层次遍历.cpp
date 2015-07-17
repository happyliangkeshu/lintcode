

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> > vec;
	if(root == NULL) return vec;
	vector<int> level;
	deque<TreeNode *> d;
	// 选用deque就是因为它既可以从前边取数
	// 又可以 从后边取数
	d.push_back(root);
	int num = 1;
	while(!d.empty()){
		int size = d.size();
		for(int i = 0; i < size; ++i){
			TreeNode * p;
			if(num % 2 == 1){
				  p = d.front(); // 如果是从前边开始取数的话
				  level.push_back(p->val);
				  d.pop_front();
				  if(p->left) // 就把左右孩子推入后边
					  d.push_back(p->left);
				  if(p->right)
					  d.push_back(p->right);
			}
			else{
				p = d.back();// 如果从后边取数的话
				level.push_back(p->val);
				d.pop_back();
				if(p->right)// 就把左右孩子推入前边，不过顺序要反过来啊
				d.push_front(p->right);
				 if(p->left)
				d.push_front(p->left);
			}
		}
		vec.push_back(level);
		level.clear();
		++num;
		
	}
	return vec;
}