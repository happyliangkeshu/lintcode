int countDigitK(int n, int k) {
    long long base = 1, res = 0, last = 0;
    while(n >= base){
        int index = (n / base) % 10;
        long long remain = n - (n / base) * base;
        if(index > k){
            res = res + index * last + base;
        }else if(index == k){
            res = res + index * last + remain + 1;
        }else{
            res = res + index * last;
        }
        last = last * 10 + base;
        base = base * 10;
    }
    return res;
}