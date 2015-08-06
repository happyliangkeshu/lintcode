


class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        
        
        vector<int> count(n + 1);
        count[0] = 1;
        for(int i = 1; i != n + 1; ++i){
            for (int j = 0; j != i; ++j){
            count[i] += count[j] * count[i - j - 1];
            }
        } 
        return count[n];
    }
};
