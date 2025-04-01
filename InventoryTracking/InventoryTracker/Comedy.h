#ifndef COMEDY_H
#define COMEDY_H

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
#include "Movie.h"
using namespace std;

class Comedy : public Movie {
public:
  Comedy();
  Comedy(char, int, const string &, const string &, int);
  Comedy(const Comedy &);
  virtual void displayInfo() const override;
  virtual Comedy &operator=(const Movie &) override;
  virtual bool operator==(const Movie &) const override;
  virtual bool operator!=(const Movie &) const override;
  virtual bool operator>(const Movie &) const override;
  virtual bool operator<(const Movie &) const override;
  virtual ~Comedy();
};

#endif // COMEDY_H