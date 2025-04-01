#ifndef HASHTABLE_H
#define HASHTABLE_H

/**
 * HashTable - A custom hash table implementation for storing and managing Customer objects.
 * 
 * This class uses a hash table to efficiently handle Customer data with operations
 * for inserting, retrieving, and removing customers based on their unique ID numbers.
 * 
 * Nolan Dela Rosa
 * 
 * August 12, 2024
 */
#include <list>
#include "Customer.h"
using namespace std;

class HashTable {
public:
  HashTable(int size = 101);
  void clear();
  void insert(Customer*);
  bool remove(int);
  Customer* get(int) const;
  ~HashTable();

private:
  int tableSize;
  list<Customer*>* table;
  int hash(int) const;
};

#endif // HASHTABLE_H