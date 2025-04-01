/**
 * Borrow - a subclass of Transaction that represents a transaction 
 * for borrowing a movie. This class is derived from the base 
 * Transaction class and is used to manage and track the process of 
 * borrowing movies. It extends the functionality of the base class by 
 * implementing the `execute` method, which updates the state of the 
 * `HashTable` to reflect that a movie has been borrowed, including 
 * decreasing its available stock.
 *
 * Nolan Dela Rosa
 * 
 * August 13, 2024
 */
#include "Borrow.h"
#include <sstream>
using namespace std;

/**
 * Default constructor for the Borrow class.
 * This constructor provides a starting point for creating
 * Borrow objects before setting specific attributes.
 */
Borrow::Borrow() 
  : Transaction(), mediaType(' '), attribute1(" "), 
    attribute2(" ") {
}

/**
 * Parameterized constructor for the Borrow class.
 * 
 * Initializes a new Borrow object with the provided values:
 * 
 * @param trans The transaction type identifier, typically a character representing the type of transaction
 * @param ID The unique ID number of the customer making the transaction.
 * @param media A character representing the type of media being borrowed 
 * @param genreType A character representing the genre of the media 
 * @param data1 A string containing the first additional attribute relevant to the transaction 
 * @param data2 A string containing the second additional attribute relevant to the transaction (e.g., year of release, director's name).
 */
Borrow::Borrow(char trans, int ID, char media,
  char genreType, const string &data1, const string &data2)
  : Transaction(trans, genreType, ID), mediaType(media),
    attribute1(data1), attribute2(data2) {
}

/**
 * Executes the borrowing transaction by processing the provided customer and movie data.
 * 
 * If the movie is found, the function attempts to mark the movie as borrowed and 
 * logs this transaction under the customer's record. If any step fails 
 * (e.g., movie not found, borrowing issue), appropriate error messages are displayed.
 * 
 * @param movies The `MovieTree` object containing the collection of movies to search through.
 * @param customers The `HashTable` object containing the customer records to retrieve 
 *                  the customer details.
 */
void Borrow::execute(MovieTree &movies, HashTable &customers) {
  Customer* currentCustomer = customers.get(customerID);

  if(currentCustomer == nullptr) {
    cout << "Error: customer not found!" << endl;
    return;
  }

  Movie* customerMovie = nullptr;
  bool movieRetrieved = false;

  if(genreOfMovie == 'C') {
    int month = 0, year = 0;
    istringstream releaseData(attribute1);
    releaseData >> month >> year;
    movieRetrieved = movies.retrieve(Classic(genreOfMovie, 0, "", "", 
      attribute2, month, year), customerMovie);

  } else if(genreOfMovie == 'D') {
      movieRetrieved = movies.retrieve(Drama(genreOfMovie, 0,
        attribute1, attribute2, 0), customerMovie);

  } else if(genreOfMovie == 'F') {
      int year = 0;
      istringstream releaseYear(attribute2);
      releaseYear >> year;
      movieRetrieved = movies.retrieve(Comedy(genreOfMovie, 0,
        "", attribute1, year), customerMovie);
  }

  if(!movieRetrieved) {
    cout << "Error: movie not found!" << endl;
    return;
  }

  try {
    customerMovie->borrowMovie();
    currentCustomer->addTransaction("Borrowed " 
      + customerMovie->getTitle());

  } catch(const exception &e) {
      cout << "Error: transaction unsuccessful!" << endl;
  }
}

/**
 * Class Destructor
 */
Borrow::~Borrow() {}
