#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bst.h"

/**
 * Write the code to find and return a pointer to the minimum
 * value in a tree.
 */
tree find_min (tree bst) {
  //Null case
  if (bst == NULL) {
     return 0;
  }
  //Left subtree
  else if (bst->left == NULL) {
    return bst;
  }
  else {
  return find_min(bst->left);
  }  
}

/**
 * Creates a new tree with the supplied value,
 * left, and right subtrees.
 * 
 * DO NOT CHANGE THIS CODE
 */
tree bt_make (tree left, int value, tree right) 
{
   tree t;

   t = (tree) malloc (sizeof (struct tree_node));
   t->value = value;
   t->left = left;
   t->right = right;

   return t;
}

/**
 * Adds a value to the BST at the correct location.
 * 
 * DO NOT CHANGE THIS CODE
 */
tree insert (int value, tree bst) {

  if (bst == NULL) {
    return bt_make (NULL, value, NULL);
  }
  else if (value < bst->value) {
    bst->left = insert (value, bst->left);
  }
  else {
    bst->right = insert (value, bst->right);
  }

  return bst;
}

/**
 * Write the delete function for a binary search tree. This will require
 * handling the following scenarios.
 * 1. Tree is empty
 * 2. Value to delete is a leaf - set the node to null
 * 3. Value node has only a less or more sub-tree - remove the node from 
 *    the tree and return the new root of the sub-tree
 * 4. Value node has two children - find the min value of the more sub-tree
 *    Replace the value node's value with the min value and delete the min
 *    node.
 * 
 * In all cases you should free any deleted memory and you must return the 
 * root of the new subtree and link that back into the overall tree. 
 * (Pseudo-code template handles the re-linking for you)
 */
tree delete (int value, tree bst) 
{ 
   tree temp;
   /**
   * Replace the pseudo-code place holders with their correct values.
   * Complete the code based on the algorigthm described above
   * (also in the html file)
   */ 

  if (bst == NULL)
  {
    return bst;
  }
  if (value < bst->value)
  {
    bst->left = delete (value, bst->left);
  }
  else if (value > bst->value) 
  {
    bst->right = delete (value, bst->right);
  }
  else
  {
    if (bst->left == NULL && bst->right == NULL)
    {
      free(bst);
      bst = NULL;
    }
    else if (bst->left == NULL) 
    {
      temp = bst;
      bst = bst->right;
      free(bst);
    }
    else if (bst->right == NULL)
    {
      temp = bst; 
      bst = bst->left;
      free(bst); 
    }
    else
    {
      temp = find_min (bst->right);
      bst->value = temp->value;
      bst->right = delete (temp->value, bst-> right);
    }
  }

  return bst;
}

/**
 * Serches the BST for a specific value. Returns true
 * if the value is in the tree, false otherwise.
 *  
 * DO NOT CHANGE THIS CODE
 */
bool search (int value, tree bst)
{
  if (bst == NULL)
  {
    return False;
  }
  else if (value == bst->value)
  {
    return True;
  }
  else if (value < bst->value)
  {
    return search (value, bst->left);
  }
  else
  {
    return search (value, bst->right);
  }
}

/**
 * Returns a string representation of the BST in infix order. 
 * Memory reponsibility is transferred to the caller. 
 * I.E. free the returned string after use.
 * 
 * DO NOT CHANGE THIS CODE
 */ 
char* infix (tree bst) 
{
  char* string = NULL;

  if (bst != NULL)
  {
    char* left = infix (bst->left);
    char* value = malloc (10);
    sprintf (value, "%d ", bst->value);
    char* right = infix (bst->right);

    string = malloc (strlen (left) + strlen (value) + strlen (right));
    *string = '\0';
    strcat (string, left);
    strcat (string, value);
    strcat (string, right);

    free (left);
    free (value);
    free (right);
    return string;
  }

  string = malloc (1);
  *string = '\0';

  return string;
}

/**
 * Prings the BST values in infix order.
 * 
 * DO NOT CHANGE THIS CODE
 */
void print_infix (tree bst)
{
  if (bst != NULL)
  {
    print_infix (bst->left);
    printf ("%d ", bst->value);
    print_infix (bst->right);
  }
}

/**
 * Prints the BST in prefix order. Assumes all values 
 * are characters.
 * 
 * DO NOT CHANGE THIS CODE
 */
void print_prefix_as_char (tree bst)
{
  if (bst != NULL)
  {
    printf ("%c ", bst->value);
    print_prefix_as_char (bst->left);
    print_prefix_as_char (bst->right);
  }
}

