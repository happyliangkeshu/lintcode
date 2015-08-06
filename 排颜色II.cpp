//给定一个有n个对象（包括k种不同的颜色，并按照1到k进行编号）的数组，
//将对象进行分类使相同颜色的对象相邻，
//并按照1,2，...k的顺序进行排序。

   void sortColors2(vector<int> &colors, int k) {
        // write your code here
        vector<int> cnt(k + 1, 0);
        
        for(int i = 0; i < colors.size(); ++i){
            ++cnt[colors[i]];
        }
        for (int i = 1, index = 0; i <= k; i++)
            for (int j = 0; j < cnt[i]; j++)
                colors[index++] = i;
        
        
    }