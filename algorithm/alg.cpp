/**
*@file alg.cpp
*@author cheng shaoguang
*@date Sun Jan 12 2013
*
*@brief try to practice some useful algs
*@note
*/

//c header
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

//c++ header
#include <iostream>
#include <assert.h>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

//linux header
#include <time.h>

using namespace std;

/**       problem1 start        */
/**
 *  problem1 description : input a string that ends with '!' from console
 *                      and then output it in reverse
 */
void input(char* s)
{
	char ch = (char)getchar();
	if(ch != '!'){
		*s = ch;
		input(s+1);	
	}
	else
		*s = '\0';
}

void rstring(char* s,int n)
{
	while(n--){
		printf("%c",*(s+n));
	}
	printf("\n");
}

void p1()
{
	char *a = (char*)malloc(sizeof(char)*1000);
	input(a);
	printf("reverse string : \n");
	rstring(a,strlen(a));
	free(a);
}

///////////////problem1 end///////////////////////////


///////////////problem2 start/////////////////////////
/**
 *  problem2 description : all arrangement problem
 */

/**
* output stack data type
*/
ostream& operator <<(ostream &out,const stack<int,vector<int> > &S)
{
	stack<int,vector<int> > tmp = S;
	int size = (int)tmp.size();
	for(int i=0;i<size;i++){
		cout << tmp.top() << " ";
		tmp.pop();
	}
	
	cout << endl;
	return out;
}

/**
* copy whole array elements except src[delIndex]
* For example, when src : {1,2,3,4}, delIndex : 2, n: 4
* then the dest : 1,2,4
**/
void copyArray(int* src,int delIndex, int n, int* dest)
{
	assert(src != NULL && dest != NULL);
	int j = 0;	
	for(int i=0;i<n;i++){
		if(i == delIndex)
			continue;
		dest[j++] = src[i];
	}
}

static stack<int,vector<int> > S; 
static  int size = 0;
//method 1
void arrange1(int* ptr,const int n)
{
	if(1 == n){
		S.push(*ptr);
		cout << "the " << ++size << "-th  :";
        cout << S;
		S.pop();
		return; 		
	}

	for(int i=0;i<n;i++){
		S.push(*(ptr+i));
		
		int *ptr_ = new int [n-1];		
		copyArray(ptr,i,n,ptr_);
	
		arrange1(ptr_,n-1);
		S.pop();
		
		delete [] ptr_;
	}
}

//method 2
void arrange2(int *ptr,const int n,bool *isUsed)
{
    if((unsigned int)S.size() == n){
		cout << "# " << ++size << " :";
		cout << S;
		return;
	}
	
	for(int i=0;i<n;i++)
		if(!isUsed[i]){
			isUsed[i] = true;
			S.push(ptr[i]);
			arrange2(ptr,n,isUsed);
			S.pop();
			isUsed[i] = false;
		}
}

void p2()
{
    const int N = 6;
    int a[N] = {1,2,3,4,5,6};
	bool isUsed[N] = {false};

    clock_t begin = clock();
//	arrange2(a,N,isUsed);
    arrange1(a,N);
    clock_t end = clock();

    cout << "time consumed : " << begin - end << endl;
}

template<class T>
void printArray(T *ptr, int n)
{
	for(int i=0;i<n;i++)
		cout <<*(ptr+i) << " ";
	cout << endl;
}
///////////////problem2 end///////////////////////////


///////////////problem3 start/////////////////////////
/**
 *  problem3 description : we have some goods that weights w1,w2,w3,....we use a bag which maximum volume is T.
 *                          output all possible conditions that satisfy w1+w2+...=T
 */

/**
* judge whether array T has the element t, where n is the total number of elements in array
*/
template <class T>
bool isIn(const T *array, int n, const T &t)
{
	assert(array != NULL);
	for(int i=0;i<n;i++)
		if(array[i] == t)
			return true;

	return false;
}

template <class T>
void printVec(const vector<T> &v, const char sep = ' ')
{
	for(int i=0;i<v.size();i++)
		cout << v[i] << sep;
	cout << endl;
}

int sumVec(const vector<int> &s)
{
	int sum = 0;
	int size = (int)s.size();
	for(int i=0;i<size;i++)
		sum += s[i];
	
	return sum;
}

//static int num = 0; //the number of answers
 //save the answers
