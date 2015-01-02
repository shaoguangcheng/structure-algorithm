// Dijistra.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <limits>

const int N = 5;

template <typename T>
void dijistra(T weight[N][N], int v0, T** dist, int** path)
{
	*dist = new T[N]{INT_MAX};
	*path = new int[N];

	bool S[N] = {false};

	for (int i = 0; i < N; ++i){ 
		(*dist)[i] = weight[v0][i];
		if ((*dist)[i] < INT_MAX)
			(*path)[i] = v0;
		else
			(*path)[i] = -1;
	}
	
	int u = v0;
	S[v0] = true;

	for (int i = 1; i < N; ++i){
		int minDist = INT_MAX;
		int j;
		for (int k = 0; k < N; ++k){
			if (!S[k] && weight[u][k] < minDist){
					j = k;
					minDist = (*dist)[k];
			}
		}

		u = j;
		S[u] = true;

		for (int k = 0; k < N; ++k){
			if (!S[k] && weight[u][k] < INT_MAX && (*dist)[u] + weight[u][k] < (*dist)[k]){
				(*dist)[k] = (*dist)[u] + weight[u][k];
				(*path)[k] = u;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int weight[N][N] = {
				0,100, 30, INT_MAX, 10,
				INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX,
				INT_MAX, 60, 0, 60, INT_MAX,
				INT_MAX, 10, INT_MAX, 0, INT_MAX,
				INT_MAX, INT_MAX, INT_MAX, 50, INT_MAX
				};

	int* dist = NULL;
	int *path = NULL;

	dijistra(weight, 0, &dist, &path);

	for (int i = 0; i < N; ++i){
		std::cout << dist[i] << " " << std::endl;
	}

	return 0;
}

