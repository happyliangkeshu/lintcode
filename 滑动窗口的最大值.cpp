#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k);
int main()
{
	int arr[] = {1,2,7,7,2,10,3,4,5};
	int k = 2;
	vector<int> nums(arr, arr + sizeof(arr)/4);
	vector<int> vec;
	vec = maxSlidingWindow(nums, k);
	
	return 0;
} 

vector<int> maxSlidingWindow(vector<int> &nums, int k) 
{
    // write your code here
    
    int n = nums.size();
    if(nums.empty() ) return {};
    if(k == 1) return nums;
    vector<int> vec;
    int maxi = nums[0];
    int maxpos = 0;
    for(int i = 0; i < k; ++i) {
        if(maxi <= nums[i]){
            maxi = nums[i];
            maxpos = i;
        }
    }
    vec.push_back(maxi);
    for(int i = 1; i <= n - k; ++i){
        if(maxpos != i - 1){
            if(maxi <= nums[i + k - 1]){
                maxpos = i + k -1;
                maxi = nums[i + k - 1];
            }
        vec.push_back(maxi);
        }
        else{
        	max[i] = nums[j];
        	maxpos = j;
            for(int j = i; j <= i + k -1; ++j){
                if(maxi <= nums[j]){
                    maxi = nums[j];
                    maxpos = j;
                }
            }
        vec.push_back(maxi);
        }
    }
    
    return vec;
}
