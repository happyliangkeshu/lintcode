// 三数之和 II

int threeSumClosest(vector<int> nums, int target) {
	
	int result = 0;
	int min_gap = INT_MAX;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size() - 2; ++i){
		int j = i + 1;
		int k = nums.size() - 1;
		while(j < k){
			int sum = nums[i] + nums[j] + nums[k];
			int gap = abs(sum - target);
			
			if(gap < min_gap){
				result = sum;
				min_gap = gap;
			}
			
			if (sum < target)
				++j;
				else
				--k;
		}
	}
	return result ;
}