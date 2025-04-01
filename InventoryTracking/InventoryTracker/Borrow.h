#ifndef BORROW_H
#define BORROW_H

/**
 * Borrow - a subclass of Transaction that represents a transaction for borrowing a movie.
 * This class is derived from the base Transaction class and is used to manage and track
 * the process of borrowing movies. It extends the functionality of the base class by 
 * implementing the `execute` method, which updates the state of the `HashTable` to reflect
 * that a movie has been borrowed, including decreasing its available stock.
 *
 * Nolan Dela Rosa
 * 
 * August 12, 2024
 */
#include "Transaction.h"
#include "MovieTree.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class Borrow : public Transaction {
private:
  char mediaType;
  string attribute1;
  string attribute2;

public:
  Borrow();
  Borrow(char, int, char, char, const string &, const string &);
  virtual void execute(MovieTree &, HashTable &) override;
  virtual ~Borrow();
};
#endif // BORROW_H