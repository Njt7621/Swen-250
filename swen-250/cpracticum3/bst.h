#ifndef BT_H
#define BT_H

// Set up a boolean type for later use
#define True (1)
#define False (0)
typedef int bool;

/*
 * The binary tree node.
 */
struct tree_node
{
   int value;
   struct tree_node* left;
   struct tree_node* right;
};

// Rename struct tree_node* to tree to make typing easier
typedef struct tree_node* tree;

/*
 * Create a tree with the given value, left subtree, and right subtree
 */
tree bt_make (tree left, int value, tree right);

/*
 * Finds and returns the minimum valued node in the  BST
 */
tree find_min (tree bst);

/*
 * Insert a vlue into the tree in BST order
 */
tree insert (int value, tree tree);

/*
 * Removes the specified value from the BST
 */
tree delete (int value, tree bst);

/*
 * Search a BST for a value
 */
int search (int value, tree tree);

/*
 * Returns the string infix representation of the tree. 
 * Free the returned pointer after use.
 */
char* infix (tree tree);

/*
 * Create a tree with the given value, left subtree, and right subtree
 */
void print_infix (tree tree);

/*
 * Create a tree with the given value, left subtree, and right subtree
 */
void print_prefix_as_char (tree tree);

#endif