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
#include "Transaction.h"
using namespace std;

/**
 * Default constructor for the Transaction class.
 * 
 * Initializes a Transaction object with a default value:
 * - transType: ' ' (empty space)
 */
Transaction::Transaction() 
  : transType(' '), genreOfMovie(' '),
    customerID(0) {
}

/**
 * Parameterized constructor for the Transaction class.
 * 
 * Initializes a Transaction object with the given values:
 * @param trans  The transaction type being made.
 */
Transaction::Transaction(char trans, char genre, int ID)
  : transType(trans), genreOfMovie(genre),
    customerID(ID) {
}

/**
 * Return this transaction's code.
 * 
 * @return The transaction type, as a char.
 */
char Transaction::getTransType() const {
  return transType;
}

/**
 * Return the ID for Customer involved in this
 * transaction.
 * 
 * @return An int representing the Customer's ID
 */
int Transaction::getCustomerID() const {
  return customerID;
}

/**
 * Returns the genre for Movie involved in this transaction.
 * 
 * @return A char to denote the genre for the Movie involved
 * in this transaction.
 */
char Transaction::getGenreOfMovie() const {
  return genreOfMovie;
}

/**
 * Class Destructor
 */
Transaction::~Transaction() {}