#include <string>
#include <iostream>

using namespace std;

/*
*  Brute Force match
*/
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
            if(k < nt && p[j] == t[k]){
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

/////////////////////////////////////////
//  KMP
void getNext(const string& p,  int *next)
{
    int np = p.size();

    next[0] = -1;
    int  k = 0, j = 1;
    while(j < np){
        if(k == -1 || p[k] == p[j]){
            next[j] = next[j-1]+1;
            ++k;
            ++j;
        }
        else
            k = next[k];
    }
}
/////////////////////////////////////////////
bool equal(const string& p, int i, int j)
{
    int k = 0, m = i-j;
    for(; k <= j-1 && m <= i-1; ++k, ++m){
        if(p[k] != p [m])
            return false;
    }
    return true;
}
void getNext2(const string& p, int * next)
{
    int np = p.size();

    next[0] = -1;
   next[1] = 0;

    int i = 1, j = 0;
    while(i < np){
        for(j = i-1; j >0; --j){
            if(equal(p, i, j)){
                next[i] = j;
            }
            else
                next[i] = 0;
        }
        ++i;
    }
}

int KMP(const string& p, const string& t)
{
    int np = p.size(), nt = t.size();
    int * next = new int [np];

    getNext2(p, next);

    int i = 0, j = 0 ;
    while(i < nt){
        if(j == -1 || p[j] == t[i]){
            ++j;
            ++i;
        }
        else
            j = next[j];

        if(j == np)
            return i-j;
    }

    delete [] next;

    return -1;
}


int main(int argc, char* argv[])
{
    string t("my name is cheng");
    string p("name");

    cout << KMP(p, t) << endl;

    return 0;
}
