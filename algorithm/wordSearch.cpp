/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring.
 The same letter cell may not be used more than once.
*/

 #include <iostream>
 #include <string>
 #include <stack>

 using namespace std;

 struct point
 {
 	int x;
 	int y;
 	point(int x, int y) : x(x), y(y){}
 };
 bool exist(vector<vector<char> > &board, string word) {
 	int nRow = board.size(), nCol = board[0].size();
 	int nChar = word.size();

 	int tmp[4][2] = {{-1, 0},
 					{0, 1},
 					{1, 0},
 					{0,-1}};

 	int i = 0, j = 0, k = 0, r = 0;

 	point p;
	stack<point> s;
	bool **visited = new bool [nRow];
	for(int i = 0; i < nRow; ++i)
		visited[i] = new bool[nCol];
	for(int i = 0; i < nRow; ++i)
		for(int j = 0; j < nCol; ++j)
			visited[i][j] = false;

 	while(i < nRow && j < nCol){
 		if(word[k] == board[i][j]){
 			++k;
 			s.push(point(i, j));
 			visited[i][j] = true;
 			while(!s.empty()){
 				p = s.top();
 				s.pop();
 				visited[p.x][p.y] = false;

 				int iTmp = p.x, jTmp = p.y;
 				while(r < 4){
 					iTmp += tmp[r][0];
 					jTmp += tmp[r][1];
 					if(iTmp < 0 || iTmp >= nRow || jTmp < 0 || jTmp >= nCol){
 						++r;
 						continue;
 					}

 					if(word[k] == board[iTmp][jTmp]){
 						if(k == nChar)
 							return true;
 						else{
 							s.push(point(iTmp, jTmp));
 							visited[iTmp][jTmp] = true;
 							++k;
 						}
 					}
 					else
 						++r;
 				}
 			}
 		}
 		else{
 			++j;
 			if(j >= nCol){
 				++i;
 				j = 0;
 			}
 		}
 	}

 	return false;
}

int main()
{
	char s1[] = "ABCE", s2[] = "SFCS", s3[] = "ADEE";

	vector<char> c1(s1, s1+4);
	vector<char> c2(s2, s2+4);
	vector<char> c3(s3, s3+4);

	vector<vector<char> > board;
	board.push_back(c1);
	board.push_back(c2);
	board.push_back(c3);

	string s("ABCCED");

	cout << exist(board, s) << endl;		
} 