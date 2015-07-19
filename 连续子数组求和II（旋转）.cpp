    
//看的这篇博客中的解释 http://www.ahathinking.com/archives/120.html
	
	// 计算最大子数组及其位置
    vector<int> continuousSubarraySum(vector<int>& A, int & ans1) {
        vector<int>& nums = A;
        int &ans = ans1;
        ans = nums[0];
        int cur = nums[0], n = nums.size();
        int start = 0, end = 0, temp = 0;
    	for(int i = 1; i < n; ++i){
    	    if(cur < 0){
    	        cur = 0;
    	        temp = i;
    	    }
    	    cur += nums[i];
		
    		if(ans < cur){
    		    ans = cur;
        //开始位置，只有等结束位置更新，开始位置才更新
    		    start = temp; 
    		    end = i;
    		}
    	}
    	return {start, end};
    }
    // 计算最小连续自数组及其位置，
    vector<int> continuousSubarraySum1(vector<int>& A, int & ans1) {
        vector<int>& nums = A;
        int &ans = ans1;
        ans = nums[0];
        int cur = nums[0], n = nums.size();
        int start = 0, end = 0, temp = 0;
    	for(int i = 1; i < n; ++i){
    	    if(cur > 0){
    	        cur = 0;
    	        temp = i;
    	    }
    	    cur += nums[i];
		
    		if(ans > cur){
    		    ans = cur;
        //开始位置，只有等结束位置更新，开始位置才更新
    		    start = temp; 
    		    end = i;
    		}
    	}
    	return {start, end};
    }
    
    vector<int> continuousSubarraySumII(vector<int>& A) {
        int ans1;
        vector<int>  vec1 = continuousSubarraySum(A, ans1);
        // 如果ans1 < 0 的话，说明全是复数，
		// 直接返回vec1就可以了，不需要再继续了。
        if(ans1 < 0) return vec1;
		
        int n = A.size();
        if(n <= 2) return vec1;
        
        int ans2;
		// 计算最小连续子数组
        vector<int>  vec2 = continuousSubarraySum1(A, ans2);
        int sum = accumulate(A.begin(), A.end(), 0);
		// 总和减去连续最小子数组，就是连续旋转子数组的最大和
        ans2 = sum - ans2;
        // 这里的>= 不能少了等于号，等于的情况下，也要返回不旋转的才对
        if(ans1 >= ans2) return vec1;
        --vec2[0];
        ++vec2[1];
        swap(vec2[0], vec2[1]);
        return vec2;
    }