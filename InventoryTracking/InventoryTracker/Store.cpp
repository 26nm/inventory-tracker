/**
 * Store - a class responsible for processing data from .txt files.
 * 
 * This class handles the reading and parsing of .txt files containing movie,
 * command, and customer data. It organizes the information into appropriate 
 * data structures such as hash tables and trees, and facilitates the creation 
 * of transactions based on parsed commands.
 * 
 * It provides methods for initializing and populating the movie inventory and 
 * customer database, as well as for managing transactions through commands 
 * specified in the input files.
 * 
 * Nolan Dela Rosa
 * 
 * August 14, 2024
 */
#include "Store.h"
#include <limits>
using namespace std;

/**
 * Class constructor
 */
Store::Store() {}

/**
 * Loads and processes data from specified text files.
 * 
 * This method reads data from three files: one containing movie information, 
 * one containing customer information, and one containing transaction details. 
 * It sequentially reads and processes the data using the corresponding 
 * file-specific methods (`readMovies`, `readCustomers`, `readTransactions`).
 * 
 * @param movieFile The path to the file containing movie data.
 * @param customerFile The path to the file containing customer data.
 * @param transactionFile The path to the file containing transaction data.
 * @return Returns true if all files are successfully read and processed; 
 *         returns false if any file fails to be read or processed.
 */
bool Store::loadData(const string &movieFile, const string &customerFile,
  const string &transactionFile) {
  return readMovies(movieFile) && readCustomers(customerFile)
    && readTransactions(transactionFile);
}

/**
 * Reads movie data from a specified file and parses each line into a Movie object.
 * The parsed Movie objects are then inserted into their respective genre-specific
 * binary search trees (Classic, Drama, Comedy). If a Movie cannot be parsed or 
 * has an unrecognized genre, it is discarded. The method returns true if the 
 * file was successfully processed, otherwise false if the file could not be opened.
 *
 * @param movieFile The name of the file containing the movie data.
 * @return True if the file was successfully read and processed, false otherwise.
 */
bool Store::readMovies(const string &movieFile) {
  ifstream input(movieFile);
  if(!input.is_open()) {
    cout << "Error opening " << movieFile << "." << endl;
    return false;
  }
  
  string movieData;

  while(getline(input, movieData)) {
    parseMovieData(movieData);
  }

  input.close();
  return true;
}

/**
 * Parses a line of movie data and creates a Movie object based on the genre.
 *
 * @param movieData The string containing the movie data to parse.
 */
void Store::parseMovieData(const string &movieData) {
  istringstream input(movieData);
  char type = ' ';
  input >> type;
  input.ignore(2); 

  int stock = 0;
  input >> stock;
  input.ignore(2); 

  string director = "", title = "", 
    actor= "", releaseMonth = "", releaseYear = "";
  int month = 0, year = 0;

  if(!getline(input, director, ',')) {
    return;
  }
    
  director.erase(0, director.find_first_not_of(" \t")); 

  if(!std::getline(input, title, ',')) {
    return;
  }
    
  title.erase(0, title.find_first_not_of(" \t")); 

  if (type == 'C') {
    string actorAndReleaseDate = "";
    getline(input, actorAndReleaseDate);
    actorAndReleaseDate.erase(0, actorAndReleaseDate.find_first_not_of(" \t")); 

    if(!parseClassicMovies(stock, director, title, actorAndReleaseDate)) {
      return;
    }

  } else if (type == 'D' || type == 'F') {
      if(!(input >> year)) {
        return;
      }

      Movie *newMovie = MovieFactory::createMovie(type, stock, director, title, "", 0, year);

      switch(type) {
        case 'D':
          dramaTree.insert(newMovie);
          break;

        case 'F':
          comedyTree.insert(newMovie);
          break;

        default:
          break;
      }

  } else {
      cout << "Error: unknown genre " << type << "." << endl;
      return;
  }
}

/**
 * Parses details specific to Classic movies such as the actor's name and release date.
 *
 * @param details The string containing the actor's name and release date.
 * @param director The director of the movie.
 * @param title The title of the movie.
 * @param stock The stock of the movie.
 * @return True if details were successfully parsed, false otherwise.
 */
bool Store::parseClassicMovies(int stock, const string &director, const string &title, const string &details) {
  istringstream input(details);
  string actor = "",
  firstName = "", lastName = "";  
  int month = 0, year = 0;
  input >> firstName >> lastName >> month >> year;
  actor = firstName + " " + lastName;
  Movie *newMovie = MovieFactory::createMovie('C', stock, director, title, actor, month, year);
  classicTree.insert(newMovie);
  return true;
}



