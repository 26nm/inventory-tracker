/**
 * This class is designed specifically for testing the functionality 
 * of the all classes currently implemented. It ensures 
 * that the implemented features behave as expected.
 * 
 * Nolan Dela Rosa
 * 
 * August 9, 2024
 */
#include <iostream>
#include <cassert>
#include "Store.h"
using namespace std;

/**
 * Function for testing implementation operability.
 */
int main() {
  Store store;

  string movieFile = "data4movies.txt";
  string customerFile = "data4customers.txt";
  string transactionFile = "data4commands.txt";

  // Load data from files
  if(!store.loadData(movieFile, customerFile, transactionFile)) {
    cout << "Error loading data from files." << endl;
    return 1;
  }

  cout << "Data loaded successfully." << endl;
  store.processTransactions();
  cout << "Transactions processed." << endl;
  cout << "Cleanup completed." << endl;

  return 0;
}
