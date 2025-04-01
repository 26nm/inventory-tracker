#ifndef MOVIE_H
#define MOVIE_H
/** 
 * Movie - This class serves as a base to represent a Movie and
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
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Movie {
protected:
  char genre;
  int stock;
  int yearReleased;
  string title;
  string director;

public:
  Movie();
  Movie(char, int, const string &, const string &, int);
  Movie(const Movie &);
  virtual void displayInfo() const = 0;
  virtual Movie &operator=(const Movie &) = 0;
  virtual bool operator==(const Movie &) const = 0;
  virtual bool operator!=(const Movie &) const = 0;
  virtual bool operator<(const Movie &) const = 0;
  virtual bool operator>(const Movie &) const = 0;
  virtual void borrowMovie();
  virtual void returnMovie();
  virtual char getGenre() const;
  virtual string getTitle() const;
  virtual string getDirector() const;
  virtual int getStock() const;
  virtual int getYearReleased() const;
  virtual ~Movie();
};

#endif // MOVIE_H
