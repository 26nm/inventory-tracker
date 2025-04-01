/**
 * MovieFactory - A utility class responsible for creating Movie objects based on the specified genre.
 * This class encapsulates the logic for generating different types of Movie instances,
 * ensuring that each genre is handled appropriately during the creation process.
 *
 * Nolan Dela Rosa
 * 
 * August 11, 2024
 */
#include "MovieFactory.h"
using namespace std;

/**
 * Creates and returns a new Movie object based on the specified genre type.
 * This factory method generates an instance of the appropriate subclass
 * (Classic, Drama, or Comedy) according to the provided type character.
 * If the type is unrecognized, an error message is printed and nullptr is returned.
 *
 * @param type The genre type of the movie ('C' for Classic, 'D' for Drama, 'F' for Comedy).
 * @param theStock The initial stock quantity of the movie.
 * @param theDirector The director of the movie.
 * @param theTitle The title of the movie.
 * @param actor The lead actor (used only for Classic movies).
 * @param month The release month (used only for Classic movies).
 * @param year The release year of the movie.
 * @return A pointer to the newly created Movie object, or nullptr if the genre type is invalid.
 */
Movie* MovieFactory::createMovie(char type, int theStock, const string &theDirector,
  const string &theTitle, const string &actor, int month, int year) {
    if(type == 'C') {
      return new Classic(type, theStock, theDirector, theTitle, actor, month, year);

    } else if(type == 'D') {
        return new Drama(type, theStock, theDirector, theTitle, year);

    } else if(type == 'F') {
        return new Comedy(type, theStock, theDirector, theTitle, year);

    } else {
        cout << "Error: unknown genre " << type << "." << endl;
        return nullptr;
    }
  }

