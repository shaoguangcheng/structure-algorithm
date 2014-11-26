/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Note
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Example
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

#include <vector>
#include <iostream>

using namespace std;

int getMin(int x, int y)
{
    return x > y ? y : x;
}

int minimumTotal(vector<vector<int> > &triangle)
{
    int N = triangle.size();

	if(N == 1)
	    return triangle[0][0];

	int * d = new int [N];

	d[0] = triangle[0][0];
	for(int i = 1; i < N; ++i){
		d[i] = d[i-1] + triangle[i][i];
		for(int j = i-1; j > 0; --j){
			d[j] = getMin(d[j], d[j-1]) + triangle[i][j];
		}
		d[0] = d[0] + triangle[i][0];
	}

	int ans = d[0];
	for(int i = 0; i < N; ++i)
		if(ans > d[i])
			ans = d[i];

	delete [] d;

	return ans;
}

