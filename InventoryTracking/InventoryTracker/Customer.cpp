/**
 * Customer - a class representing a customer in the movie rental system.
 * 
 * This class currently stores the customer's ID number and name (last name and first name).
 * The ID number uniquely identifies each customer, while the name provides personal details.
 * 
 * Functionality may be expanded in the future to include additional attributes and methods, 
 * such as contact information, rental history, or loyalty status.
 * 
 * Nolan Dela Rosa
 * 
 * August 12, 2024
 */
#include "Customer.h"
using namespace std;

/**
 * Default constructor for the Customer class.
 * 
 * Initializes a new Customer object with default values:
 * - ID is set to 0
 * - name is set to an empty string
 * 
 * This constructor provides a starting point for creating Customer objects before setting
 * specific attributes.
 */
Customer::Customer() 
  : ID(0), firstName(""),
    lastName("") {
}

/**
 * Parameterized constructor for the Customer class.
 * 
 * Initializes a new Customer object with the provided ID and name.
 * 
 * @param customerID The unique ID number for the customer.
 * @param firstName The customer's first name.
 * @param lastname The customer's last name.
 */
Customer::Customer(int customerID, const string &first, const string &last)
  : ID(customerID), firstName(first),
    lastName(last) {
}

/**
 * Adds a transaction record to the customer's list of transactions.
 * 
 * This method appends a new transaction entry to the `transactions` vector for the current customer.
 * The transaction string could represent various customer activities, such as borrowing or returning movies.
 * 
 * @param transaction A string describing the transaction to be recorded. This might include details such as the type of transaction (e.g., borrowing), movie title, and date.
 */
void Customer::addTransaction(const string &transaction) {
  transactions.push_back(transaction);
}

/**
 * Retrieves the transaction history for the Customer.
 * 
 * This method returns a vector of strings, where each string
 * represents a transaction performed by the Customer. The transactions
 * are stored in the order they were performed, with the earliest 
 * transaction at the beginning of the vector and the most recent 
 * transaction at the end.
 *
 * @return A vector containing the Customer's transaction history.
 */
vector<string> Customer::displayHistory() const {
  return transactions;
}

/**
 * Displays the customer's name and ID.
 */
void Customer::displayInfo() const {
  cout << lastName << " " << firstName;
}

/**
 * Retrieves the unique ID number of the customer.
 * 
 * @return The customer ID, which is a unique integer identifier for the customer.
 */
int Customer::getID() const {
  return ID;
}

/**
 * Class Destructor
 */
Customer::~Customer() {}