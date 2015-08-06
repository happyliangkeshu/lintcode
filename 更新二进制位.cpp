#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
void Itoa( int num, char *str, int base );
int updateBits(int n, int m, int i, int j);
int main()
{
//	int n = 1024, m = 21, i = 2, j = 6;
//	int n = 1, m = -1, i = 0, j = 31;
int n = 512, m = -1, i = 0, j = 31;
	int a = updateBits(n, m, i, j);
	
	cout << a << endl;
	return 0;
} 

void Itoa( int num, char *str, int base ){
	char *p = str;
	stack<int> s;
	while(num){
		s.push(num % base);
		num /= base;
	}
	while(!s.empty()){
		*str++ = s.top() + '0';
		s.pop();
	}
	*str = 0;
}
int updateBits(int n, int m, int i, int j) {
    // write your code here
    char sn[33] = {0};
    char sm[33] = {0};
    
    itoa(n, sn, 2);
    itoa(m, sm, 2);
    int ln = strlen(sn), lm = strlen(sm);
    if(j >= ln){
    	strncpy(sn + 32 - 1 - j, sm, lm);
	}
	else{
		strncpy(sn + ln - 1 - j, sm, lm);
	}
    
    int num = 0;
    int base = 1;
    ln = strlen(sn);
    for(int i = ln - 1; i >= 0; --i){
        num += (sn[i] - '0' ) * base;
        base *= 2;
    }
    
    return num;
}
