#ifndef RETURN_H
#define RETURN_H

/**
 * Borrow - a subclass of Transaction that represents a transaction for returning a movie.
 * This class is derived from the base Transaction class and is used to manage and track
 * the process of returning movies. It extends the functionality of the base class by 
 * implementing the `execute` method, which updates the state of the `HashTable` to reflect
 * that a movie has been returned, including increasing its available stock.
 *
 * Nolan Dela Rosa
 * 
 * August 13, 2024
 */
#include "Transaction.h"
#include "MovieTree.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class Return : public Transaction {
private:
  char mediaType;
  string attribute1;
  string attribute2;

public:
  Return();
  Return(char, int, char, char, const string &, const string &);
  virtual void execute(MovieTree &, HashTable &) override;
  virtual ~Return();
};
#endif // RETURNH 