    void reverse(int R[], int start, int end)
{
	int low = start;
	int high = end;
	int len = end - start + 1;

	int count = len / 2;
	while (count--){
		swap(R[low], R[high]);
		++low;
		--high;
	}
}

    void nextPermutation(vector<int> &nums) {
	int n = nums.size();
	if (n <= 1) return;
	int i = n - 2;
	int fi = INT_MAX;
	// 从尾部开始查找元素
	// 找到nums[i] < nums[i + 1] ，第一个升序
	for (; i >= 0; --i){
		if (nums[i] < nums[i + 1]){
			fi = i;
			break;
		}
	}
	if (fi == INT_MAX) // 如果全都是降序的话，就没有更大的排列了
	{
		reverse(&nums[0], 0, n - 1);
		return;
	}
	//cout << nums[i] << endl;
	// 在 i + 1到 n - 1之间找大于nums[i]的最小元素
	int k = i + 1;
	for (; k <= n - 1; ++k){
		if (nums[k] <= nums[i])// 加等于号，表示有重复元素时的处理
		{
			break;
		}
	}
	int kk = k - 1; 
	swap(nums[i], nums[kk]);// 交换
	reverse(&nums[0], i + 1, n - 1); //翻转
    }