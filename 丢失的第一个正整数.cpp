 //丢失的第一个正整数
 //给出一个无序的正数数组，找出其中没有出现的最小正整数。
// 如果给出 [1,2,0], return 3 如果给出 [3,4,-1,1], return 2
 
 
 //这种方法很好，但是使用了o(n) 的空间
     int firstMissingPositive(vector<int> A) {
       if(A.empty() ) return 1;
       int n = A.size();
       vector<bool> hash(n, false);
       for(int i = 0; i < n; ++i){
		   //找的是第一个正整数
		   // 负数就直接排除掉了，大于n的数也直接排除掉了
		   // 在这个过程中，也对A[i] - 1进行了排序了
           if(A[i] > 0 && A[i] <= n) hash[A[i] - 1] = true;
       }
       for(int i = 0; i < n; ++i){
           if(!hash[i]) return i + 1;
       }
		
	   // 如果数字是[1,2,3,4,5] 缺失的就是6 ，前边计算不出，在这里return
       return n + 1;
    }
	
//通过交换，把A[i] 放到A[i] - 1 的位置上边
// 例如A[0] = 3, 那么3应该放在A[2] ,那么就交换A[0] 与 A[2]	
int firstMissingPositive(vector<int> A) {
 
       int n = A.size();
       for(int i = 0; i < n; ++i){
		   // 将负数 和  大于n的数也直接去掉
		   // A[i] != A[A[i] - 1] 自然包含了 i != A[i] - 1,即 A[i] != i + 1;
            while(A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]){
                swap(A[i], A[A[i] - 1]);
            }
       }
       for(int i = 0; i < n; ++i){
           if(A[i] !=  i + 1 ){
               return i + 1;
           }
       }
       return n + 1;
    }
	
	
    int firstMissingPositive(vector<int> A) {
    //   if(A.empty() ) return 1;
       int n = A.size();
       for(int i = 0; i < n; ){
			if(A[i] == i + 1)
				++i; 
			// 如果有一个不满足条件的数的话
			// 就把最后一个数给i，并且n - 1，
			// 相当于把这个不符合条件的数给删掉了
			// A[i] == A[A[i] - 1] 
			else if(A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
				A[i] = A[--n]; 
			else 
				swap(A[i], A[A[i] - 1]);
       }
    
       return n + 1;
	}