/**
 * Movie Class: This class serves as a base to represent a Movie and
 * encapsulates common functionality and attributes shared by all genres.
 * It provides a foundational structure for specific movie genres,
 * allowing derived classes to inherit and build upon these shared
 * characteristics while potentially adding genre-specific features
 * and behaviors.
 *
 * Nolan Dela Rosa
 *
 * August 9, 2024
 */
#include "Movie.h"
using namespace std;

/**
 * Default constructor for the Movie class.
 * Initializes a new instance of the Movie class with default values.
 */
Movie::Movie()
  : genre(' '), stock(0), yearReleased(0), title(""), director("") {
}

/**
 * Parameterized constructor for the Movie class.
 * Initializes a new instance of the Movie class with specified values.
 *
 * @param type The genre of the movie.
 * @param theStock The number of copies available in stock.
 * @param theTitle The title of the movie.
 * @param theDirector The director of the movie.
 * @param theYear The year the movie was released.
 */
Movie::Movie(char type, int theStock, const string &theDirector,
  const string &theTitle, int theYear) 
    : genre(type), stock(theStock), director(theDirector),
      title(theTitle), yearReleased(theYear) {
}

/**
 * Class copy constructor
 */
Movie::Movie(const Movie &other) 
  : genre(other.genre), stock(other.stock), director(other.director),
    title(other.title), yearReleased(other.yearReleased) {
}

/**
 * Increments the stock count of the movie by one when the movie is returned.
 * This method should be called to update the inventory whenever a movie 
 * that was previously checked out is returned, making it available again.
 */
void Movie::returnMovie() {
  stock++;
}

/**
 * Decreases the stock count of the movie by one when the movie is borrowed.
 * This method should be called to update the inventory whenever a movie is 
 * checked out or borrowed, reducing its availability.
 */
void Movie::borrowMovie() {
  if(stock < 0) {
    cout << "Error: this Movie is out of stock." << endl;
    return;
  }

  stock--;
}

/**
 * Retrieves the genre of this Movie instance.
 *
 * @return The genre of the movie as a character.
 */
char Movie::getGenre() const {
  return genre;
}

/**
 * Retrieves the current stock quantity of this Movie instance.
 *
 * @return The number of available copies of the movie in stock.
 */
int Movie::getStock() const {
  return stock;
}

/**
 * Retrieves the title of this Movie instance.
 *
 * @return The title of the movie as a string.
 */
string Movie::getTitle() const {
  return title;
}

/**
 * Retrieves the director of this Movie instance.
 *
 * @return The director's name as a string.
 */
string Movie::getDirector() const {
  return director;
}

/**
 * Retrieves the year this Movie was released.
 *
 * @return The release year of the movie as an integer.
 */
int Movie::getYearReleased() const {
  return yearReleased;
}

/**
 * Class Destructor
 */
Movie::~Movie() {}
