// 最少
// 1. max/min true/false  count;
// 2. 是不是能随便改变sequence里面的东西
// state ：前i个字符最少分割几次，能够分割成为各自都是回文串
// function : f[i] = min(f[j] +1, j < i && j + 1 ~ i 这一段是回文串)
// answer: f[s.length]
// intialize : f[0] = -1, f[1] = 0, f[2] = 1 ... f[i] = i - 1


class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    bool isPalindrome(string &s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (s[i] != s[j] ){
                return false;
            }
        }
        return true;
    }
	// 预处理来节省时间
      void getIsPalindrome(string &s,vector<vector<bool>>& isPalindrome) {
          int n = s.size();
        // auto isPalindrome = ;

        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
        }

        for (int length = 2; length < n; length++) {
            for (int start = 0; start + length < n; start++) {
                isPalindrome[start][start + length]
        = isPalindrome[start + 1][start + length - 1] && s[start] == s[start + length];
            }
        }
    }
    int minCut(string s) {
        
        int n = s.size() + 1;
        vector<int> f;
        for(int i = 0; i < n + 1; ++i){
            f.push_back(i - 1);
        }
		// 二维数组做参数还是vector好用
        vector<vector<bool>> isPalindrome(n, vector<bool>(n));
        getIsPalindrome(s, isPalindrome);
		
		// i 的值必须要能够到n 才可以， 这代表整个串是回文串，不需要分
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                // auto str = s.substr(j, i - j);
                if(isPalindrome[j][i - 1]){
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        
        return f[s.size()];
    }
};


