state: f[i][j]表示s1的前i个字符和s2的前j个字符能否交替组成s3的前i+j
个字符
function: f[i][j] = (f[i-1][j] && (s1[i-1]==s3[i+j-1]) ||
f[i][j-1] && (s2[j-1]==s3[i+j-1])
initialize: f[i][0] = s1[0..i-1] = s3[0..i-1]
f[0][j] = s2[0..j-1] = s3[0..j-1]
answer: f[n][m]
n = sizeof(s1), m = sizeof(s2)

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s3.length() != s1.length() + s2.length())
            return false;
vector<vector<bool>> f(s1.length() + 1, vector<bool>(s2.length() + 1, true));
		// 初始化初值
        for (size_t i = 1; i <= s1.length(); ++i)
            f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (size_t i = 1; i <= s2.length(); ++i)
            f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		
		// 按照状态方程写就可以了
        for (size_t i = 1; i <= s1.length(); ++i)
            for (size_t j = 1; j <= s2.length(); ++j)
            f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
            || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
        
        return f[s1.length()][s2.length()];
    }
};