static vector<int> SS;
static set<vector<int> > ans;
void solveP3(int *w,const int N,int T)
{
	if(0 == N) return;

	for(int i=0;i<N;i++){
		SS.push_back(*(w+i));
		if(sumVec(SS) == T){
			vector<int> SS_ = SS;
			sort(SS_.begin(),SS_.end());
			ans.insert(SS_);

//			cout << ++num << "-th answer : ";
//			printVec(SS);
			SS.pop_back();
			continue;
		}
		
		int *w_ = new int [N-1];
		copyArray(w,i,N,w_);
		solveP3(w_,N-1,T);
		SS.pop_back();
		delete [] w_;		
	}
}

void p3()
{
	const int N = 10;
	int w[N];
	int T;
	int nTimes = 0;

	cout << "please input the weight of " << N << " packages :" << endl;
	for(int i=0;i<N;i++)
		cin >> w[i];

	cout << "please input the maximum volume of the bag :" << endl;
		cin >> T;
	
	solveP3(w,N,T);

	set<vector<int> >::iterator it;
	cout << "finally result : " << endl;
	for(it = ans.begin();it != ans.end();it++){
		cout << ++nTimes << "-th answer : ";	
		printVec(*it);
	}
}
///////////////problem3 end///////////////////////////

///////////////probelm4 start/////////////////////////
/**
 *  problem4 description : prime ring problem. Use number from 1 to 20 to fill 20 positions and ensure
                          that the sum of two adjacent number is prime. These 20 positions form a ring.
 */
static vector<int> ring; // data in ring
static vector<int> org; // original data set
static bool isFind = false; //isFind : a sign that indicate if the solution is found

// decide whether a number is a prime
bool isPrime(const int v)
{
	for(int i=2;i<=sqrt(v);i++)
		if(v%i == 0)
			return false;
	return true;
}

//try next position
void tryPos1(int pos)
{
	if(isFind)
		return;

	for(int i=0;i<org.size();i++)
		if(isPrime(org[i]+ring[ring.size()-1])){
			int tmp = org[i];
			ring.push_back(tmp);
			org.erase(org.begin()+i);
				if(pos == 20){
					if(isPrime(ring[ring.size()-1]+ring[0])){
						printVec(ring);
						isFind = true;
					}
					
					ring.pop_back();
					org.insert(org.begin()+i,tmp);
					return;			
				} 
            tryPos1(pos+1);
			ring.pop_back();
			org.insert(org.begin()+i,tmp);
		}
}

void tryPos2(int pos, bool *isUsed)
{
    if(isFind)
        return;

    for(int i=0;i<org.size();i++)
        if((!isUsed[i])&&isPrime(org[i]+ring.back())){
            ring.push_back(org[i]);
            isUsed[i] = true;

            if(20 == pos){
                if(isPrime(ring.back()+ring.front())){
                    printVec(ring);
                    isFind = true;
                }

                ring.pop_back();
                isUsed[i] = false;
                return;
            }

            tryPos2(pos+1,isUsed);
            ring.pop_back();
            isUsed[i] = false;
        }
}

void p4()
{
    const int N = 20;
    bool isUsed[N-1];
    for(int i=1;i<=N;i++){
		org.resize(0);
		ring.resize(0);
		for(int j=1;j<=20;j++)
			if(j != i)
				org.push_back(j);
		ring.push_back(i);

		isFind = false;
        memset((void*)isUsed,false,sizeof(isUsed));
//		tryPos1(2);
        tryPos2(2,isUsed);
	}
}
///////////////problem4 end///////////////////////////

///////////////problem5 start/////////////////////////
/**
 *  problem5 description : Given number from 1 to N,output all possible combinations that contain r numbers
 */

static vector<int> V;
static int size5 = 0;
void combination1(int* s,const int N, const int r)
{
    if(V.size() == (unsigned int)r){
        cout << "#" << ++size5 << " : ";
        printVec(V);
        return;
    }

    for(int i=0;i<N;i++){
        V.push_back(s[i]);

       int* s_ = new int [N-1];
        copyArray(s,i,N,s_);

        combination1(s_,N-1,r);

        V.pop_back();
        delete [] s_;
    }
}

void combination2(int *s, int indexStart, const int N, const int r)
{
    if((unsigned int)V.size() == r){
        cout << "#" << ++size5 << " : ";
        printVec(V);
        return;
    }

    for(int i = indexStart;i<N;i++){
        V.push_back(s[i]);
        combination2(s,i+1,N,r);
        V.pop_back();
    }
}

void p5()
{
    const int N = 10;
    const int r = 9;
    int* data = new int [N];
    for(int i=1;i<=N;i++)
        *(data+i-1) = i;

    combination2(data,0,N,r);

    delete [] data;
}
///////////////problem5 end///////////////////////////

