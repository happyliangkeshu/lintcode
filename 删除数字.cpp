删除数字

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    
    string DeleteDigits(string A, int k) {
       if(A.empty() || k <= 0){
           return A;
       }
       if(A.size() <= k ){
           return {};
       }
// 每次删除一个数字，从左往右每相邻的两个数字比较，
// 若左边大于右边则删除左边的那个数字，则删掉左边的数字
// 178542 第一次 8 > 5, 删除8， 剩余的17542是删除一个数字后最小的
// 第二次 7 > 5 ,删除7，剩余的1542是删除两个数字后最小的
// 依次类推
// 否则比较下一对数字

       while(k ){
            for(auto pos = A.begin(); pos != A.end(); ++pos){
           auto pos1 = pos+1;
           if(*pos > *pos1){
               A.erase(pos);
               break;
           }
           
            }
            --k;
       }
       while(A.front() == '0'){
           A.erase(A.begin());
       }
       return A;

        
    }
};

