#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using std::tr1::unordered_map;
vector<int> twoSum(vector<int> &nums, int target, int j);
vector<vector<int> > threeSum(vector<int> &nums);
int main()
{
	
//	int arr[] = {1,0,-1,-1,-1,-1,0,1,1,1};
//	int arr[] = {-8,0,-7,-101,-123,-1,-2,0,-1,0,-1111,0,-1,-2,-3,-4,-5,-6,-100,-98,-111,-11};
//	int arr[] = {0,0,0,0};
	int arr[] = {0,0,0,0,92,0,-3002,0,0,0,-10,-19,0,65,0,0,
	293,0,1,1,1,9,9,9,10,11,1001,2001,-404,201,203,201,999,345,
	1,1,1,1,1,1,1,-2,1,1,1,1,1,1,1,1,-2,1,1,1,1,1,1,1,1,1,1,-1200,
	1,1,1,1,1,2,1202,2,2,-4,2,2,2,2,4,5,6,1,1,-11,1,1,1,1,1,1,1,1,
	101,1,1,1,1,1,-1,1,-6};
	vector<int> nums(arr, arr + sizeof(arr)/4);
	
	vector<vector<int> > vec = threeSum(nums);
	
	
	
	
	
	return 0;
}
	
vector<int> twoSum(vector<int> &nums, int target, int j) {
    unordered_map<int, int> mapping;
    vector<int> result;
    int count0 = 1;
    for(int i = j + 1; i < nums.size(); ++i){
    	if( i > j + 1 && nums[i] == nums[i - 1] && nums[i] + nums[i - 1] != target) continue;
    
//	if( i > j + 1 && nums[i] == nums[i - 1] && nums[i] + nums[i - 1] == target && nums[i] == 0) 
//	        --count0;
    	if( i > j + 2 && nums[i] == nums[i - 2] && nums[i]==0 && target == 0) continue;
    	int gap = target - nums[i];
    	if(mapping.find(gap) != mapping.end() && count0 >= 0){
    	    result.push_back(mapping[gap]);
    		result.push_back(i);
    	}
    	else{
    	    mapping[nums[i]] = i;
    	}
    }
    return result;
}

vector<vector<int> > threeSum(vector<int> &nums) {
    vector<vector<int> > vec;
    vector<int> row(3,0);
    if(nums.size() < 3) return vec;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; ++i){
    	cout << nums[i] << endl;
    	if(i >= 1 && nums[i] == nums[i - 1]) continue;// ШЅжи 
        vector<int> t = twoSum(nums, -nums[i], i);
        if(t.empty()) 
            continue;
        else {

            for(int k = 0; k < t.size()/2; ++k){
                row[0] = nums[i];
                row[1] = nums[ t[2 * k]];
                row[2] = nums[t[2 * k + 1]];
                vec.push_back(row);
            }
            t.clear();
        }
    }
    return vec;
    }
