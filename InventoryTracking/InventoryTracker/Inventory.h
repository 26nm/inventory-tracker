#ifndef INVENTORY_H
#define INVENTORY_H

/**
 * InventoryTransaction - a class to represent a transaction for displaying the current inventory of movies.
 * This class is used to generate and display a report of all movies currently available in the MovieTree.
 * It inherits from the Transaction class and implements the execute method to print out detailed
 * information about each movie in the inventory, including their titles and other relevant details.
 * 
 * Nolan Dela Rosa
 * 
 * August 13, 2024
 */
#include "Transaction.h"
#include "MovieTree.h"
using namespace std;

class HashTable;

class Inventory : public Transaction {
public:
  Inventory();
  Inventory(char, char, int);
  virtual void execute(MovieTree &, HashTable &) override;
  virtual ~Inventory();
};
#endif // INVENTORY