///////////////problem 6 start////////////////////////
/*
 * problem 6 description : decompose a given number to the sum of some numbers that are smaller than itself.
 */

static vector<int> addItems;
int size6 = 0;

void printP6(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for(it=v.begin();it != (v.end()-1);it++)
        cout << *it << "+";
    cout << *it;
    cout << endl;
}

// It's clever to add curMin variable
void decompose(int curMin,const int N,const int goal)
{
    if(sumVec(addItems) == goal){
        cout << "#" << ++size6 << " :";
        cout << goal << " = ";
        printP6(addItems);
        return;
    }

    for(int i=1;i<=N;i++){
        if(i < curMin)
            continue;
        if(i == goal)
            continue;

        addItems.push_back(i);
        decompose(i,N-i,goal);
        addItems.pop_back();
    }
}

void p6()
{
    const int goal = 10;
    int curMin = 0;
    decompose(curMin,goal,goal);
}
///////////////problem 6 end//////////////////////////

///////////////problem 7 start////////////////////////
/*
 *problem 7 dscription : eight queens problem
 */
typedef struct point{
	int x;
	int y;
	point(const int &x_,const int &y_){
		x = x_;y = y_;
	}
}point;

#define COL 8
#define ROW 8

#define N 8
static vector<point> position;
int size7 = 0;
void printP7(const vector<point>& v)
{
    int size = (unsigned int)v.size();
    for(int i=0;i<size;i++)
		cout << "(" << v[i].x << "," << v[i].y << ")";
	cout << endl;
}

bool isPuttable(const point & p)
{
    int size = (unsigned int)position.size();
    for(int i=0;i<size;i++)
		if((position[i].x == p.x)||
		   (position[i].y == p.y)||
		   (abs(position[i].x-p.x) == abs(position[i].y-p.y)))
			return false;
	return true;
}
void putPiece(int n)
{	
	if(n == (N+1)){
		cout << "#" << ++size7 << " :";
		printP7(position);
		return;
	}
	for(int i=1;i<=N;i++)
		if(isPuttable(point(i,n))){
			position.push_back(point(i,n));
			putPiece(n+1);
			position.pop_back();
		}
}

void p7()
{
	putPiece(1);
}

///////////////problem 7 end//////////////////////////

///////////////problem 8 start////////////////////////
/*
*	problem8 description : find all the path from start point to end point in graph.
*/
#define SRC 1
#define DEST 6
#define NODENUM 6

vector<int> path; //path
int pathNum = 0;  // the number of path
int adjacentTable[NODENUM][NODENUM] = {
    {2,3,0,0,0,0},
    {1,3,4,0,0,0},
    {1,2,4,5,0,0},
    {2,3,5,6,0,0},
    {3,4,6,0,0,0},
    {4,5,0,0,0,0}
};

//using recursion
void traverseGraph1(const int &n, bool *hasTraversed)
{
    if(n == DEST){
        cout << "#path " << ++pathNum << " :";
        cout << "1" << " ";
        printVec(path);
        return;
    }

    for(int i=0;adjacentTable[n-1][i] != 0;i++){
        int node = adjacentTable[n-1][i];
        if(!hasTraversed[node-1]){
            path.push_back(node);
            hasTraversed[node-1] = true;
            traverseGraph1(node,hasTraversed);
            path.pop_back();
            hasTraversed[node-1] = false;
        }
    }
}

void p8()
{
    bool hasTraversed[NODENUM] = {true,false};
    traverseGraph1(SRC,hasTraversed);
}
///////////////////problem 8 end/////////////////////

///////////////////problem 9 start///////////////////
/*
 * problem 9 description : partial package problem.
 *                          maximum volumn : M
 *                          the kinds of goods : N
 *                          the weight of every goods : W
 *                          the value of every goods : V
 */
struct item{
    float weight;
    float value;
    item& operator = (const item &s){
        weight = s.weight;
        value = s.value;
        return *this;
    }
};
typedef struct item item;
template <class T>
void qsortM_1(T* array,int l,int r)
{
    if(l >= r)
        return;

    int l_ = l,r_ = r;
    T base = array[l_];
    while(l_ < r_){
        while(l_ < r_){
            if(array[r_] >= base)
                r_--;
            else{
                array[l_] = array[r_];
                l_++;
                break;
            }
        }

        while(l_ < r_){
            if(array[l_] < base)
                l_++;
            else{
                array[r_] = array[l_];
                r_--;
                break;
            }
        }
    }

    array[l_] = base;
    if(r_-1 >= l)
        qsortM_1(array,l,r_-1);
    if(l_+1 <= r)
        qsortM_1(array,l_+1,r);

}

