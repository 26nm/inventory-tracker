#ifndef CLASSIC_H
#define CLASSIC_H

/**
 * Classic - A subclass of Movie that represents classic genre films.
 * This class extends the base Movie class to include specific features
 * or functionality related to classic films, while inheriting
 * common attributes and methods from Movie.
 *
 * Nolan Dela Rosa
 *
 * August 9, 2024
 */
#include "Movie.h"
#include <vector>
using namespace std;

class Classic : public Movie {
  private:
    string majorActor;
    int monthReleased;

  public:
    Classic();
    Classic(char, int, const string &, const string &, const string &, int, int);
    Classic(const Classic &);
    int getMonthReleased() const;
    string getMajorActor() const;
    virtual void displayInfo() const override;
    virtual Classic &operator=(const Movie &) override;
    virtual bool operator==(const Movie &) const override;
    virtual bool operator!=(const Movie &) const override;
    virtual bool operator>(const Movie &) const override;
    virtual bool operator<(const Movie &) const override;
    virtual ~Classic();
};

#endif // CLASSIC_H