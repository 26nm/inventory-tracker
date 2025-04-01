#ifndef HISTORY_H
#define HISTORY_H

/**
 * History - a class responsible for retrieving and displaying a Customer's transaction history.
 *
 * The History class is designed to track all transactions that a customer has made, 
 * such as borrowing or returning movies. It provides functionality to look up a customer 
 * by their unique ID and display a chronological list of all recorded transactions.
 * This class helps maintain an organized record of customer activities, 
 * ensuring that their transaction history can be easily accessed and reviewed when needed.
 *
 * Nolan Dela Rosa
 * 
 * August 13, 2024
 */
#include "Transaction.h"
#include "HashTable.h"
#include "Customer.h"
using namespace std;

class MovieTree;

class History : public Transaction {

public:
  History();
  History(char, char, int);
  virtual void execute(MovieTree &, HashTable &) override;
  virtual ~History();
};
#endif // HISTORY_H