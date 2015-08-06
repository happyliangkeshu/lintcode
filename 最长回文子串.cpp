

    string longestPalindrome(string& s) {
        // Write your code here
        if(s.size() < 2) return s;
        std::map<int,int> mpal;//<len,start> 
        for(int i = 0; i < s.size(); )
        {
            int start = i;
            while(s[start] == s[i+1]) ++i;
            int finish = i;
            while(start >= 0 && finish < s.size() && s[start] == s[finish]) 
            {
                --start;
                ++finish;
            }
            if(finish - start >= 3) mpal.insert(std::make_pair(finish-start-1, start+1));
            ++i;
        }
        auto m = std::max_element(mpal.begin(),mpal.end());
        return s.substr((*m).second,(*m).first);
    }
	
	
http://blog.csdn.net/yzl_rex/article/details/7908259	
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
     // Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(string s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++) 
            ret += "#" + s.substr(i, 1);
            ret += "#$";
         return ret;
    }
    string longestPalindrome(string& s) {
        // Write your code here
      string T = preProcess(s);
        const int n = T.length();
    // 以 T[i] 为中心，向左/右扩张的长度，不包含 T[i] 自己，
    // 因此 P[i] 是源字符串中回文串的长度
    int P[n];
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i; // equals to i' = C - (i-C)
        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
    // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
    P[i]++;
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
            }
            }
            // Find the maximum element in P.
            int max_len = 0;
            int center_index = 0;
            for (int i = 1; i < n - 1; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                center_index = i;

                }
            }
            return s.substr((center_index - 1 - max_len) / 2, max_len);
        }
};
