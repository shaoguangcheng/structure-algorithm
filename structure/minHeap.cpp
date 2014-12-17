
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class minHeap{
private :
  T* array;
  int nElem;
  int nRealElem;

public :
  minHeap() : array(NULL), nElem(0), nRealElem(0){}
  minHeap(int N) : array(new T [N+1]), nElem(N), nRealElem(0){}
  minHeap(T* array_, int N);
  ~minHeap(){if(array != NULL) delete [] array;}

  void insert(const T &x);
  void del(int index);
  T getMin() const;
  void size() const;
  T* sort();
  void print() const;

  int left(int index) const;
  int right(int index) const;
  int parent(int index) const;

private :
  void heapify(int index);
  void buildHeap();
};

////////////////////////////////////////////////////////////
template <typename T>
minHeap<T>::minHeap(T* array_, int N)
 : array(new T [N+1]), nElem(N), nRealElem(N)
{
  for(int i = 0; i < N; ++i)
    array[i+1] = array_[i];

  buildHeap();
}

template <typename T>
void minHeap<T>::insert(const T& x)
{
  if(nRealElem >= nElem){
    cout << "array is full" << endl;
    return;
  }

  nRealElem++;
  array[nRealElem] = x;

  for(int i = nRealElem; i > 1&&array[parent(i)] > array[i]; i = parent(i)){
    array[i] = array[parent(i)];
    array[parent(i)] = x;
  }
}

template <typename T>
void minHeap<T>::print() const
{
  for(int i = 1; i <= nRealElem; ++i)
    cout << array[i] << " ";
  cout << endl;
}

template <typename T>
int minHeap<T>::left(int index) const
{
  return index << 1;
}

template <typename T>
int minHeap<T>::right(int index) const
{
  return index << 1 + 1;
}

template <typename T>
int minHeap<T>::parent(int index) const 
{
  return index >> 1;
}

////////////////////////////////////////////////////////////
template <typename T>
void minHeap<T>::heapify(int index)
{
  int leftIndex = left(index);
  int rightIndex = right(index);
  
  int tmpIndex;
  if(leftIndex <= nRealElem)
  	tmpIndex = array[index] < array[leftIndex] ? index : leftIndex;
  if(rightIndex <= nRealElem)
    tmpIndex = array[tmpIndex] < array[rightIndex] ? tmpIndex : rightIndex;
  
  if(tmpIndex != index){
    swap(array[tmpIndex], array[index]);
    heapify(tmpIndex);
  }
}

template <typename T>
void minHeap<T>::buildHeap()
{
  for(int i = nRealElem/2; i > 0; --i)
    heapify(i);
}


int main()
{
  minHeap<int> h(5);

  h.insert(53);
  h.insert(23);
  h.insert(6);
  h.insert(43);
  h.insert(32);
  h.insert(22);

  h.print();

  int array[6] = {2,1,4,3,6,5};
  minHeap<int> hh(array, 6);
  hh.print();

  return 0;
}
