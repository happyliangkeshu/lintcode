class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  }
 
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        if(root == NULL){
            return {};
        }
       string s;
       queue<TreeNode *> q;
       q.push(root);
       while(!q.empty()){
           auto p = q.front();
           q.pop();
           if(p == NULL){
               s.push_back('#');
               s.push_back(',');
               continue;
           }
		   // 特别是两位数以上转字符串，一定不能使用+'0'
		   // 以后转字符串就用to_string.
           s += to_string(p->val);
           s.push_back(',');
           q.push(p->left);
           q.push(p->right);
       }
       return s;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        if(data.empty() ) {
            return NULL;
        }
        
       queue<TreeNode *> q;
       auto p = &data[0];
       char * p1;
       int num = strtol(p, &p1, 10);
       p = p1 + 1;
       if(num == '#') return NULL;
       
       TreeNode * root = new TreeNode(num);
       q.push(root);
       while(*p ){

           auto q1 = q.front();
           q.pop();
           if(*p == '#'){
               num = '#';
               p += 2;
           }
           else{
               num = strtol(p, &p1, 10);
               p = p1 + 1;
           }
           
           q1->left = num == '#'? NULL : new TreeNode(num);
           if(q1->left) q.push(q1->left);
            if(*p == '#'){
               num = '#';
               p += 2;
           }
           else{
               num = strtol(p, &p1, 10);
               p = p1 + 1;
           }            
           q1->right = num == '#'? NULL : new TreeNode(num);
           if(q1->right) q.push(q1->right);
           
       }
       
       return root;
    }
};

