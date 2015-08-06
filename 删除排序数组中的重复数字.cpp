#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums);
int main()
{
	int array[8] = {0,4,4,0,0,2,4,4};
	vector<int> A(array, array + 8);
	
	removeDuplicates(A);
	for(auto pos = A.begin(); pos != A.end(); ++pos)
	{
		cout << *pos << " ";
	}
	cout << endl << endl;
//	endl <<len1 << endl;
	return 0;
 } 
 // lintcode 测试通过
  
    int removeDuplicates(vector<int> &nums) {
    	if(nums.empty())
    		return 0;
        int index = 0;
        int len = nums.size();
        for(int i = 1; i < len; ++i)
        {
        	if( nums[index] != nums[i] )
        	{
        		nums[++index] = nums[i];
        		// 想象index指向另一个数组 
			}
		}
		return index + 1; // 数组长度是最大索引值加一 
    }
