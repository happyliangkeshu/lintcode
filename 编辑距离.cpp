state: f[i][j]a的前i个字符“配上”b的前j个字符
最少要用几次编辑使得他们相等
function:
f[i][j] = MIN(f[i-1][j-1], f[i-1][j]+1, f[i][j-1]+1) // a[i] == b
[j]
= MIN(f[i-1][j], f[i][j-1], f[i-1][j-1]) + 1 // a[i] != b[j]
intialize: f[i][0] = i, f[0][j] = j
answer: f[a.length()][b.length()]

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        const size_t n = word1.size();
const size_t m = word2.size();
// 长度为 n 的字符串，有 n+1 个隔板
int f[n + 1][m + 1];
        for (size_t i = 0; i <= n; i++)
            f[i][0] = i;
        for (size_t j = 0; j <= m; j++)
            f[0][j] = j;
        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                   f[i][j] = f[i - 1][j - 1];
                 else {
                    int mn = min(f[i - 1][j], f[i][j - 1]);
                    f[i][j] = 1 + min(f[i - 1][j - 1], mn);
                    }
            }
        }
            return f[n][m];
    }
};

