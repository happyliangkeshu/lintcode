state: f[i][j] 表示 S的前i个字符中选取T的前j个
字符，有多少种方案
function:
f[i][j] = f[i - 1][j] + f[i - 1][j - 1] (S[i-1] == T[j-1])
= f[i - 1][j] (S[i-1] != T[j-1])
initialize: f[i][0] = 1, f[0][j] = 0 (j > 0)
answer: f[n][m] (n = sizeof(S), m = sizeof(T))

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector<int> f(T.size() + 1);
        f[0] = 1;
        for (int i = 0; i < S.size(); ++i) {
            for (int j = T.size() - 1; j >= 0; --j) {
                f[j + 1] += S[i] == T[j] ? f[j] : 0;
            }
        }
        return f[T.size()];
    }
};

