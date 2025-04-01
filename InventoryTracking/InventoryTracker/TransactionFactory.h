#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

/**
 * TransactionFactory - A utility class responsible for creating instances of Transaction objects.
 * 
 * This class provides a static method to generate specific types of Transaction objects based on
 * a given command type. It centralizes the instantiation logic for different transaction types,
 * making it easier to manage and extend the types of transactions supported by the application.
 * 
 * Nolan Dela Rosa
 * 
 * August 13, 2024
 */
#include "Transaction.h"
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
using namespace std;

class TransactionFactory {
public:
  static Transaction* createTransaction(char, int, char, char, 
    const string &, const string &);
};
#endif // TRANSACTIONFACTORY_H
