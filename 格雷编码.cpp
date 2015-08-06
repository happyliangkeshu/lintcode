//格雷编码
//格雷码有数学公式，整数 n 的格雷码是 n ⊕ (n/2)。
//这题要求生成 n 比特的所有格雷码。
//方法 1，最简单的方法，利用数学公式，对从 0 ∼ 2n − 1 的所有整数，转化为格雷码。

    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        int size = 1 << n;
		// 预留出size大的内存，这样做的效率要高
		// 如果vector<int> v(5) 这样做只是为了保留足够的内存的话，
		// 那就应该使用reserve
		// 避免内存不够，而重新分配内存，提高效率。
        res.reserve(size);
        for(int i = 0; i < size; ++i){
            res.push_back( i^(i >> 1) );
        }
        
        return res;
    }