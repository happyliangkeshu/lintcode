#include <iostream>
#include <vector>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle);
int main()
{
	vector<vector<int>> triangle={
	    {2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3},
	};
	
	int num = minimumTotal(triangle);	
	
	return 0;
} 

int minimumTotal(vector<vector<int> > &triangle){
	
	int m = triangle.size();
	vector<vector<int> > dp(m + 1, vector<int>(m + 1, 0));
	
	for(int i = 0; i < m; ++i){
		for(int j = 0; j <= i; ++j){
			if(i == 0){
				dp[0][0] = triangle[0][0];
			}
			else if(j == 0){
				dp[i][0] = dp[i - 1][0] + triangle[i - 1][0];
			}
			else{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1])
			 + triangle[i][j];
			}

		}
	}
	
}
