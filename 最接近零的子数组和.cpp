// 最接近零的子数组和 查看运行结果 
// 给定一个整数数组，找到一个和最接近于零的子数组。
// 返回第一个和最有一个指数。你的代码应该返回满足要求的子数组的起始位置和结束位置 
//给出[-3, 1, 1, -3, 5]，返回[0, 2]，[1, 3]， [1, 1]， [2, 2] 或者 [0, 4] 
 
     vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        map<int, int> mapi;
        int n = nums.size();
        int cur(0);
        for(int i = 0; i < n; ++i){
            cur += nums[i];
            // 如果 有子数组和为0的话，就可以直接退出了
            if(mapi.find(cur) != mapi.end()){
                return {i, mapi[cur]};
            }
            else{
                mapi[cur] = i;
            }
        }
        int minadj = INT_MAX;
        int start = 0, end = 0;
        // map就是排好序的，直接查找map的相邻元素差 就可以了
        for(auto pos = next(mapi.begin()); pos != mapi.end(); ++pos){
            auto pos1 = prev(pos);
            if(minadj > pos->first - pos1->first){
                minadj = pos->first - pos1->first;
                // 注意下标的计算
                start = min(pos->second, pos1->second) + 1;
                end = max(pos->second, pos1->second);
            }
        }
        
        return {start, end};
        
    }