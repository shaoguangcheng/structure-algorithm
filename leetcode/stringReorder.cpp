#include <string>
#include <iostream>

using namespace std;

bool isValid(string& s)
{
	const int n = s.size();
	for(int i = 0; i < n; ++i){
		if(!((s[i] >= '0'&&s[i] <= '9')||(s[i] >= 'a' && s[i] <= 'z')))
			return false;
	}
	return true;
}

void countChar(int* table, string& s)
{
	const int n = s.size();
	for(int i = 0; i < n; ++i){
		if(s[i] >= '0' && s[i] <= '9')
			++table[s[i]-'0'];
		else
			++table[s[i]-'a'+10];
	}
}

int main()
{
	int table[36] = {0};
	string s;

	while(cin >> s){
		if(!isValid(s)){
			cout << "Invalid" << endl;
			continue;
		}

		countChar(table, s);
		const int n = s.size();
		bool isPrint = true;
		while(isPrint){
			isPrint = false;
			for(int j = 0; j < 36; ++j){
				if(table[j] != 0){
					isPrint = true;
					--table[j];
					if(j < 10)
						cout << char(j+'0');
					else
						cout << char(j-10+'a');
				}
			}
		}
	}

	return 0;
}