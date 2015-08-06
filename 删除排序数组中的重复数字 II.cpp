#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums);
int removeDuplicates1(vector<int> &nums);
int main()
{
//	int array[] = {1,1,1,2,2,3,3,3,4,4,5,5,5,5,5,55,6};
	int array[] = {-8,0,1,2,3};
	vector<int> A(array, array + sizeof(array)/sizeof(int));
	
	int len = removeDuplicates1(A);
	for(auto pos = A.begin(); pos != A.end(); ++pos)
	{
		cout << *pos << " ";
	}
	cout << endl <<len << endl;

	return 0;
 } 
 // lintcode 测试通过
  
    int removeDuplicates(vector<int> &nums) {
    	if(nums.empty())
    		return 0;
        int index = 2;
        int len = nums.size();
        for(int i = 2; i < len; ++i)
        {
        	if( nums[i] != nums[index - 2] )
        	{
        		nums[index++] = nums[i];
        		// 想象index指向另一个数组 
			}
		}
		return index; // 数组长度是最大索引值加一 
    }
    
    
 int removeDuplicates1(vector<int> &nums) {
    	if(nums.empty())
    		return 0;
        int len = nums.size();
        if(len <= 2)
        return len;
        int index = 0;
        for(int i = 2; i < len; ++i)
        {
        	if( nums[i] != nums[index] )
        	{
        		nums[(index++) + 2] = nums[i];
        		// 想象index指向另一个数组 
			}
		}
		return index + 2; // 数组长度是最大索引值加一 
    }
