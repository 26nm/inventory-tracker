#ifndef STORE_H
#define STORE_H

/**
 * Store - a class responsible for processing data from .txt files.
 * 
 * This class handles the reading and parsing of .txt files containing movie,
 * command, and customer data. It organizes the information into appropriate 
 * data structures such as hash tables and trees, and facilitates the creation 
 * of transactions based on parsed commands.
 * 
 * It provides methods for initializing and populating the movie inventory and 
 * customer database, as well as for managing transactions through commands 
 * specified in the input files.
 * 
 * Nolan Dela Rosa
 * 
 * August 14, 2024
 */
#include "Movie.h"
#include "MovieTree.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Transaction.h"
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
#include "HashTable.h"
#include "MovieFactory.h"
#include "TransactionFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Store {
public:
  Store();
  ~Store();
  bool loadData(const string &, const string &, const string &);
  void processTransactions();

private:
  MovieTree classicTree;
  MovieTree comedyTree;
  MovieTree dramaTree;
  HashTable customers;
  vector<Transaction*> transactions;

  void parseMovieData(const string &);
  Customer* parseCustomerData(const string &);
  Transaction* parseTransactionData(const string &);
  Transaction* parseBorrowOrReturnTransaction(istringstream &, char, int, char, char);
  string trim(const string &);
  bool parseClassicMovies(int, const string &, const string &, const string &);
  bool readMovies(const string &);
  bool readTransactions(const string &);
  bool readCustomers(const string &);
  void cleanup();

};
#endif // STORE_H