#include <cstdlib> 
#include <iostream>
#include <string>
using namespace std;

template <class T>
class HashTable {
public:
  HashTable();
  HashTable(int);
  HashTable(const HashTable &h);
  ~HashTable();
  HashTable& operator = (const HashTable &h);

  void ShowFill(ostream& os) const;
  void ShowContents(ostream& os) const;
  int Insert(T data);
  int Remove(T data);
  int Search(T data);
  int NewSlot(T HashVal, int trynumber);

  void Clear();
private:
  int size;
  T * data;
};

template <class T>
HashTable<T>::HashTable() {
  size = 7;
  data = (T*)malloc(size*sizeof(T));
  for(int i = 0; i < size; i++) {
    data[i] = NULL;
  }
}

template <class T>
HashTable<T>::HashTable(int x) {
  x = x*2;
  for (x; (x%2 == 0 || x%3 == 0); x++);
  //std::cout << x << std::endl;
  //while 
  size = x;
  data = (T*)malloc(size*sizeof(T));
  for(int i = 0; i < size; i++) {
    data[i] = NULL;
  }
}

template <class T>
HashTable<T>::HashTable(const HashTable &h) {
    data = (T*)malloc(sizeof(T)*h.size);
 
    memcpy(data, h.data, sizeof(T)*h.size);
    size = h.size;
}

template <class T>
HashTable<T>::~HashTable() {
  if (data) 
  { 
    free(data);
    data = NULL;
  } 
  size = 0;
}

template <class T>
HashTable<T>& HashTable<T>::operator = (const HashTable &h) {
  if (this == &h) // in case somebody tries assign array to itself  
    return *this;
 
  if (h.size == 0) // is other array is empty -- clear this array  
    Clear();
 
  size = h.size; // set size  
 
  memcpy(data, h.data, sizeof(T)*h.size);
 
  return *this;
}


template <class T>
void HashTable<T>::ShowFill(ostream& os) const {
  for(int i = 0; i < size; i++) {
    os << i << ":\t";
    if (data[i])
      os << data[i] << endl;
    else
      os << "NULL" << endl;
  }
}

template <class T>
void HashTable<T>::ShowContents(ostream& os) const {
  for(int i = 0; i < size; i++) {
    if (data[i]) {
      os << data[i] << "\t ";
    }
  }
}

template <class T>
int HashTable<T>::Insert(T key) {

  int i = key%size;
  int hits = i;
  if (data[i])
    i = NewSlot(key, ++i);
  else
    data[i] = key;

  if (i == size) // Ow, A little part of me died writing this.
    return size+1;
  else if (i == hits)
    return 1;
  else if (i > hits)
    return (i-hits)+1;
  else if (i < hits)
    return ((size-hits)+i)+1;
  else return 0;
}

template <class T>
int HashTable<T>::Remove(T key) {
  int i = Search(key);
  if (i != NULL) {
    data[i] = NULL;
    return i;
  } else {
    return NULL;
  }
}

template <class T>
int HashTable<T>::Search(T key) {
  int i = key%size;
  if (key == data[i])
    return i;
  else {
    for(int tmp = (i+1); tmp != i; tmp++) {
      if (tmp == size)
        tmp = tmp - size;

      if (key == data[tmp])
        return tmp;
    }
    return NULL;
  }
}

template <class T>
int HashTable<T>::NewSlot(T HashVal, int trynumber) {
  int i = trynumber + 1;

  if (trynumber == size)
    trynumber = 0;

  i = HashVal%size;
  if (trynumber == i) {
    return 8;
  }

  if (data[trynumber])
    trynumber = NewSlot(HashVal,  ++trynumber);
  else
    data[trynumber] = HashVal;

  return trynumber;
}

template <class T>
void HashTable<T>::Clear() { 
	data = (T*)realloc(data, sizeof(T)*size);  
  size = 0;
} 