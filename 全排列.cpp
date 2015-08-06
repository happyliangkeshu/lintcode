// 一．全排列的递归实现
// 为方便起见，用123来示例下。
// 123的全排列有123、132、213、231、312、321这六种。
// 首先考虑213和321这二个数是如何得出的。
// 显然这二个都是123中的1与后面两数交换得到的。
// 然后可以将123的第二个数和每三个数交换得到132。
// 同理可以根据213和321来得231和312。
// 因此可以知道——全排列就是从第一个数字起
// 每个数分别与它后面的数字交换。
// 找到这个规律后，递归的代码就很容易写出来了：


class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.*/
    void perm(vector<vector<int> > &res, vector<int> & nums, int k){
        if(k == nums.size()){
            res.push_back(nums);
            return;
        }
        //全排列就是从第一个数字起每个数分别与它后面的数字交换。
        for(int i = k; i < nums.size(); ++i){
            swap(nums[i], nums[k]);
            perm(res, nums, k + 1);
            swap(nums[i], nums[k]);
        }
        
    }
     
    vector<vector<int> > permute(vector<int> nums) {
    
        vector<vector<int> > res;
        if(nums.empty() ){
            return res;
        }
        perm(res, nums, 0);
        return res;
    }
};






class Solution {
public:
    void dfs(vector<vector<int> > &res, vector<int> & path, vector<int> & nums){
        if(path.size() == nums.size()){
            res.push_back(path);
			return;
        }
        for(int i = 0; i < nums.size(); ++i){
			//使用回溯法解题的关键在于如何确定正确解及排除不符条件的解(剪枝)。
            auto pos = find(path.begin(), path.end(), nums[i] );
            if(pos == path.end() ){
                path.push_back(nums[i]);
                dfs(res, path, nums);
                path.pop_back();
            }

        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int> > res;
        if(nums.empty() ){
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        
        dfs(res, path, nums);
        return res;
    }
};