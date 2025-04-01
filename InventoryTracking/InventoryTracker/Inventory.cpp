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
#include "Inventory.h"
using namespace std;

/**
 * Default constructor for the Inventory class.
 * Initializes an Inventory transaction by invoking the base Transaction class constructor.
 * This constructor is typically used to create an empty Inventory transaction object 
 * before assigning specific data to it.
 */
Inventory::Inventory()
  : Transaction() {
}

/**
 * Parameterized constructor for the Inventory class.
 * This constructor initializes the Inventory object by invoking 
 * the base Transaction class constructor with the provided 
 * transaction type.
 *
 * @param trans A character representing the type of transaction 
 *              (e.g., 'B' for borrow, 'R' for return, etc.).
 */
Inventory::Inventory(char trans, char genre, int ID)
  : Transaction(trans, genre, ID) {
}

/**
 * Display the inventory of available Movies.
 * This method outputs the list of all Movies currently stored in the MovieTree,
 * formatted for easy readability. It is typically invoked when a user or system
 * operation requires a view of all Movies that are available for transactions.
 *
 * @param movies    The MovieTree containing the collection of Movies to display.
 * @param customers The HashTable of customers (unused in this function but passed in as part of the interface).
 */
void Inventory::execute(MovieTree &movies, HashTable &customers) {
  cout << "Available Movies: " << endl;
  cout << "------------------------------------------------------" << endl;
  movies.display();
  cout << endl;
}

/**
 * Class Destructor
 */
Inventory::~Inventory() {}