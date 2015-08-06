#include <iostream>
using namespace std;
void mergeSortedArray(int A[], int m, int B[], int n);
int main()
{
	int A[100] = {0};
	int m = 10;
	for(int i = 0; i < m; ++i)
		A[i] = i + 10;
	const int n = 6;
	int B[n] = {1,2,3,4,5,6};	
	
	mergeSortedArray(A, m, B, n);
	
	return 0;
}

void mergeSortedArray(int A[], int m, int B[], int n)
{
     // 将B中数字插入A中 
     // 插入之后，A中数字需要后移
     int i = 0, j = 0;
     while(i < m && j < n){
     	if(A[i] <= B[j]){
     		++i;
		 }
		 else if(A[i] > B[j]){
		 	insert(A, i, B[j]);
		 }
	 }
	 cout << i << endl;
	 cout << j << endl; 
	  
}
void insert(int A[], int pos, int val)
{
	
	
}
