/**
 * Drama - A subclass of Movie that represents drama genre films.
 * This class extends the base Movie class to include specific features
 * or functionality related to drama films, while inheriting
 * common attributes and methods from Movie.
 *
 * Nolan Dela Rosa
 *
 * August 9, 2024
 */
#include "Drama.h"
using namespace std;

/**
 * Default constructor for the Drama class.
 * Initializes a new instance of the Drama class with default values.
 */
Drama::Drama() 
  : Movie() {
}

/**
 * Parameterized constructor for the Drama class.
 * Initializes a new instance of the Drama class with specified values.
 *
 * @param type The genre of the movi.
 * @param theStock The number of copies available in stock.
 * @param theTitle The title of the movie.
 * @param theDirector The director of the movie.
 * @param theYear The year the movie was released.
 */
Drama::Drama(char type, int theStock, const string& theDirector,
  const string& theTitle, int theYear)
    : Movie(type, theStock, theDirector, theTitle, theYear) {
}


/**
 * Copy constructor for the Drama class.
 * 
 * Creates a new Drama object as a copy of an existing one by 
 * duplicating all of its attributes. This includes the genre, 
 * stock quantity, director, title, and year of release, 
 * ensuring that the new Drama instance is identical to the 
 * original one in all relevant properties.
 *
 * @param other The Drama object to be copied.
 */
Drama::Drama(const Drama &other)
  : Movie(other) {  
}

/**
 * Overloads the assignment operator to handle assignment from a Movie reference.
 * This operator allows for assigning one Drama object to another. 
 * It first checks if the current object is the same as the one being assigned 
 * (self-assignment). If not, it uses dynamic_cast to safely downcast the 
 * Movie reference to a Drama pointer. If the cast is successful, it copies 
 * the data members from the source Drama object to the current object.
 * 
 * @param other A reference to the Movie object being assigned. 
 * @return A reference to the current Drama object after the assignment.
 */
Drama &Drama::operator=(const Movie &other) {
  if(this != &other) {
    const Drama* dramaPtr = dynamic_cast<const Drama*>(&other);
    if(dramaPtr != nullptr) {
      genre = dramaPtr->genre;
      stock = dramaPtr->genre;
      director = dramaPtr->director;
      title = dramaPtr->title;
      yearReleased = dramaPtr->yearReleased;
    }
  }

  return *this;
}


/**
 * Compares this Drama movie object with another Movie object 
 * to check for equality. The comparison is based on the 
 * title, director, and year released. This method first ensures 
 * that the other Movie object is also of type Drama.
 * 
 * @param other A pointer to the other Movie object to compare with.
 * @return true if both Drama movies have the same title, director, 
 *         and year released; false otherwise or if the other Movie 
 *         is not of type Comedy.
 */
bool Drama::operator==(const Movie &other) const {
  const Drama *otherDrama = dynamic_cast<const Drama *>(&other);

  if (otherDrama != nullptr) {
    return (((getTitle() == otherDrama->getTitle()) 
      && (getDirector() == otherDrama->getDirector())));
  }

  return false;
}

/**
 * Compares this Drama movie object with another Movie object for inequality.
 * This method returns the opposite result of the equality comparison 
 * (operator==).
 * 
 * @param other A pointer to the other Movie object to compare with.
 * @return true if the two Drama movies differ in title, director, 
 *         or year released, or if the other Movie is 
 *         not of type Comedy; false if they are equal.
 */
bool Drama::operator!=(const Movie &other) const {
  return !(*this == other);
}

/**
 * Compares this Drama object with another Drama object.
 * 
 * The comparison is first based on the Director. If Directors are the same, 
 * it then compares the Titles. This ensures that Dramas are sorted by Director 
 * first, and by Title if Directors are identical.
 * 
 * @param other A pointer to a `Movie` object, expected to be of type `Drama`. 
 *              It is cast to `Drama` for comparison.
 * 
 * @return `true` if this Drama is less than the `other` Drama according to 
 *         the specified criteria; `false` otherwise.
 */
bool Drama::operator<(const Movie &other) const {
  const Drama *otherDrama = dynamic_cast<const Drama*>(&other);

  if (otherDrama != nullptr) {
    if(getDirector() < otherDrama->getDirector()) {
      return true;
    }

    if(getTitle() < otherDrama->getTitle()) {
      return true;
    }
  }

  return false;
}

/**
 * Returns the opposite result of the "<" operator, comparing
 * this Drama movie object with another Movie object.
 *
 * @param other A pointer to the other Movie object to compare with.
 * @return true if this Drama movie's title is lexicographically greater,
 *         or, if the titles are the same, the year of this movie is later;
 *         false otherwise. If the other Movie is not of type Drama, 
 *         it returns true by default (assuming a Drama movie is considered 
 *         "greater" in such cases).
 */
bool Drama::operator>(const Movie &other) const {
  return !(*this < other) && (*this != other);
}

/**
 * Displays detailed information about this Drama movie.
 * 
 * This function outputs the movie's title, director, 
 * and the year it was released, formatted for readability. 
 * It provides a clear and concise summary of the movie's key attributes.
 */
void Drama::displayInfo() const {
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
Drama::~Drama() {}



