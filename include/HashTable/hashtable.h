#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class hashtable
{
 public:
  hashtable();
  ~hashtable();
  int Index(const string &);
  int numberOfItems(int);
  void add(string, T);
  void printTable();
  void printItem(int);
  bool keyExists(string);
  bool removeItem(string);
  void rehash();
  int tableSize();

 protected:
 private:
  struct item {
    string key;
    T value;
    item *next;
    item *bucket;
  };
  item **table;
  static int entries;
  static const float loadFactor = 0.7;
  static int tsize;
};

template <typename T>
int hashtable<T>::entries = 0;

template <typename T>
int hashtable<T>::tsize = 10;

template <typename T>
hashtable<T>::hashtable()
{
  table = new item *[tsize];
  for (int i = 0; i < tsize; i++) {
    table[i] = new item;
    table[i]->bucket = NULL;  // pointer for each index of the table
    table[i]->next =
        NULL;  // pointer for the next element of the index in the linked list
  }
}

template <typename T>
hashtable<T>::~hashtable()  // deletes all pointers
{
  for (int i = 0; i < tsize; i++) {
    if (table[i]->bucket != NULL) {
      item *p = table[i];
      while (p != NULL) {
        item *temp;
        temp = p;
        p = p->next;
        delete temp;
      }
    }
  }
  delete[] table;
}

template <typename T>
void hashtable<T>::add(string key, T value)  // adds element in the hashtable
{
  int index = Index(key);
  if (table[index]->bucket ==
      NULL)  // if the node in the index is empty put the element there,
  {          // otherwise set it as the next element in the linked list
    table[index]->key = key;
    table[index]->value = value;
    table[index]->bucket = table[index];
  } else {
    item *p = new item;
    p->key = key;
    p->value = value;
    p->next = table[index]->next;
    table[index]->next = p;
  }
  entries++;
  if ((entries / tsize) >=
      loadFactor)  // if the entries are too many (considering the load factor),
                   // call rehash
  {
    rehash();
  }
}

template <typename T>
int hashtable<T>::Index(
    const string &key)  // find the index where the element should be inserted
{
  int sum = 0;
  for (unsigned int i = 0; i < key.length(); i++) { sum = (sum + (int)key[i]); }
  return sum % tsize;
}

template <typename T>
int hashtable<T>::numberOfItems(
    int index)  // finds the number of items inside a bucket (=elements with the
                // same index)
{
  int n;
  if (table[index]->bucket != NULL) {
    n = 1;
    item *p = table[index]->next;
    while (p != NULL) {
      n++;
      p = p->next;
    }
  } else {
    n = 0;
  }
  return n;
}

template <typename T>
void hashtable<T>::printTable()  // prints table- for debugging purposes mostly
{
  for (int i = 0; i < tsize; i++) {
    cout << endl << "index " << i << endl;
    cout << "key: " << table[i]->key << endl;
    cout << "value: " << table[i]->value << endl;
    cout << "number of items in this index: " << numberOfItems(i) << endl
         << endl;
  }
}

template <typename T>
void hashtable<T>::printItem(
    int index)  // prints items (key,value) in a bucket- debugging purposes
{
  if (table[index]->bucket == NULL) {
    cout << "no items yet" << endl;
  } else {
    int counter = 1;
    item *p = table[index];
    while (p != NULL) {
      cout << endl
           << counter << ") key: " << p->key << "  value: " << p->value << endl;
      counter++;
      p = p->next;
    }
  }
}

template <typename T>
bool hashtable<T>::keyExists(
    string key)  // searches if the key given exists in the hashtable
{
  int index = Index(key);
  item *p = table[index];
  bool found = false;
  if (table[index]->bucket != NULL) {
    while (p != NULL) {
      if (p->key == key) {
        found = true;
      }
      p = p->next;
    }
  }
  return found;
}

template <typename T>
bool hashtable<T>::removeItem(
    string key)  // deletes the items with the key given
{
  int index = Index(key);
  item *temp;
  bool removed = false;
  if (table[index]->bucket != NULL)  // deletes the first element if it has the
                                     // key given and replaces it
  {  // with the next in the list and checks again.
    while (table[index]->key == key) {
      temp = table[index];
      if (table[index]->next == NULL) {  // if there is no next element, set the
                                         // bucket pointer to null
        table[index]->bucket = NULL;
      }
      table[index] =
          table[index]
              ->next;  // set the table pointer to point to the next element
      delete temp;
      removed = true;
    }
    item *p = table[index]->next;
    item *pre = table[index];
    while (p != NULL)  // searches in the rest linked list to find if there are
                       // any more elements with that key
    {
      if (p->key == key) {
        temp = p;
        p = p->next;
        pre->next = p;
        delete temp;
        removed = true;
      } else {
        pre = p;
        p = p->next;
      }
    }
  }
  return removed;
}

template <typename T>
void hashtable<T>::rehash()  // makes a new array double the size of the old
                             // one, calculates again the index of each element
{  // and places them in the new hashtable. Finally, it gets rid of the old one.
  int oldTableSize = tsize;
  tsize = 2 * oldTableSize;
  item **oldTable = table;
  table = new item *[tsize];
  for (int i = 0; i < tsize; i++) {
    table[i] = new item;
    table[i]->bucket = NULL;
    table[i]->next = NULL;
  }
  for (int i = 0; i < oldTableSize; i++) {
    if (oldTable[i]->bucket != NULL) {
      item *p = oldTable[i];
      while (p != NULL) {
        int index = Index(p->key);
        if (table[index]->bucket == NULL) {
          table[index]->key = p->key;
          table[index]->value = p->value;
          table[index]->bucket = table[index];
        } else {
          item *k = new item;
          k->key = p->key;
          k->value = p->value;
          k->next = table[index]->next;
          table[index]->next = k;
        }
        p = p->next;
      }
    }
  }
  delete[] oldTable;
}

template <typename T>
int hashtable<T>::tableSize()
{  // return the size of the table
  return tsize;
}

#endif  // HASHTABLE_H
