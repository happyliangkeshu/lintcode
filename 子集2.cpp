// 以 [1, 2 , 2 ] 为例， 若不考虑重复， 
// 组合有 [], [1], [1, 2 ], [1, 2 , 2 ], [1, 2 ], [2 ], [2 , 2 ], [2 ]. 
// 其中重复的有 [1, 2 ], [2 ]. 
// 从中我们可以看出只能从重复元素的第一个持续往下添加到列表中， 而不能取第二个
// 或之后的重复元素。
 // 参考上一题Subsets的模板， 
// 能代表「 重复元素的第一个」 即为 for 循环中的 pos 变量，
 // i == pos 时， i 处所代表的变量即为某一层遍历中得「 第一个元素」 ，
// 因此去重时只需判断 i !=pos && s[i] == s[i - 1] .


class Solution {
public:
void subset(const vector<int> & nums, vector<int> & path, int pos, vector<vector<int> > &result){
    
         result.push_back(path);
         
		 for( int i = pos; i < nums.size(); ++i){
		
			 if(i != pos && nums[i] == nums[i - 1]) continue;
			 
		 	path.push_back(nums[i]);
			subset(nums, path, i + 1, result);
			path.pop_back();
			
		 }
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        subset(nums, path, 0, result);
        return result;
    }
};