// 计算当前位置 和 当前位置所能跳的长度。
     // 一层一层往上跳
    bool canJump(vector<int> A) {
        
        int step = A[0], n = A.size();
        for(int i = 1; i < n; ++i){
            if(step == 0){
                return false;
            }
            --step;
            step = max(step, A[i]);
            
            if(step + i >= n - 1){
                return true;
            }
        }
        return false;
        
    }