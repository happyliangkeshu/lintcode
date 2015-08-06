// 合并排序数组
#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B);
int searchInsert(vector<int> &A, int target);
int main()
{
	int array1[] = {1,2,3,4, 7, 8, 9, 31};
	int array2[] = {2,4,5,6, 7,8,34 };
	
	vector<int> vec1(array1, array1 + sizeof(array1)/sizeof(int));
	vector<int> vec2(array2, array2 + sizeof(array2)/sizeof(int));
	vector<int> vec3;
	
	vec3 = mergeSortedArray(vec1, vec2);
	
	for(auto pos = vec3.begin(); pos != vec3.end(); ++pos)
		cout << *pos << ' ' ;
	cout << endl;
	
	return 0;
}

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
{
	vector<int> c;
	int lenA = A.size();
	int lenB = B.size(); 
	int i = 0, j = 0;
	while(i < lenA && j < lenB){
		if(A[i] <= B[j]){
			c.push_back(A[i]);
			++i;
		}
		else if(A[i] > B[j]){
			c.push_back(B[j]);
			++j;
		}
	}
	
	cout << "i " << i << endl;
	cout << "j " << j << endl;
	if(i != lenA ||j == lenB){
		for(i; i < lenA; ++i)
			c.push_back(A[i]);
	}
	if(i == lenA || j != lenB){
		
		for(j; j < lenB; ++j)
			c.push_back(B[j]);
	}
	return c;	
        	
        	
}

int searchInsert(vector<int> &A, int target)
{
	int low = 0;
	int high = A.size() - 1;
	if(A.empty())
	return 0;
	if(target > A[high])
	return high + 1;
	while(low < high)
	{
		int mid = (low + high) / 2;
		if(A[mid] < target)
		{
			low = mid + 1;
		}
		if(A[mid] > target)
		{
			high = mid - 1;
		}
		if(A[mid] == target)
		{
			return mid;
		}
	}
	return low;
}
