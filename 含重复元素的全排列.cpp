// 二．去掉重复的全排列的递归实现
// 由于全排列就是从第一个数字起每个数分别与它后面的数字交换。
// 我们先尝试加个这样的判断——如果一个数与后面的数字相同那么这二个数就不交换了。
// 如122，第一个数与后面交换得212、221。
// 然后122中第二数就不用与第三个数交换了，但对212，它第二个数与第三个数是不相同的，
// 交换之后得到221。与由122中第一个数与第三个数交换所得的221重复了。所以这个方法不行。

//	http://blog.csdn.net/morewindows/article/details/7370155/

// 换种思维，对122，第一个数1与第二个数2交换得到212，然后考虑第一个数1与第三个数2交换，
// 此时由于第三个数等于第二个数，所以第一个数不再与第三个数交换。
// 再考虑212，它的第二个数与第三个数交换可以得到解决221。此时全排列生成完毕。

// 这样我们也得到了在全排列中去掉重复的规则——
// 去重的全排列就是
// 从第一个数字起每个数分别与它后面非重复出现的数字交换。
// 用编程的话描述就是第i个数与第j个数交换时，要求[i,j)中没有与第j个数相等的数。
// 下面给出完整代码：
	
	void perm(vector<vector<int> > &res, vector<int> & nums, int k){
        if(k == nums.size() ){
            res.push_back(nums);
            return;
        }
        
        for(int i = k; i < nums.size(); ++i){
			//  从第一个数字起每个数分别与它后面非重复出现的数字交换。
			// 找下标k  到 下标i 之间 有没有重复元素
			// 如果有重复的元素就不交换。
            auto begin = nums.begin() + k;
            auto end = nums.begin() + i;
            auto pos = find(begin, end, nums[i]);
            if(pos == end ){
				swap(nums[i], nums[k]);
				perm(res, nums, k + 1);
				swap(nums[i], nums[k]);
            }
        }
    }
  
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > res;
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end() );
        
        perm(res, nums, 0);
        return res;
    }




class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    void perm(vector<vector<int> > &res, vector<int> & nums, int k){
        if(k == nums.size() ){
            res.push_back(nums);
            return;
        }
        
        for(int i = k; i < nums.size(); ++i){
            sort(nums.begin() + k, nums.end());
            if(i == k || nums[i] != nums[i - 1]){
            swap(nums[i], nums[k]);
            perm(res, nums, k + 1);
            swap(nums[i], nums[k]);
            }
        }
    }
  
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > res;
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end() );
        
        perm(res, nums, 0);
        return res;
    }
};
