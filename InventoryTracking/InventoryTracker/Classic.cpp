/*
 * Classic - A subclass of Movie that represents classic genre films.
 * This class extends the base Movie class to include specific features
 * or functionality related to classic films, while inheriting
 * common attributes and methods from Movie.
 *
 * Nolan Dela Rosa
 *
 * August 9, 2024
 */
#include "Classic.h"
using namespace std;

/**
 * Default constructor for the Classic class.
 * Initializes a new instance of the Classic class with default values.
 */
Classic::Classic()
  : Movie(), majorActor(""), monthReleased(0) {
}

/**
 * Parameterized constructor for the Comedy class.
 * Initializes a new instance of the Comedy class with specified values.
 *
 * @param type The genre of the movie.
 * @param theStock The number of copies available in stock.
 * @param theTitle The title of the movie.
 * @param theDirector The director of the movie.
 * @param theActor The actor/actress featured in the movie.
 * @param releaseMonth The month the movie was released.
 * @param theYear The year the movie was released.
 */
Classic::Classic(char type, int theStock, const string& theDirector, 
const string& theTitle, const string& theActor, 
  int releaseMonth, int theYear)
  : Movie(type, theStock, theDirector, theTitle, theYear),
     majorActor(theActor),
    monthReleased(releaseMonth) {
}

/**
 * Copy constructor for the Classic class.
 * 
 * Initializes a new Classic object as an exact copy of an existing one.
 * This constructor duplicates all attributes of the original Classic object,
 * including the genre, stock quantity, title, director, major actor, 
 * month released, and year released. This ensures that the new Classic 
 * instance contains the same data as the original.
 *
 * @param other The Classic object to be copied.
 */
Classic::Classic(const Classic &other)
  : Movie(other), majorActor(other.majorActor), 
    monthReleased (other.monthReleased) {
}

/**
 * Overloads the assignment operator to handle assignment from 
 * a Movie reference. This operator allows for assigning 
 * one Classic object to another. It first checks if the current 
 * object is the same as the one being assigned (self-assignment). 
 * If not, it uses dynamic_cast to safely downcast the 
 * Movie reference to a Classic pointer. If the cast is successful, 
 * it copies the data members from the source Classic object 
 * to the current object.
 * 
 * @param other A reference to the Movie object being assigned. 
 * @return A reference to the current Classic object after the assignment.
 */
Classic &Classic::operator=(const Movie &other) {
  if(this != &other) {
    const Classic* classicPtr = dynamic_cast<const Classic*>(&other);
    if(classicPtr != nullptr) {
      genre = classicPtr->genre;
      stock = classicPtr->stock;
      director = classicPtr->director;
      title = classicPtr->title;
      majorActor = classicPtr->majorActor;
      monthReleased = classicPtr->monthReleased;
      yearReleased = classicPtr->yearReleased;
    }
  }

  return *this;
}

/**
 * Compares this Classic movie object with another Movie object for equality.
 * 
 * This comparison checks if the two Classic movie objects have identical
 * titles, directors, major actors, and release dates (both month and year).
 * The method ensures that the other Movie object is of type Classic before
 * performing the comparison. If all attributes match, the two Classic movies
 * are considered equal.
 *
 * @param other A pointer to the other Movie object to compare with. Expected 
 *              to be of type Classic.
 * @return true if both Classic movies have the same title, director, 
 *         major actor, month of release, and year of release; false if 
 *         the movies differ in any of these attributes or if the other 
 *         Movie is not of type Classic.
 */
bool Classic::operator==(const Movie &other) const {
  const Classic *otherClassic = dynamic_cast<const Classic*>(&other);

  if(otherClassic != nullptr) {
    return (getMajorActor() == otherClassic->getMajorActor()
      && getMonthReleased() == otherClassic->getMonthReleased()
      && getYearReleased() == otherClassic->getYearReleased());
  }

  return false;
}

/**
 * Compares this Classic movie object with another Movie object for 
 * inequality. This method returns the opposite result of the 
 * equality comparison (operator==).
 * 
 * @param other A pointer to the other Movie object to compare with.
 * @return true if the two Classic movies differ in title, director, 
 *         actor, month and year released, or if the other Movie is 
 *         not of type Comedy; false if they are equal.
 */
bool Classic::operator!=(const Movie &other) const {
  return !(*this == other);
}

/**
 * Compares this Classic movie object with another Movie object to determine 
 * if it is "less than" the other.
 * 
 * The comparison primarily focuses on the year of release. 
 * If the year of release is the same, it further compares 
 * the month of release to determine the order. 
 *
 * @param other A pointer to the other Movie object to compare with. 
 *              Expected to be of type Classic.
 * @return true if this Classic movie was released before 
 *         the other Classic movie, or if they were released 
 *         in the same year but this movie was released 
 *         in an earlier month. Returns false if the other movie is 
 *         not of type Classic or if this movie is not less than the other 
 *         based on the release date.
 */
bool Classic::operator<(const Movie &other) const {
  const Classic *otherClassic = dynamic_cast<const Classic*>(&other);

  if (otherClassic != nullptr) {
    if (getYearReleased() < otherClassic->getYearReleased()) {
      return true;

    } else if (getYearReleased() == otherClassic->getYearReleased()) {
      if (getMonthReleased() < otherClassic->getMonthReleased()) {
        return true;

      } else if(getMajorActor() < otherClassic->getMajorActor()) {
          return true;
      }
    }
  }

  return false;
}

/**
 * Compares this Classic movie object with another Movie object 
 * to determine if it is "greater than" the other.
 * 
 * This method returns the opposite result of the less-than (<) operator. 
 * It checks if this Classic movie is not less than and not equal to the 
 * other movie, effectively determining if it is "greater than" the other. 
 * The comparison is based on the release year, followed by the release 
 * month if the years are the same.
 *
 * @param other A pointer to the other Movie object to compare with,
 *              expected to be of type Classic.
 * @return true if this Classic movie is "greater than" the other based on 
 *         the specified criteria; false otherwise.
 */
bool Classic::operator>(const Movie &other) const {
  return !(*this < other) && (*this != other);
}

/**
 * Retrieves this Classic's major actor.
 * 
 * @return The major actor/actress in this film.
 */
string Classic::getMajorActor() const {
  return majorActor;
}

/**
 * Retrive this Classic's month released.
 * 
 * @return The month this Classic was released.
 */
int Classic::getMonthReleased() const {
  return monthReleased;
}

/**
 * Displays detailed information about this Classic movie.
 * 
 * This function outputs the movie's title, director, actor, 
 * the month and year it was released, formatted for readability. 
 * It provides a clear and concise summary of the movie's key attributes.
 */
void Classic::displayInfo() const {
  if(stock < 0) {
    cout << "Error: this Movie is out of stock." << endl;
    return;
  }
  
  cout << left << setw(8) << getGenre()
       << setw(8) << getStock()
       << setw(25) << getDirector()
       << setw(35) << getTitle()
       << setw(20) << getMajorActor()
       << setw(8) << getMonthReleased()
       << getYearReleased() << endl;
}

/**
 * Class Destructor
 */
Classic::~Classic() {}