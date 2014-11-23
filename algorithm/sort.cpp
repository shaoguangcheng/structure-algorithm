#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// bubble sort
// O(n^2), extra space O(1), stable sort, in-place sort
template <typename T>
void bubbleSort(T* array, int N)
{
    if(NULL == array || 0 == N)
        return;

    T tmp;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N - i -1; ++j){
            if(array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

// insertion sort
// O(n^2), extra space O(1), stable sort, in-place sort
template <typename T>
void insertionSort(T* array, int N)
{
    if(array == NULL || N == 0)
        return;

    T tmp;
    for(int i = 1; i < N; i++){
        for(int j = i; j >=1; j--){
            if(array[j] < array[j-1]){
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
            else{
                break;
            }
        }
    }
}

// quick sort
// averge time complicity O(nlgn), unstable sort,
template <typename T>
void quickSortMain(T* array, int left, int right)
{
    if(left >= right)
        return;

    int l = left+1, r = left+1;
    T pivot = array[left];

    while(r <= right){
        if(array[r] < pivot){
            T tmp = array[r];
            array[r] = array[l];
            array[l] = tmp;
            ++l;
        }
        ++r;
    }

    if(l > 0){
        array[left] = array[l-1];
        array[l-1] = pivot;
    }
    quickSortMain(array, left, l-2);
    quickSortMain(array, l, right);
}

template <typename T>
void quickSort(T* array, int N)
{
    if(array == NULL || 0 == N)
        return;

    quickSortMain(array, 0, N-1);
}

// merge Sort
// O(nlgn), extra space O(n), stable sort
template <typename T>
void merge(T* array, int first, int mid, int last, int tmp[])
{
    int i = first, j = mid+1;
    int k = 0;
    while(i <= mid && j <= last){
        if(array[i] <= array[j]){
            tmp[k++] = array[i++];
        }
        else{
            tmp[k++] = array[j++];
        }
    }

    while(i <= mid){
        tmp[k++] = array[i++];
    }

    while(j <= last){
        tmp[k++] = array[j++];
    }

    for(int i = 0; i < k; ++i){
        array[first+i] = tmp[i];
    }
}

template <typename T>
void mergeSortMain(T* array, int first, int last, int tmp[])
{
    if(first >= last)
        return;

    int mid = (first + last)/2;

    mergeSortMain(array, first, mid, tmp);
    mergeSortMain(array, mid+1, last, tmp);
    merge(array, first, mid, last, tmp);
}

template <typename T>
void mergeSort(T* array, int N)
{
    if(NULL == array || 0 == N)
        return;

    T* tmp = new T [N];

    mergeSortMain(array, 0, N-1, tmp);

    delete [] tmp;
}

// print elements
template <typename T>
void printArray(T* array, int N){
    for(int i = 0; i < N; ++i){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{

    int array[20000];
    srand((unsigned int)(time(NULL)));
    for(int i = 0; i < 20000; ++i)
        array[i] = rand()%RAND_MAX;

    clock_t start = clock();
    insertionSort(array, 20000);
    clock_t end = clock();
    cout << "insertion sort : " << (end - start) << endl;

    start = clock();
    quickSort(array, 20000);
    end = clock();
    cout << "quick sort : " << (end - start) << endl;

    start = clock();
    mergeSort(array, 20000);
    end = clock();
    cout << "merge sort : " << (end - start) << endl;

    start = clock();
    bubbleSort(array, 20000);
    end = clock();
    cout << "bubble sort : " << (end - start) << endl;
}
