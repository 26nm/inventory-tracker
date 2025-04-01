#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

/**
 * MovieFactory - A utility class responsible for creating Movie objects based on the specified genre.
 * This class encapsulates the logic for generating different types of Movie instances,
 * ensuring that each genre is handled appropriately during the creation process.
 *
 * Nolan Dela Rosa
 * 
 * August 11, 2024
 */
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

class MovieFactory {
public:
  static Movie* createMovie(char, int, const string &,
    const string &, const string &, int, int);
};
#endif // MOVIEFACTORY_H