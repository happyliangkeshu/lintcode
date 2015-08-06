    
	
	//乱序字符串
	// 排序，统计出现的次数，
	// 将出现次数 大于1的 输出 就可以了。
	
	vector<string> anagrams(vector<string> &strs) {
        
        map<string, int>mas;
        
        for(auto str : strs){
            sort(str.begin(), str.end());
            ++mas[str]; 
        }
        vector<string > res;
        for(auto str : strs){
            auto temp = str;
            sort(temp.begin(), temp.end());
            if(mas[temp] > 1){
                res.push_back(str);
            }
        }
        return res;
    }