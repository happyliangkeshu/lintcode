class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
     bool isvalid(string &s){
         
         for(int i = 0, j = s.size() - 1; i < j; ++i, --j){
             if(s[i] != s[j]){
                 return false;
             }
         }
         return true;
     }
     void partition(vector<vector<string>> &res, vector<string>& path, string & s, int pos ){
         if(s.size() == pos ){
             res.push_back(path);
             return;
         }
        
        for(int i = pos; i < s.size(); ++i){
			// pos 到 i 之间的串
            auto str = s.substr(pos, i - pos + 1);
            if(isvalid(str)){
                path.push_back(str);
                partition(res, path, s, i + 1);
                path.pop_back();
            }
        }
         
     }
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> path;
        partition(res, path, s, 0);
        
        return res;
    }
};
