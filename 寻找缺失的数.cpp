//寻找缺失的数

// 给出一个包含 0 .. N 中 N 个数的序列，找出0 .. N 中没有出现在序列中的那个数。

// N = 4 且序列为 [0, 1, 3] 时，缺失的数为2。

// 一种方法 可以直接求和
// 另一种方法，就是使用位运算 与它的下标做异或
    int findMissing(vector<int> &nums) {
          
          int n = nums.size();
          int res = 0;
         for(int i = 0; i < n; ++i) {
             res ^= (nums[i] ^ i);
         }
         res ^= n;
         return res;
    }