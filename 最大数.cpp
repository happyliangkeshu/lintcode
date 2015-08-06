     给出样例 [1, 20, 23, 4, 8]，返回组合最大的整数为8423201
	 
	 
	 static bool cmp(int a, int b){
         return to_string(a) + to_string(b) > to_string(b) + to_string(a);
     }
    string largestNumber(vector<int> &num) {
        string res;
        sort(num.begin(), num.end(), cmp);
        for (int n : num) { res += to_string(n); }
        // return result.front() == '0' ? "0" : result;
        
        return res.front() == '0' ? "0" : res;
		// 如果数字全是0的情况下，只返回一个0就可以了
｝		
	 
	 static bool cmp(int a, int b){
         return to_string(a) + to_string(b) > to_string(b) + to_string(a);
     }
    string largestNumber(vector<int> &num) {
        vector<int> & nums = num;
        string result;
        sort(nums.begin(), nums.end(), cmp);
        for (int n : nums) { result += to_string(n); }
        return result.front() == '0' ? "0" : result;
    }
	
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        sort(nums.begin(), nums.end(), 
		[](int a, int b) {
		return to_string(a) + to_string(b) >
		to_string(b) + to_string(a); 
		});
		
        for (int n : nums) { result += to_string(n); }
        return result.front() == '0' ? "0" : result;
    }
};