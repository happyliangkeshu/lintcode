#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//����һ���������飬���ҳ�һ�����������飬ʹ�ø�������ĺ����
//�����ʱ����ֱ𷵻ص�һ�����ֺ����һ�����ֵ�ֵ��
//�����������ͬ�Ĵ𰸣��뷵����������һ����

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int max(int a, int b, int c)
{
	return max(max(a,b),c);
}
int continuousSubarraySum(vector<int>& A);
int main()
{
	
//	int arr[] = {-3, 1, 3, -3, 4, -1, -2,-3};
//	int arr[] = {1, -1};
	int arr[] = {1,2,-2,-100,1,2,-2};
	
	vector<int> A(arr, arr + sizeof(arr)/sizeof(int));
	vector<int> vec;
	
	cout << continuousSubarraySum(A) << endl;

//vec =	continuousSubarraySum(A);
//	for(auto pos = A.begin(); pos != A.end(); ++pos)
//		cout << *pos << ' ';
//	cout << endl;
//	
//	cout << vec[0] << ' ' << vec[1] << endl;
	return 0;
 } 
 
// ��ȷ���� 
    vector<int> continuousSubarraySum(vector<int>& A) {
 	
 	vector<int> vec;
	int maxnum = A[0];
  	int start = A[0];// ��ǰ���ֵ 
	int all = A[0]; // ���к� 
	int first = 0;
	int last = 0;
	int a = 0;
	for(int i = 1; i < A.size(); ++i)
	{
		if(0 > start)
		{
			first = i;
		}
		start = max(A[i], A[i] + start);
		if(start >= maxnum)
		{
			maxnum = start;
			last = i;
			a = first;
		}
	}

    vec.push_back(a);
    vec.push_back(last);
 	return vec;
    }


