#ifndef MOVIETREE_H
#define MOVIETREE_H

/**
 * MovieTree - a class representing a dynamically allocated binary tree.
 * This class has been modified from the original BinTree class
 * to allow efficient storage, insertion, retrieval, and deletion of 
 * Movie objects in a hierarchical structure.
 *
 * Nolan Dela Rosa
 *
 * August 10, 2024
 */
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include <iostream>
using namespace std;

class MovieTree {
private:
  struct Node {
    Movie* data = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
  };
  Node* root;
  bool insertInMovieTree(Node *&, Movie *);
  bool find(Node *, const Movie &, Movie *&) const;
  void displayHelper(Node *) const;
  void clear(Node *&);

public:
  MovieTree();
  ~MovieTree();
  bool insert(Movie*);
  bool retrieve(const Movie &, Movie *&) const;
  void display() const;
  void makeEmpty();
};

#endif // MOVIETREE_H