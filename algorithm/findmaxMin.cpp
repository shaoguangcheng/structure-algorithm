#include <iostream>

using namespace std;

template <typename T>
void findMaxMin(const T* array, int size, T& maxNumber, T& minNumber){
    if(array == NULL || size == 0){
        return;
    }

    if(size == 1){
        maxNumber= minNumber= *array;
        return;
    }
        
    maxNumber = array[0] >  array[1] ? array[0] : array[1];
    minNumber = array[0] <= array[1] ? array[0] : array[1];

    T tmpMax, tmpMin;
    for(int i = 2; (i + 1) < size; i += 2){
        if(array[i] > array[i+1]){
            tmpMax = array[i];
            tmpMin = array[i+1];
        }
        else{
            tmpMax = array[i+1];
            tmpMin = array[i];
        }

        if(maxNumber < tmpMax)
            maxNumber= tmpMax;
        if(minNumber > tmpMin)
            minNumber = tmpMin;
    }

    if(size%2 != 0){
        if(array[size-1] > maxNumber)
            maxNumber = array[size-1];
        else if(array[size-1] < minNumber)
            minNumber = array[size-1];
    }
}

int main()
{
    int array[11] = {2,1,2,13,4,4,2,1,-1,89, -100};
    int m,n;

    findMaxMin(array, 11, m, n);
    cout << m << " " << n << endl;
}