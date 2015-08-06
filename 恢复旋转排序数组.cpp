#include <iostream>
#include <vector>
using namespace std;
void reverse(int arr[], int begin, int end);
void recoverRotatedSortedArray(vector<int> &nums);
int main()
{
//	int arr[] = {4, 5, 1, 2, 3};
	int arr[] = {5,6, 1, 2, 3,4};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));

	recoverRotatedSortedArray(nums);
	
	for(auto pos = nums.begin(); pos != nums.end(); ++pos )
		cout << *pos << " " ;
	cout << endl; 
	
	return 0;
} 

void reverse(int arr[], int begin, int end)
{
	int len = end - begin + 1;
	int num = len >> 1;
	int temp;
	while(num)
	{
		temp = arr[begin];
		arr[begin] = arr[end];
		arr[end] = temp;
		++begin;
		--end; 
		--num;
	}
}
void recoverRotatedSortedArray(vector<int> &nums)
{
	if(nums.empty())
		return;
	int len = nums.size();
	// 找到旋转的位置
	int xz = INT_MIN;
	for(int i = 0; i < len - 1; ++i)
	{
		if(nums[i] > nums[i + 1])
		{
			xz = i + 1;
			break;
		}	
	} 
	if(xz == INT_MIN)
	return;
	// 向右旋转xz位，得到旋转数组
	// 向左旋转xz位，回复原始数组
	
	reverse(&nums[0], 0, xz - 1);
	reverse(&nums[0], xz , len - 1);
	reverse(&nums[0], 0, len - 1); 

			
}
