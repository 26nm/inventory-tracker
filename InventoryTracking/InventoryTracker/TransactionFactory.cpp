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
#include "TransactionFactory.h"
using namespace std;

/** 
 * Creates and returns a new Transaction object based on the provided transaction code and parameters.
 * The method supports various transaction types including Borrow, History, Inventory, and Return. 
 * Depending on the transaction code, it initializes the respective transaction object with the given 
 * parameters or returns an error message for unknown transaction codes.
 *
 * @param trans         A character representing the type of transaction ('B' for Borrow, 'H' for History,
 *                      'I' for Inventory, 'R' for Return).
 * @param customerID    An integer representing the ID of the customer involved in the transaction.
 * @param mediaType     A character representing the type of media involved (e.g., 'D' for DVD, 'F' for Film).
 * @param movieType     A character representing the type of movie (e.g., 'C' for Comedy, 'D' for Drama).
 * @param attribute1    A string representing additional attribute 1 relevant to the transaction (e.g., movie title).
 * @param attribute2    A string representing additional attribute 2 relevant to the transaction (e.g., actor name).
 * 
 * @return A pointer to the created Transaction object, or nullptr if the transaction code is unknown.
 */
Transaction* TransactionFactory::createTransaction(char trans, 
  int customerID, char mediaType, char movieType, 
  const string &attribute1, const string &attribute2) {
  if(trans == 'B') {
    return new Borrow(trans, customerID, mediaType, 
      movieType, attribute1, attribute2);

  } else if(trans == 'H') {
      return new History(trans, movieType, customerID);

  } else if(trans == 'I') {
      return new Inventory(trans, ' ', 0);

  } else if(trans == 'R') {
      return new Return(trans, customerID, mediaType,
        movieType, attribute1, attribute2);

  } else {
      cout << "Error: unknown transaction code " << trans << "." << endl;
      return nullptr;
  }
}