/**
 * Reads and parses customer data from a given file.
 * Each line in the file represents a customer record, which is parsed 
 * into a Customer object. The parsed Customer objects are then processed 
 * as needed, such as being added to a data structure for later use.
 *
 * @param customerFile The path to the file containing customer data.
 * @return True if the file was successfully opened and processed; 
 *         false if there was an error opening the file.
 */
bool Store::readCustomers(const string &customerFile) {
  ifstream input(customerFile);

  if(!(input.is_open())) {
    cout << "Error opening file " << customerFile << endl;
    return false;
  }

  string customerData;

  while(getline(input, customerData)) {
    Customer *newCustomer = parseCustomerData(customerData);
    if(newCustomer != nullptr) {
      customers.insert(newCustomer);
    } 
  }

  input.close();
  return true;
}

/**
 * Parses a line of customer data to create a Customer object.
 * The line is expected to contain customer information in a specific format,
 * with the customer ID and full name separated by spaces.
 *
 * @param customerData A string representing a single line of customer data,
 *                     with the customer ID followed by the full name.
 * @return A pointer to a newly created Customer object if parsing is successful;
 *         nullptr if there is an error parsing the data.
 */
Customer* Store::parseCustomerData(const string &customerData) {
  istringstream input(customerData);
  int customerID = 0;
  string firstName = "", lastName = "";

  if(input >> customerID && input >> firstName >> lastName) {
    return new Customer(customerID, firstName, lastName);
  }
  
  return nullptr;
}

/**
 * Reads transaction data from a file and processes each transaction.
 * Opens the specified file and reads it line by line. Each line represents
 * a transaction in a predefined format. For each line, a Transaction object
 * is created by parsing the line. Valid transactions are added to the 
 * `transactions` vector. If a transaction cannot be parsed, an error message
 * is printed.
 *
 * @param transactionFile The name of the file containing transaction data.
 * @return true if all transactions were successfully read and processed;
 *         false if there was an error opening the file or reading its contents.
 */
bool Store::readTransactions(const string &transactionFile) {
  ifstream input(transactionFile);

  if(!(input.is_open())) {
    cout << "Error opening " << transactionFile << "." << endl;
    return false;
  }

  string transactionData;

  while(getline(input, transactionData)) {
    Transaction* newTransaction = parseTransactionData(transactionData);
    if(newTransaction != nullptr) {
      transactions.push_back(newTransaction);
    } 
  }

  input.close();
  return true;
}

/**
 * Parses a line of transaction data and creates the corresponding Transaction object.
 * This function takes a single line of transaction data, which includes various
 * attributes such as transaction type, customer ID, media type, genre, and additional
 * attributes. Based on the transaction type (denoted by the first character), it
 * delegates the creation of the Transaction object to the TransactionFactory.
 * 
 * The transaction types are as follows:
 * - 'B': Borrow transaction
 * - 'H': Return transaction
 * - 'I': Inventory transaction
 * - 'R': Reserve transaction
 * 
 * @param transactionData A string containing the transaction data to be parsed.
 * @return A pointer to the created Transaction object if the transaction type is valid;
 *         nullptr if the transaction type is unknown or if there is an error parsing the data.
 */
Transaction* Store::parseTransactionData(const string &transactionData) {
  istringstream input(transactionData);
  char transType;
  int customerID = 0;
  input >> transType;

  switch (transType) {
    case 'I':
      return TransactionFactory::createTransaction('I', 0, ' ', ' ', "", "");

    case 'H':
      input >> customerID;
      return TransactionFactory::createTransaction('H', customerID, ' ', ' ', "", "");

    case 'B':
      case 'R': {
        input >> customerID;
        char mediaType, genre;
        input >> mediaType >> genre;
        return parseBorrowOrReturnTransaction(input, transType, customerID, mediaType, genre);
    }

    default:
      cerr << "Error: unknown transaction code " << transType << "." << std::endl;
      return nullptr;
  }
}

