#ifndef CUSTOMER_H
#define CUSTOMER_H

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
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Customer {
private:
  int ID;
  string firstName;
  string lastName;
  vector<string> transactions;

public:
  Customer();
  Customer(int, const string &, const string &);
  void displayInfo() const;
  void addTransaction(const string &);
  int getID() const;
  vector<string> displayHistory() const;
  ~Customer();  
};
#endif // CUSTOMER_H