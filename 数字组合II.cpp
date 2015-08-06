class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
	 
	 void combinationSum(vector<vector<int> > &res, const vector<int> & nums,
vector<int> & path, int target, int pos){
       if(target == 0){
           res.push_back(path);
           return;
       }
       
       for(int i = pos; i < nums.size(); ++i){
         
        if(i != pos && nums[i] == nums[i -1]){
            continue;
        }
          if(nums[i] <= target ){
            path.push_back(nums[i]);
           combinationSum(res, nums, path, target - nums[i], i + 1);
           path.pop_back();
          }

       }
      
     }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
          vector<vector<int> > res;
        if(num.empty() ){
            return res;
        } 
        
        sort(num.begin(), num.end() );
        vector<int > path;
        combinationSum(res, num, path, target, 0);
        return res;
    }
};