/**
 * Parses and creates a Borrow or Return transaction based on the provided genre.
 * 
 * This function handles the parsing of transaction data specific to Borrow ('B') 
 * or Return ('R') transactions. The genre of the item (denoted by the fourth character)
 * determines how the rest of the data is parsed. It handles the following genres:
 * 
 * - 'C': Classic movies, which include month, year, and actor information.
 * - 'D': Dramas, which include director and movie title.
 * - 'F': Comedies, which include movie title and release year.
 * 
 * The parsed data is used to create a Transaction object through the TransactionFactory.
 * 
 * @param input The input stream containing the transaction data.
 * @param transType The type of transaction ('B' for Borrow, 'R' for Return).
 * @param customerID The ID of the customer involved in the transaction.
 * @param mediaType The type of media involved in the transaction.
 * @param genre The genre of the movie involved in the transaction.
 * @return A pointer to the created Transaction object if the genre is valid;
 *         nullptr if the genre is unknown.
 */
Transaction* Store::parseBorrowOrReturnTransaction(std::istringstream &input, char transType, int customerID, char mediaType, char genre) {
  switch (genre) {
    case 'C': {
      string month, year, firstName, lastName;
      input >> month >> year >> firstName >> lastName;
      string releaseDate = month + " " + year;
      string actor = firstName + " " + lastName;
      return TransactionFactory::createTransaction(transType, customerID, mediaType, genre, releaseDate, actor);
    }

    case 'D': {
      string director, title;
      getline(input >> ws, director, ',');
      getline(input >> ws, title, ',');
      title = trim(title);
      return TransactionFactory::createTransaction(transType, customerID, mediaType, genre, director, title);
    }

    case 'F': {
      string title, year;
      getline(input >> ws, title, ',');
      getline(input >> ws, year, ',');
      year = trim(year);
      return TransactionFactory::createTransaction(transType, customerID, mediaType, genre, title, year);
    }

    default:
      cout << "Error: unknown genre code " << genre << "." << std::endl;
      return nullptr;
  }
}

/**
 * Trims leading and trailing whitespace (spaces and tabs) from the input string.
 *
 * This function finds the first and last characters in the string that are
 * not spaces or tabs, and returns the substring between these two points.
 * If the string contains only whitespace or is empty, an empty string is returned.
 *
 * @param str The input string to be trimmed.
 * @return A new string with leading and trailing whitespace removed.
 */
string Store::trim(const std::string &str) {
  size_t start = str.find_first_not_of(" \t");
  size_t end = str.find_last_not_of(" \t");
  return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}


/**
 * Iterate through all stored transactions and process each one.
 * Each transaction is executed against the movie trees for classic, comedy, and drama genres,
 * and the customer data is provided to handle the transaction's effects on both movies and customers.
 */
void Store::processTransactions() {
  for(Transaction* transaction : transactions) {
    if(transaction == nullptr) {
      cout << "Error: encountered a null transaction." << endl;
      continue;
    }

    char transType = transaction->getTransType();
    char genre = transaction->getGenreOfMovie();

    if(transType == 'B' || transType == 'R') {
      if(genre == 'C') {
        transaction->execute(classicTree, customers);

      } else if(genre == 'D') {
          transaction->execute(dramaTree, customers);

      } else if(genre == 'F') {
          transaction->execute(comedyTree, customers);

      } else {
          cout << "Error: unknown Movie genre " << genre << "." << endl;
      }
 
    } else if(transType == 'H') {
        MovieTree temp;
        transaction->execute(temp, customers);

    } else if(transType == 'I') {
        transaction->execute(classicTree, customers);
        transaction->execute(comedyTree, customers);
        transaction->execute(classicTree, customers);

    } else {
        cout << "Error: unknown transaction type " << transType << " encountered." << endl;
    }
  }
}

/**
 * Cleans up resources and manages memory for the Store class.
 * 
 * This method performs the following tasks:
 * 1. Clears the customer data structure by calling its `clear` method. This removes all customer records but does not deallocate the memory used for storing the hash table itself.
 * 2. Iterates through the list of transactions, deleting each `Transaction` object. This ensures that the destructor of each `Transaction` is called, releasing any dynamically allocated memory associated with each transaction.
 * 3. Clears the list of transaction pointers, effectively removing all transaction references and allowing the list to be reset or reused.
 * 
 * This method is intended to free up memory and clean up resources when the `Store` object is no longer needed or before it is destroyed.
 */
void Store::cleanup() {
  customers.clear();

  for(Transaction* transaction : transactions) {
    delete transaction;  // Calls the destructor for each Transaction
  }
    
  transactions.clear(); 
}

/**
 * Class Destructor
 */
Store::~Store() {
  cleanup();
}



