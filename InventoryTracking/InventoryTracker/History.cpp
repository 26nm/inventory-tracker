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
#include "History.h"
using namespace std;

/**
 * Default constructor for the History class.
 * 
 * Initializes a History object with default values. The transaction type is set to
 * the default value of the base Transaction class, and the customerID is initialized
 * to 0, indicating that no specific customer has been associated with this transaction yet.
 */
History::History()
  : Transaction() {
}

/**
 * Parameterized constructor for the History class.
 * 
 * This constructor initializes a History object with specific values for the transaction type 
 * and customer ID. The `trans` parameter is passed to the base Transaction class to define 
 * the type of transaction (e.g., borrow, return), while the `ID` parameter is used to 
 * associate this transaction with a specific customer.
 *
 * @param trans A character representing the type of transaction (e.g., 'B' for borrow).
 * @param ID An integer representing the unique customer ID for whom the transaction is being recorded.
 */
History::History(char trans, char genreType, int ID)
  : Transaction(trans, genreType, ID) {
}

/**
 * Executes the History transaction to display the customer's transaction history.
 *
 * This function retrieves the customer associated with the `customerID` stored in the History object 
 * from the provided HashTable of customers. If the customer is found, it retrieves their transaction history.
 * If the customer does not exist, an error message is displayed. If the customer exists but has no recorded transactions,
 * a message indicating that there are no recorded transactions is displayed. Otherwise, the function 
 * iterates through the customer's transaction history and prints each transaction.
 *
 * @param movies A reference to the MovieTree, though it is not used in this method.
 * @param customers A reference to the HashTable containing customer data.
 */
void History::execute(MovieTree &movies, HashTable &customers) {
  Customer* currentCustomer = customers.get(customerID);

  if(currentCustomer == nullptr) {
    cout << "Error: customer not found!" << endl;
    return;
  }

  vector<string> customerTransactions = currentCustomer->displayHistory();

  if(customerTransactions.empty()) {
    cout << "No recorded transactions for this customer." << endl;
    return;
  }

  cout << "Transaction History for ";
  currentCustomer->displayInfo();
  currentCustomer->addTransaction("Viewed History");
  cout << endl;
  cout << "--------------------------------------------------------------" << endl;
  
  for(const string &transaction : customerTransactions) {
    cout << transaction << endl;
  }

  cout << endl;
}

/**
 * Class Destructor
 */
History::~History() {}