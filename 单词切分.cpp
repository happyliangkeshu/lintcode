单词切分
1.yes/no
2.不能交换字符的字符串
猜： 可以用DP
f[i]:表示前i个能不能被dict完美划分
f[i] = f[j], j < i && j + 1 ~ i 是一个dict里单词
f[i] = OR(f[j], j < i && j + 1 ~ i 是dict里的一个单词)
//initialize :
f[0] = true;
// answer:
f[s.length()]
// 单词长度不会很长 枚举长度


class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
      int getMaxLength(unordered_set<string> &dict) {
        int maxLength = 0;
        for (auto & word : dict) {
            maxLength = max(maxLength, (int)word.size());
        }
        return maxLength;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        
        int n = s.size();
        vector<bool> f(n + 1); 
        f[0] = true;
        int maxlength = getMaxLength(dict);
       for(int i = 1; i <= n; ++i ) {
           f[i] = false;
		   // 枚举长度
           for(int j = 1; j <= maxlength && j <= i; ++j){
               if(!f[i - j]){
                   continue;
               }
			   // i - j 是字符串的起始位置， j 是子字符串的长度。
               auto str = s.substr(i - j, j);
               if(dict.find(str) != dict.end()){
                   f[i] = true; 
                   break;
               }
           }
       }
       return f[n];
    }
};
