#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > fourSum(vector<int> nums, int target) {
    int N = nums.size();

    vector<vector<int> > ans;
    vector<int> tmp;
    if(N < 4)
        return ans;

    sort(nums.begin(), nums.end());
    for(int i = 0; i < N; ++i){
        tmp.push_back(nums[i]);
        for(int j = i+1; j < N; ++j){
            int sum = target - nums[i] - nums[j];
            int k = j+1;
            int r = N-1;
            tmp.push_back(nums[j]);
            while(k < r){
                if(nums[k] + nums[r] == sum){
                    tmp.push_back(nums[k]);
                    tmp.push_back(nums[r]);
                    ans.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                    ++k;
                    --r;
                }

                if(nums[k] + nums[r] < sum)
                    ++k;
                if(nums[k] + nums[r] > sum)
                    --r;

                while(k < r-1 && nums[k] == nums[k+1]  && (sum != nums[k]*2 || sum == nums[k]*2 && nums[k+1] == nums[k+2])
                     ++k;
                while(k < r-1 && nums[r] == nums[r-1] && (sum != nums[r]*2) || sum == nums[r]*2 && nums[r-1] == nums[r-2])
                     --r;

            }
            tmp.pop_back();
            while(j < N-1 && nums[j] == nums[j+1])
                ++j;
        }
        while(i < N-1 && nums[i] == nums[i+1])
            ++i;
        tmp.pop_back();
    }
    return ans;
}

void twoSum(vector<int>& v, int l, int r, int t, vector<int>& ans)
{
	int N = r - l + 1;
	if(N < 2)
		return;

	while(l < r){
		if(v[l] + v[r] == t){
			ans.push_back(v[l]);
			ans.push_back(v[r]);
			for(int i = 0; i < ans.size(); ++i)
				cout << v[i] << " ";
			cout << endl;
			ans.pop_back();
			ans.pop_back();
			++l;
			--r;
		}
		if(v[l] + v[r] < t)
			++l;
		if(v[l] + v[r] > t)
			--r;
		while(l < r-1 && v[l] == v[l+1] && (sum != v[l]*2 || (sum == v[l]*2 && v[l+1] == v[l+2]))
			++l;
		while(l < r-1 && v[r] == v[r-1] && (sum != v[r]*2 || (sum == v[r]*2 && v[r-1] == v[r-2]))
			--r;
	}
} 

void queryFourSum(vector<int>& v, int l, int r, int t, int n, vector<int>& ans)
{
	if(n == 2){
		twoSum(v, l, r, t, ans);
		return;
	}

	for(int i = l; l <= r; ++i){
		ans.push_back(v[i]);
		queryFourSum2(v, l+1, r, t-v[i], n-1, ans);
		ans.pop_back();
	}
}

void fourSum2(vector<int>& v, int t, vector<int>& ans)
{
	sort(v.begin(), v.end());

	vector<int> ans;
	queryFourSum(v, 0, v.size()-1, t, 4, ans);
}

int main()
{
	int array[6] = {1,0,-1,0,-2,2};
	vector<int> v(array, array+6);
	vector<vector<int> > ans;

	ans = fourSum2(v, 0);

	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans[i].size(); ++j){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}	
