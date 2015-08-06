#include <iostream>
#include <vector>
using namespace std;
inline int max(int a, int b)
{
	return a > b ? a :b;
}
inline int min(int a, int b)
{
	return a < b ? a :b;
}
int maxSubArray(vector<int> nums);
int minSubArray(vector<int> nums);
int main()
{
	int arr[] = {-2,2,-3,4,-1,2,1,-5,3};
//	int arr[] = {5};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	
	cout << maxSubArray(nums) << endl;
	cout << minSubArray(nums) << endl;
	
	
	return 0;
}


int maxSubArray(vector<int> nums)
{
	int len = nums.size();

	int maxnum = INT_MIN;
	int start = nums[0];
	for(int i = 0; i < len; ++i)
	{
		start = i == 0 ? nums[0] : max(nums[i], start + nums[i]);
		if(maxnum < start)
			maxnum = start;
	}
	
	return maxnum;

}

int minSubArray(vector<int> nums)
{
	int len = nums.size();
	int minnum = INT_MAX;
	int start = nums[0];
	for(int i = 0; i < len; ++i)
	{
		start = i == 0 ? nums[0] : min(nums[i], start + nums[i]);
		if(minnum > start)
			minnum = start;
	}
	
	return minnum;
    
}
