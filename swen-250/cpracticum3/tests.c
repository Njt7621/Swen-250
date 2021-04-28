#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simplectest.h"
#include "bst.h"

START_TESTS()
tree root = NULL;

root = insert (5, root);
root = insert (8, root);
root = insert (3, root);
root = insert (4, root);
root = insert (7, root);
root = insert (1, root);
root = insert (6, root);
root = insert (9, root);
root = insert (2, root);

START_TEST ("FindMin - NULL")
	tree root = NULL;
	tree min  = find_min (root);
	ASSERT_EQUALS (min, NULL);
END_TEST ()	

START_TEST ("FindMin - Single Node")
	tree root = insert (5, NULL);
	tree min  = find_min (root);
	ASSERT_EQUALS (min->value, 5);
END_TEST ()	

START_TEST ("FindMin - Left Child")
	tree root = insert (5, NULL);
	root = insert (3, root);
	tree min  = find_min (root);
	ASSERT_EQUALS (min->value, 3);
END_TEST ()	

START_TEST ("FindMin - Right Child")
	tree root = insert (5, NULL);
	root = insert (8, root);
	tree min  = find_min (root);
	ASSERT_EQUALS (min->value, 5);
END_TEST ()	

START_TEST ("FindMin - Full Tree")
	tree min = find_min (root);
	ASSERT_EQUALS (min->value, 1);
END_TEST ()	

START_TEST ("Delete - NULL")
	tree root = NULL;
	root = delete (9, root);
	ASSERT_EQUALS (strcmp ("", infix (root)), 0);
END_TEST ()	

START_TEST ("Delete - Not In Tree")
	root = delete (10, root);
	char* string = infix (root);
	ASSERT_EQUALS (strcmp ("1 2 3 4 5 6 7 8 9 ", string), 0);
	free (string);
END_TEST ()	

START_TEST ("Delete - No Children")
	root = delete (9, root);
	char* string = infix (root);
	ASSERT_EQUALS (strcmp ("1 2 3 4 5 6 7 8 ", string), 0);
	free (string);
END_TEST ()	

START_TEST ("Delete - Left Child Only")
	root = delete (8, root);
	char* string = infix (root);
	ASSERT_EQUALS (strcmp ("1 2 3 4 5 6 7 ", string), 0);
	free (string);
END_TEST ()	

START_TEST ("Delete - Right Child Only")
	root = delete (1, root);
	char* string = infix (root);
	ASSERT_EQUALS (strcmp ("2 3 4 5 6 7 ", string), 0);
	free (string);
END_TEST ()	

START_TEST ("Delete - Both Children")
	root = delete (5, root);
	char* string = infix (root);
	ASSERT_EQUALS (strcmp ("2 3 4 6 7 ", string), 0);
	free (string);
END_TEST ()	

END_TESTS()


