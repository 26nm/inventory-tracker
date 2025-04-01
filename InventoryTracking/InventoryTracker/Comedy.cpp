/**
 * Comedy - A subclass of Movie that represents comedy genre films.
 * This class extends the base Movie class to include specific features
 * or functionality related to comedy films, while inheriting
 * common attributes and methods from Movie.
 *
 * Nolan Dela Rosa
 *
 * August 9, 2024
 */
#include "Comedy.h"
using namespace std;

/**
 * Default constructor for the Comedy class.
 * Initializes a new instance of the Comedy class with default values.
 */
Comedy::Comedy() 
  : Movie() {
}

/**
 * Parameterized constructor for the Comedy class.
 * Initializes a new instance of the Comedy class with specified values.
 *
 * @param type The genre of the movie.
 * @param theStock The number of copies available in stock.
 * @param theTitle The title of the movie.
 * @param theDirector The director of the movie.
 * @param theYear The year the movie was released.
 */
Comedy::Comedy(char type, int theStock, const string& theDirector,
  const string& theTitle, int theYear)
    : Movie(type, theStock, theDirector, theTitle, theYear) {
}

/**
 * Copy constructor for the Comedy class.
 * 
 * Creates a new Comedy object as a copy of an existing one by duplicating
 * all of its attributes. This includes the genre, stock quantity, director, 
 * title, and year of release, ensuring that the new Comedy instance is 
 * identical to the original one in all relevant properties.
 *
 * @param other The Comedy object to be copied.
 */
Comedy::Comedy(const Comedy &other)
  : Movie(other) {  
}

/**
 * Overloads the assignment operator to handle assignment from a Movie reference.
 * This operator allows for assigning one Comedy object to another. 
 * It first checks if the current object is the same as the one being assigned 
 * (self-assignment). If not, it uses dynamic_cast to safely downcast the 
 * Movie reference to a Comedy pointer. If the cast is successful, it copies 
 * the data members from the source Comedy object to the current object.
 * 
 * @param other A reference to the Movie object being assigned. 
 * @return A reference to the current Comedy object after the assignment.
 */
Comedy &Comedy::operator=(const Movie &other) {
  if(this != &other) {
    const Comedy* comedyPtr = dynamic_cast<const Comedy*>(&other);
    if(comedyPtr != nullptr) {
      genre = comedyPtr->genre;
      stock = comedyPtr->genre;
      director = comedyPtr->director;
      title = comedyPtr->title;
      yearReleased = comedyPtr->yearReleased;
    }
  }

  return *this;
}

/**
 * Compares this Comedy movie object with another Movie object 
 * to check for equality. The comparison is based on the 
 * title, director, and year released. This method first ensures 
 * that the other Movie object is also of type Comedy.
 * 
 * @param other A pointer to the other Movie object to compare with.
 * @return true if both Comedy movies have the same title, director, 
 *         and year released; false otherwise or if the other Movie 
 *         is not of type Comedy.
 * 
 */
bool Comedy::operator==(const Movie &other) const {
  const Comedy *otherComedy = dynamic_cast<const Comedy *>(&other);

  if (otherComedy != nullptr) {
    return (((getTitle() == otherComedy->getTitle())) 
      && (getYearReleased() == otherComedy->getYearReleased()));
  }

  return false;
}

/**
 * Compares this Comedy movie object with another Movie object for inequality.
 * This method returns the opposite result of the equality comparison 
 * (operator==).
 * 
 * @param other A pointer to the other Movie object to compare with.
 * @return true if the two Comedy movies differ in title, director, 
 *         or year released, or if the other Movie is 
 *         not of type Comedy; false if they are equal.
 */
bool Comedy::operator!=(const Movie &other) const {
  return !(*this == other);
}

/**
 * Compares this Comedy movie object with another Movie object 
 * by title and publication year to determine which is "earlier."
 *
 * @param other A pointer to the other Movie object to compare with.
 * @return true if this Comedy movie's title is lexicographically less,
 *         or, if the titles are the same, the year of this movie is earlier;
 *         false otherwise. If the other Movie is not of type Comedy, 
 *         it returns false.
 */
bool Comedy::operator<(const Movie &other) const {
  const Comedy *otherComedy = dynamic_cast<const Comedy*>(&other);

  if (otherComedy != nullptr) {
    if(getTitle() < otherComedy->getTitle()) {
      return true;
    }

    if(getYearReleased() < otherComedy->getYearReleased()) {
      return true;
    }
  }

  return false;
}

/**
 * Returns the opposite result of the "<" operator, comparing
 * this Comedy movie object with another Movie object.
 *
 * @param other A pointer to the other Movie object to compare with.
 * @return true if this Comedy movie's title is lexicographically greater,
 *         or, if the titles are the same, the year of this movie is later;
 *         false otherwise. If the other Movie is not of type Comedy, 
 *         it returns true by default (assuming a Comedy movie is considered 
 *         "greater" in such cases).
 */
bool Comedy::operator>(const Movie &other) const {
  return !(*this < other) && (*this != other);
}

/**
 * Displays detailed information about this Comedy movie.
 * 
 * This function outputs the movie's title, director, 
 * and the year it was released, formatted for readability. 
 * It provides a clear and concise summary of the movie's key attributes.
 */
void Comedy::displayInfo() const {
  if(stock < 0) {
    cout << "Error: this Movie is out of stock." << endl;
    return;
  }

  const int genreWidth = 3;        // Width for the genre code
  const int stockWidth = 4;        // Width for the stock number
  const int directorWidth = 20;    // Width for the director's name
  const int titleWidth = 40;       // Width for the title
  const int yearWidth = 4;         // Width for the year

  // Set the output format
  cout << left
       << setw(genreWidth) << getGenre() << " " 
       << setw(stockWidth) << getStock() << " "
       << setw(directorWidth) << getDirector() << " "
       << setw(titleWidth) << getTitle() << " "
       << setw(yearWidth) << getYearReleased()
       << endl;
}

/**
 * Class Destructor
 */
Comedy::~Comedy() {}