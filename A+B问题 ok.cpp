#include <iostream>
#include <iomanip>
using namespace std;

//定理1：设a，b为两个二进制数，则a+b = a^b + (a&b)<<1。 
//证明：a^b是不考虑进位时加法结果。当二进制位同时为1时，才有进位，因此 (a&b)<<1是进位产生的值，称为进位补偿。将两者相加便是完整加法结果。 
//定理2：使用定理1可以实现只用位运算进行加法运算。 
//证明：利用定理1中的等式不停对自身进行迭代。每迭代一次，进位补偿右边就多一位0，因此最多需要加数二进制位长度次迭代，进位补偿就变为0，这时运算结束。 
int main()
{
	int a = 3;
	
	int b = 5;
	
	
	
	
	
	return 0;
} 

    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int carry;
        int sum;
        while(b ){
            sum = a^b;
            carry = (a & b) << 1 ;
            //  进位左移，继续与之前的和相加，直到进位为0为止。
            a = sum;
            b = carry;
        }
        return a;
    }
