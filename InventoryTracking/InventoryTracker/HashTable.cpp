/**
 * HashTable - A custom hash table implementation for storing and managing Customer objects.
 * 
 * This class uses a hash table to efficiently handle Customer data with operations
 * for inserting, retrieving, and removing customers based on their unique ID numbers.
 * 
 * Nolan Dela Rosa
 * 
 * August 12, 2024
 */
#include "HashTable.h"
using namespace std;

/**
 * Constructor for the HashTable class.
 * 
 * Initializes a new HashTable with a specified size. The table is an array of lists,
 * with each list designed to handle collisions via separate chaining.
 * 
 * @param size The size of the hash table, determining the number of buckets (lists).
 */
HashTable::HashTable(int size)
  : tableSize(size) {
  table = new list<Customer*>[tableSize];
}

/**
 * Hash function for the HashTable class.
 * 
 * Computes the hash value for a given customer ID by using the modulus operation.
 * The hash value determines the index of the bucket (list) where the Customer object
 * will be stored in the hash table.
 * 
 * @param customerID The unique ID of the customer, used as the key in the hash table.
 * @return An integer representing the index in the hash table where the customer will be stored.
 */
int HashTable::hash(int customerID) const {
  return customerID % tableSize;
}

/**
 * Insert a Customer into the HashTable.
 * 
 * This function adds a new Customer object to the hash table. The customer's ID is used to compute
 * the hash value, which determines the appropriate index (bucket) in the table where the customer 
 * will be stored. If a customer with the same ID already exists in the table, their information 
 * is updated; otherwise, the new customer is added to the list at that index.
 * 
 * @param customer The Customer object to be inserted into the hash table.
 */
void HashTable::insert(Customer* customer) {
    int index = hash(customer->getID());
    auto &list = table[index];

    for (auto &existingCustomer : list) {
        if (existingCustomer->getID() == customer->getID()) {
            delete existingCustomer;  // Delete the old customer object
            existingCustomer = customer;  // Replace with the new one
            return;
        }
    }

    list.push_back(customer);
}

/**
 * Remove a Customer from the HashTable.
 * 
 * This function removes a Customer object from the hash table based on the given customer ID.
 * It computes the hash value using the customer ID to determine the appropriate index (bucket) 
 * in the table. If a Customer with the specified ID is found at that index, the customer is 
 * removed from the list, and the function returns true. If no matching customer is found, the 
 * function returns false, indicating that the customer was not present in the hash table.
 * 
 * @param customerID The unique ID number of the customer to be removed.
 * @return A boolean value: true if the customer was successfully removed, false if the customer 
 * was not found in the hash table.
 */
bool HashTable::remove(int customerID) {
  int index = hash(customerID);
  auto &list = table[index];

  for(auto it = list.begin(); it != list.end(); ++it) {
    if((*it)->getID() == customerID) {
      list.erase(it);
      return true;
    }
  }

  return false;
}

/**
 * Retrieve a Customer by their ID.
 * 
 * This function searches the HashTable for a Customer object with the specified customer ID.
 * It uses the hash function to compute the index (bucket) where the Customer should be located 
 * and then iterates through the list at that index to find a matching customer. If a Customer 
 * with the given ID is found, a pointer to that Customer is returned. If no such Customer is 
 * found, the function returns a nullptr, indicating that the customer is not present in the 
 * hash table.
 * 
 * @param customerID The unique ID number of the customer to be retrieved.
 * @return A pointer to the Customer object if found, or nullptr if the customer was not found 
 * in the hash table.
 */
Customer* HashTable::get(int customerID) const {
  int index = hash(customerID);
  const auto &list = table[index];

  for(const auto &customer : list) {
    if(customer->getID() == customerID) {
      return customer;
    }
  }

  return nullptr;
}

/**
 * Clears all entries from the hash table.
 * 
 * This method iterates through each bucket in the hash table and clears
 * the list of customers at each bucket. It effectively removes all customer
 * data from the hash table, but does not deallocate the memory used for
 * storing the hash table itself. This method is typically used before 
 * destroying the hash table or when resetting it for reuse.
 */
void HashTable::clear() {
  for(int i = 0; i < tableSize; ++i) {
    for(auto customer : table[i]) {
      delete customer; // Delete all customer objects in each list
    }

    table[i].clear();
  }
}

/**
 * Class Destructor
 */
HashTable::~HashTable() {
  clear();
  delete[] table;
}