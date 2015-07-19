     
	// 接利用动归来求解，考虑到可能存在负数的情况，我们用Max[i]来表示以a[i]结尾的最大连续子序列的乘积值，用Min[i]表示以a[i]结尾的最小的连续子序列的乘积值，那么状态转移方程为：
       // Max[i]=max{a[i], Max[i-1]*a[i], Min[i-1]*a[i]};
       // Min[i]=min{a[i], Max[i-1]*a[i], Min[i-1]*a[i]};
// 初始状态为Max[1]=Min[1]=a[1]。代码如下： 
	 template <class T>
     T max( T a, T b,  T c){
         a = a > b ? a : b;
         return a > c ? a : c;
     }
     template <class T>
     T min( T a, T b,  T c){
         a = a < b ? a : b;
         return a < c ? a : c;
     }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxi = nums[0], mini = nums[0];
        for(int i = 1; i < n; ++i){
            int temp = maxi;
            maxi = max(nums[i], maxi* nums[i], mini * nums[i]);
			// maxi 的结果要用之前的，不可以用之后的
            mini = min(nums[i], temp* nums[i], mini * nums[i]);
            ans = max(ans, maxi,mini);
        } 
        return ans;
    }