template <class T>
void qsortM_2(T* array,int l,int r)
{
    if(l>=r)
        return;

    int l_ = l,r_ = r;
    T base = array[l_];
    while(l_<r_){
        while(array[r_] > base)
            r_--;
        if(l_>=r_)
            break;
        array[l_] = array[r_];
        l_++;

        while(array[l_] < base)
            l_++;
        array[r_] = array[l_];
        r_--;
    }

    array[l_] = base;
    if(l_-1 >= l)
        qsortM_2(array,l,l_-1);
    if(r_+1 <= r)
        qsortM_2(array,r_+1,r);
}

void qsortItems(item goods[], int l,int r)
{
    if(l >= r)
        return;

    int l_ = l,r_ = r;
    item base = goods[l_];

    while(l_ < r_){
        while(l_ < r_){
            if(goods[r_].value > base.value){
                goods[l_] = goods[r_];
                l_++;
                break;
            }
            else
                r_--;
        }

        while(l_ < r_){
            if(goods[l_].value < base.value){
                goods[r_] = goods[l_];
                r_--;
                break;
            }
            else
                l_++;
        }
    }

    goods[l_] = base;

    if(r_-1 >= l)
        qsortItems(goods,l,r_-1);
    if(l_+1 <= r)
        qsortItems(goods,l_+1,r);
}

void sortItems(item goods[],const int nGoods)
{
    qsortItems(goods,0,nGoods-1);
}

void partialPackage(float maxVol,item goods[],const int nGoods)
{
    sortItems(goods,nGoods);

    int totalValue = 0;
    float *chooseWeight = new float [nGoods];
    memset(chooseWeight,0,sizeof(chooseWeight));
    for(int i=0;(i<nGoods)&&(maxVol>=0);i++){
        maxVol -= goods[i].weight;
        if(maxVol >= 0){
            chooseWeight[i] = goods[i].weight;
            totalValue += (goods[i].weight*goods[i].value);
        }
        else{
            chooseWeight[i] = goods[i].weight+maxVol;
            totalValue += (goods[i].weight+maxVol)*goods[i].value;
        }
    }

    cout << "partial package problem best solution : " << endl;
    for(int i=0;(i<nGoods)&&(fabs(chooseWeight[i])>1e-3);i++)
        cout << "price : " << goods[i].value
             << "      "
             << "weight :" << chooseWeight[i]<< endl;
    cout << "total value : " << totalValue << endl;

    delete [] chooseWeight;
}

void p9()
{
    const float maxVol = 80;
    const int nGoods = 10;
    item goods[nGoods] = {{8,2},{9,4},{12,1.5},{6,4},{15,1.4},{20,0.6},{5,3},{6,1},{11,2.5},{22,1.6}};

    partialPackage(maxVol,goods,nGoods);
}

///////////////////problem 9 end/////////////////////

///////////////////problem 10 start//////////////////
/*
 *  problem 10 description :
 */

int* readDataFromFile(const string& fileName,int &nHeap)
{
    fstream fin;
    fin.open(fileName.c_str());
    if(!fin.is_open()){
        cout << "can not open " << fileName << endl;
        return NULL;
    }

    int *nCards; //save data in this array
    try{
        fin >> nHeap; // read the number of data
        nCards = new int [nHeap]; // dynamically allocate memory for data, remeber to deallocate memory
        int i = 0;

        while(!fin.eof())
            fin >> (nCards[i++]);

        if(i != nHeap+1)
            throw "data number is not enough, i != nHeap";
        }
    catch(const char* s){
        cout << s << endl;
        return NULL;
    }
    fin.close();

    return nCards;
}

///////////////////problem 10 end////////////////////

///////////////////problem 11 start//////////////////
/*
 * problem 11 description : input a date, output the week information
 */
