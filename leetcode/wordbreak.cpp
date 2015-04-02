#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

bool wordBreak(string s, unordered_set<string>& dict)
{
	const int size = s.size();
	if(size == 0)
		return true;

	vector<bool> result(size+1, false);

	result[0] = true;

	for(int i = 1; i <= size; ++i){
		for(int j = i-1; j >= 0; --j){
			if(result[j] && dict.find(s.substr(j, i-j)) != dict.end()){
				result[i] = true;
				break;
			}
		}
	}

	return result[size];
}

///////////////////////////////////////////////////////////////////

void breakWord(string s, unordered_set<string>& dict, 
	vector<bool>& dp, int index, string& subs)
{
	const int size = s.size();
	for(int i = index; i < size; ++i){
		if(dp[i+1])
	}
}

vector<string> wordBreak2(string s, unordered_set<string>& dict)
{
	vector<string> result;
	const int size = s.size();

	if(0 == size)
		return result;

	vector<bool> dp(size+1, false);

	dp[0] = true;

	for(int i = 1; i <= size; ++i){
		for(int j = i-1; j >= 0; --j){
			if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end){
				dp[i] = true;
				break;
			}
		}
	}

	if(dp[size]){
		breakWord(s, dict, dp, 0, "");
	}

	return result;
}

int main()
{
	string s("leetcode");
	unordered_set<string> dict;

	dict.insert("leet");
	dict.insert("code");

	cout << wordBreak(s, dict) << endl;

	return 0;
}