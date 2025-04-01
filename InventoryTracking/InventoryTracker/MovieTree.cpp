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
#include "MovieTree.h"
using namespace std;

/**
 * Constructs an empty binary tree.
 * Initializes the binary tree with no nodes, setting
 * the root to nullptr. This creates an empty tree
 * that can have nodes added to it later.
 */
MovieTree::MovieTree() 
  : root(nullptr) { 
}

/**
 * Inserts an element into this binary tree.
 * If the provided value is nullptr,
 * insertion fails and returns false.
 *
 * @param value The Movie pointer to insert into the binary tree.
 * @return true if insertion is successful, false otherwise
 * (e.g., if value is nullptr).
 */
bool MovieTree::insert(Movie *value) {
  if (value == nullptr) {
    return false;
  }

  return insertInMovieTree(root, value);
}

/**
 * Recursively inserts a NodeData value into the binary tree.
 * If the value is already present, it does not insert it again.
 *
 * @param current The current node in the binary tree.
 * @param value   The value to insert into the binary tree.
 * @return true if the value was successfully inserted, false
 * if it already exists.
 */
bool MovieTree::insertInMovieTree(Node *&current, Movie *value) {
  if (current == nullptr) {
    current = new Node;
    current->data = value;
    return true;

  } else if (*value < *current->data) {
      return insertInMovieTree(current->left, value);

  } else if (*value > *current->data) {
      return insertInMovieTree(current->right, value);

  } else {
      return false;
  }
}

/**
 * Retrieves the Movie object matching the target's reference
 * from the tree.
 *
 * @param target The Movie object to search for.
 * @param found A reference to a pointer that will hold the found
 *              Movie object, if found.
 * @return True if the target NodeData object is found in the tree;
 *         false otherwise.
 */
bool MovieTree::retrieve(const Movie &target, Movie *&found) const {
  return find(root, target, found);
}

/**
 * Recursively finds the Node containing the target
 * NodeData object in the tree.
 *
 * @param current The current Node being examined in the recursion.
 * @param target The Movie object to search for.
 * @param found A reference to a pointer that will hold
 *              the found Movie object, if found.
 * @return True if the target Movie object is found in the tree;
 *         false otherwise.
 */
bool MovieTree::find(Node *current, const Movie &target, Movie *&found) const {
  if (current == nullptr) {
    found = nullptr;
    return false;

  } else if (*current->data == target) {
      found = current->data;
      return true;

  } else if (target < *current->data) {
      return find(current->left, target, found);
      
  } else {
      return find(current->right, target, found);
  }
}

/**
 * Prints the contents of the MovieTree.
 * Uses inorder traversal to print nodes in sorted order.
 */
void MovieTree::display() const {
  displayHelper(root);
}

/**
 * Recursively performs an inorder traversal of the MovieTree
 * starting from the given node. Prints each node's data
 * in sorted order.
 * 
 * * @param current The current node in the traversal.
 */
void MovieTree::displayHelper(Node *current) const {
  if(current != nullptr) {
    displayHelper(current->left);
    current->data->displayInfo();
    displayHelper(current->right);
  }
}

/**
 * Empties the entire MovieTree by recursively deleting all nodes.
 * This function initiates the clearing process starting from the root of the tree.
 */
void MovieTree::makeEmpty() {
  clear(root);
}

/**
 * Recursively clears the MovieTree by deallocating all nodes.
 *
 * @param current The current node being cleared.
 */
void MovieTree::clear(Node *&current) {
  if (current != nullptr) {
    clear(current->left);
    clear(current->right);
    delete current->data;
    delete current;
    current = nullptr;
  }
}

/**
 * Class Destructor
 */
MovieTree::~MovieTree() { clear(root); }