const string calWeekDay(int year, int month, int day)
{
	const string week[] = {"sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	
	int preYear = year - 1; 
	int modY = preYear+preYear/4-preYear/100+preYear/400;//(year-1)-((year-1)/4-(year-1)/100+(year-1)/400),
	int modM = 0;
	switch (month) {
	case 1 :
	case 10 :
		modM = 0;
		break;
	case 5 :
		modM = 1;
		break;
	case 2 :
	case 3 :
	case 11 :
		modM = 3;
		break;
	case 4 :
	case 7 :
		modM = 6;
		break;
	case 6 :
		modM = 4;
		break;
	case 8 :
		modM = 2;
		break;
	case 9 :
	case 12 :
		modM = 5;
		break;
	default :
		break;
	}
	
	if((((year%4 == 0)&&(year%100 !=0))||(year%400 == 0))&&(month > 2)) // decide whether this year is a leap year
		modM += 1;
	return week[(modY+modM+day)%7];
}


void p11(int argc, char* argv[])
{
	if(argc != 4){
		cout << " Usage : [program] [year] [month] [day]" << endl;
		return;
	}

	int year = atoi(argv[1]);
	int month = atoi(argv[2]);
	int day = atoi(argv[3]);

	if(year < 0 || month <= 0||month > 12||day <= 0 ||day >31){
		cout << "input error" << endl;
		return;
	}

	string weekDay = calWeekDay(year,month,day);
	cout << weekDay << endl;
}
///////////////////problem 11 end////////////////////

void p12()
{
    const char *s[] = {"black", "white", "pink", "violet"};
    const char **ptr[] = {s+3, s+2, s+1, s}, ***p;
    p = ptr;
    ++p;
    printf("%s", **p+1);
}

/////////////////////////////////////////////////////////

////////////////problem 13 start/////////////////
/* problem description : longest common subsequence(LCS)
 */
/**
 * @brief LCS_length compute  longest common subsequence(LCS)
 * @param X A sequence
 * @param Y another sequence
 * @param C c[i][j] means the length of LCS of Xi and Yj
 * @param B b[i][j] means which sub-problem c[i][j] chooses to make c[i][j] longget
 *
 * For B, U means uo,D means diagnose, L means left
 */

#define FOR(END,i,START) for(int i=START;i<END;i++)

int LCS_length(const char* X,const char* Y,char* lcs)
{
    assert(X != NULL && Y != NULL);
    const int lenX = strlen(X);
    const int lenY = strlen(Y);

    int **C;
    char** B;
    int len = 0;

    C = (int**)malloc((lenX+1)*sizeof(int*));
    if(C == NULL){
        perror("alloc memory error\n");
        exit(-1);
    }

    FOR(lenX+1,i,0)
            C[i] = (int*)malloc(sizeof(int)*(lenY+1));

    B = (char**)malloc((lenX+1)*sizeof(char*));
    if(B == NULL){
        perror("alloc memory error\n");
        exit(-1);
    }

    FOR(lenX+1,i,0)
        B[i] = (char*)malloc(sizeof(char)*(lenY+1));

    FOR(lenX+1,i,0)
        C[i][0] = 0;
    FOR(lenY+1,i,0)
        C[0][i] = 0;

    FOR(lenX+1,i,1)
        FOR(lenY+1,j,1)
            if(X[i-1] == Y[j-1]){
        C[i][j] = C[i-1][j-1]+1;
        B[i][j] = 'D';
    }
    else if(C[i-1][j] >= C[i][j-1]){
        C[i][j] = C[i-1][j];
        B[i][j] = 'U';
    }
    else{
        C[i][j] = C[i][j-1];
        B[i][j] = 'L';
    }

    len = C[lenX][lenY];

/*    FOR(lenX+1,i,0){
        FOR(lenY,j,0)
                printf("%d ",C[i][j]);
        printf("\n");
    }
*/

    {
        lcs[len] = '\0';

        int i = lenX,j = lenY;
        int k = len-1;
        while(i != 0 & j != 0){
            if(B[i][j] == 'D'){
                i--;
                j--;
                lcs[k--] = X[i];
            }

            if(B[i][j] == 'U')
                i--;
            if(B[i][j] == 'L')
                j--;
        }
    }


    FOR(lenX+1,i,0){
            free(C[i]);
            free(B[i]);
    }

    free(C);
    free(B);

    return len;
}


void p13()
{
    const char X[] = "ABCBDAB";
    const char Y[] = "BDCABA";

    int minLen = strlen(X) > strlen(Y) ? strlen(X) : strlen(Y);
    char* lcs = (char*)malloc(sizeof(char)*(minLen+1));

    int len = LCS_length(X,Y,lcs);

    printf("the length of LCS : %d\n",len);
    printf("LCS : %s\n",lcs);

    free(lcs);
}


////////////////problem 13 end //////////////////
int main(int argc,char* argv[])
{
    p13();
	return 0;
}
