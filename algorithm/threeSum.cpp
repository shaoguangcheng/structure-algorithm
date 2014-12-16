#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int> > threeSum(vector<int>& v, int target)
{
	int N = v.size();

	sort(v.begin(), v.end());

	int i = 0, j = 0, k = N - 1;
	int sum = 0;

	vector<vector<int> > ans;
	vector<int> tmp;
	for(; i < N; ++i){
		sum = target - v[i];
		j = i + 1;
		k = N - 1;
		tmp.push_back(v[i]);
		while(j < k){
			if(v[j] + v[k] == sum){
				tmp.push_back(v[j]);
				tmp.push_back(v[k]);
				ans.push_back(tmp);
				tmp.pop_back();
				tmp.pop_back();

				while(j > 0 && v[j] == v[j-1])
					++j;
				while(k < N-1 && v[k] == v[k+1])
					--k;
				++j;
				--k;
			}

			if(v[j] + v[k] < sum)
				++j;
			if(v[j] + v[k] > sum)
				--k;
		}
		tmp.pop_back();
	}

	return ans;
}

int main()
{
	int array[10] = {1,2,2,3,3,2,4,5,4,2};
	vector<int> v(array, array+10);
	vector<vector<int> > ans;

	ans = threeSum(array, 4);

	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}