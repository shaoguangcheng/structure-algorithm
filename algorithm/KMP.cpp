#include <iostream>
#include <string>

using namespace std;

void getNext(const string& pattern, int *next)
{
	int lenPattern = pattern.size();
	int k = -1, i = 0;
	next[0] = -1;

	while(i < lenPattern){
		if(k == -1 || pattern[k] == pattern[i]){
			i++;
			k++;
/*			if(pattern[i] == pattern[k]){
				next[i] = next[k];
			}
			else{
*/				next[i] = k;
//			}
		}
		else{
			k = next[k];
		}
	}
}

void KMP(const string& target, const string& pattern)
{
	int lenTarget = target.size();
	int lenPattern = pattern.size();
	int *next = new int[lenPattern];

	getNext(pattern, next);

	for(int i = 0; i < lenPattern; i++){
		cout << next[i] << " ";
	}
	cout << endl;

	int i = 0, j = 0;
	while(i < lenTarget){
		if(j == -1 || pattern[j] == target[i]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}

		if(j == lenPattern){
			cout << i - lenPattern << endl;
			return; 
		}
	}

	delete [] next;
}

int main()
{
	string target = "abcabdcds";
	string pattern = "abd";

	KMP(target, pattern);

	return 0;
}