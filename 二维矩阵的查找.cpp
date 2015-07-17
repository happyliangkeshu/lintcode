    
	
	
	bool find(vector<vector<int> > a, int x1, int y1, int x2, int y2, int target){
        
        if(x1 > x2 || y1 > y2){
            return false;
        }
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        if(a[midx][midy] == target)
            return true;
        return (target < a[midx][midy])?
        find(a, x1, y1,midx - 1, y2, target) || find(a, midx, y1, x2, midy -1, target):
        find(a,x1, midy + 1, x2, y2, target) || find(a, midx + 1, y1, x2, midy, target);
        
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty() ) return false;
         int m = matrix.size(), n = matrix[0].size();
         
         return find(matrix, 0, 0, m - 1, n - 1, target);
        
    }
	
	     int help(vector<int> & a, int y1, int y2, int target){
         int left = y1, right = y2;
         while(left <= right){
             int mid = (left + right) >> 1;
             if(a[mid] <= target){
                 left = mid + 1;
             }
             else{
                 right = mid - 1;
             }
         }
         return left - 1;
     }
    bool find(vector<vector<int> > a, int x1, int y1, int x2, int y2, int target){
        
        if(x1 > x2 || y1 > y2){
            return false;
        }
        int midx = (x1 + x2) >> 1;
        int indy = help(a[midx], y1, y2, target);
        if(indy >= y1 && a[midx][indy] == target){
            return true;
        }
        return find(a, x1, indy + 1, midx - 1,y2, target) 
        || find(a, midx + 1, y1, x2, indy, target);

        
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty() ) return false;
         int m = matrix.size(), n = matrix[0].size();
         
         return find(matrix, 0, 0, m - 1, n - 1, target);
        
    }
	
	
	