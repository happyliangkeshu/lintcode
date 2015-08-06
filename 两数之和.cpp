#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using std::tr1::unordered_map;
vector<int> twoSum(vector<int> &nums, int target);
int main()
{
//	int arr[] = {2,7,11,15};
	int arr[] = {0,4,1,1,1,1,1,1 ,3,0};
	vector<int > nums(arr, arr + sizeof(arr)/sizeof(int));
	
	int target = 2;
	twoSum(nums, target);
	
	return 0;
}
vector<int> twoSum(vector<int> &nums, int target) {
	unordered_map<int, int> mapping;
	vector<int> result;
	for(int i = 0; i < nums.size(); ++i){
		int gap = target - nums[i];
		if(mapping.find(gap) != mapping.end() ){
			result.push_back(mapping[gap] + 1);
			result.push_back(i + 1);
		}
		else{
			mapping[nums[i]] = i;
		}
	}
	return result;
}
