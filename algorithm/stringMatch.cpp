#include <string>
#include <iostream>

using namespace std;

int BFMatch(const string& p, const string& t)
{
	int np = p.size(), nt = t.size();

	if(nt < np)
		return -1;

	int i = 0, j = 0, k = 0;

	while(i < nt){
		k = i;
		j = 0;
		while(j < np){
			if(k < np && p[j] == t[k]){
				++k;
				++j;
			}
			else
				break;
		}

		if(j == np)
			return i;
		else
			++i;
	}

	return -1;
}

int main(int argc, char* argv[])
{
	string t("my name is cheng");
	string p("name");

	cout << BFMatch(p, t) << endl;

	return 0;
}