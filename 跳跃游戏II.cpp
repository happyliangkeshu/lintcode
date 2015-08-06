class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
// state: f[i]代表我跳到这个位置最少需要几步
// function: f[i] = MIN(f[j]+1, j < i && j能够跳到i)
// initialize: f[0] = 0;
// answer: f[n-1]
    int jump(vector<int> A) {
        
        int n = A.size();
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(j + A[j] >= i){
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n - 1];
        
    }
};
