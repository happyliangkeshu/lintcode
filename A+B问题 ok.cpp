#include <iostream>
#include <iomanip>
using namespace std;

//����1����a��bΪ����������������a+b = a^b + (a&b)<<1�� 
//֤����a^b�ǲ����ǽ�λʱ�ӷ��������������λͬʱΪ1ʱ�����н�λ����� (a&b)<<1�ǽ�λ������ֵ����Ϊ��λ��������������ӱ��������ӷ������ 
//����2��ʹ�ö���1����ʵ��ֻ��λ������мӷ����㡣 
//֤�������ö���1�еĵ�ʽ��ͣ��������е�����ÿ����һ�Σ���λ�����ұ߾Ͷ�һλ0����������Ҫ����������λ���ȴε�������λ�����ͱ�Ϊ0����ʱ��������� 
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
            //  ��λ���ƣ�������֮ǰ�ĺ���ӣ�ֱ����λΪ0Ϊֹ��
            a = sum;
            b = carry;
        }
        return a;
    }
