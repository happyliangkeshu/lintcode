数字组合
// 2 3 5 
// 2 3 5 
// 2 3 5
// target = 7 
// 去重
class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
void combinationSum(vector<vector<int> > &res, const vector<int> & nums,
vector<int> & path, int target, int pos){
       if(target == 0){
           res.push_back(path);
           return;
       }
       
       for(int i = pos; i < nums.size(); ++i){
          if(nums[i] <= target ){
            path.push_back(nums[i]);
           combinationSum(res, nums, path, target - nums[i], i);
           path.pop_back();
          }

       }
           
         
         
     }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        vector<vector<int> > res;
        if(candidates.empty() ){
            return res;
        } 
        
        sort(candidates.begin(), candidates.end() );
        vector<int > path;
        combinationSum(res, candidates, path, target, 0);
        return res;
            
    }
};
