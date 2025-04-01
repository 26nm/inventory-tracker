#ifndef DRAMA_H
#define DRAMA_H

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
#include "Movie.h"
using namespace std;

class Drama : public Movie {
public:
  Drama();
  Drama(char, int, const string &, const string &, int);
  Drama(const Drama &);
  virtual void displayInfo() const override;
  virtual Drama &operator=(const Movie &) override;
  virtual bool operator==(const Movie &) const override;
  virtual bool operator!=(const Movie &) const override;
  virtual bool operator>(const Movie &) const override;
  virtual bool operator<(const Movie &) const override;
  virtual ~Drama();
};

#endif // DRAMA_H