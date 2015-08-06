class Solution {
public:

    void dfs(vector<vector<int> > &res, vector<int>& path, vector<int>& nums, int pos){
        
        res.push_back(path);
        
        for(int i = pos; i < nums.size(); ++i){
            path.push_back(nums[i]);
            dfs(res, path, nums, i + 1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        vector<vector<int> > res;
        if(nums.empty() ){
            return res;
        }
        sort(nums.begin(), nums.end() );
        vector<int> path;
      
        dfs(res, path, nums, 0);
        return res;
    }
};