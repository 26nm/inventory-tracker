#ifndef TRANSACTION_H
#define TRANSACTION_H

/**
 * Transaction - Abstract base class for representing various types of transactions.
 * 
 * This class provides a common interface and shared attributes for different 
 * transaction types, such as borrowing and returning movies. It includes
 * attributes for customer ID, media type, movie type, and movie title, and 
 * declares a pure virtual function `execute()` that must be implemented by
 * derived classes to perform the specific actions associated with the transaction.
 * 
 * Nolan Dela Rosa
 * 
 * August 12, 2024
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "HashTable.h"
#include "Customer.h"
using namespace std;

class MovieTree;
class HashTable;

class Transaction {
public:
  Transaction();
  Transaction(char, char, int);
  char getGenreOfMovie() const;
  char getTransType() const;
  int getCustomerID() const;
  virtual void execute(MovieTree &, HashTable &) = 0;
  virtual ~Transaction();

protected:
  char transType;
  char genreOfMovie;
  int customerID;
};

#endif // TRANSACTION_H