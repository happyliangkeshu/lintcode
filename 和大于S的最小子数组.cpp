#include <iostream>
#include <vector>
#include <map> 
//#include <string>
using namespace std;
int minimumSize(vector<int> &nums, int s);

int main()
{
//	int arr[] = {2,3,1,2,4,3};
	int arr[] = {1,1,2,3,1,5};
	vector<int> nums(arr, arr + sizeof(arr)/4);
	int s = 5;
	int a = minimumSize(nums, s); 
	cout << a << endl;
	
		
	return 0;
}

int minimumSize(vector<int> &nums, int s) 
{
    int n = nums.size();
    int cursum = 0;
    map<int, int> used;
    int len = 0;
    int minlen = INT_MAX;
    for(int i = 0; i < nums.size(); ++i){
        cursum += nums[i];
        if(nums[i] >= s){
        	len = 1;
        	minlen = min(len, minlen);
		}
        else if(cursum >= s){
            len = i + 1;
            minlen = min(len, minlen);
        }
        auto pos = used.upper_bound(cursum - s);
        if(pos != used.end() && pos->second > 0){
            auto j = pos->second - 1;
            len = i - j;
            minlen = min(len, minlen);
        }
        
        
            used[cursum] = i;
    }
    
    return minlen== INT_MAX ? -1:minlen;
    
}
