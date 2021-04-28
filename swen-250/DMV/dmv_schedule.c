/***
 * Functions for the DMV customer scheduling and service application.
 * Implementation file.
 ***/

#include <stdlib.h>
#include "dmv_schedule.h"

/*
 * Actual definition of the line array of service lines.
 */
struct service_line line[NLINES] ;

/*
 *
 *Accidentally erased these comments
 *
 *
 */
void init_service_lines() {
   // initialize the line array
   struct service_line a_line;
   struct service_line b_line;
   struct service_line c_line;

   char x ='A', y ='B', z ='C';
   a_line.priority = x;
   b_line.priority = y;
   c_line.priority = z;

   a_line.head_of_line = NULL;
   b_line.head_of_line = NULL;
   c_line.head_of_line = NULL;

   line[0] = a_line;
   line[1] = b_line;
   line[2] = c_line;
   
}

/*
 * Return the next ticket number.
 * 	The first customer gets ticket number 1.
 *	The number increases by 1 on each call.
 * Local (static) int ticket holds the current ticket value.
 */
static int ticket = 1;
int next_ticket() {
   int curr_t  = ticket;
  
   ticket++;
   return curr_t;

}

/*
 * A new customer arrives with the given <priority> and
 * <ticket_number>. The customer is placed at the end of
 * the appropriate service line.
 */
void new_customer(char priority, int ticket_number) {
   struct customer* new_cust = malloc(sizeof(struct customer));
   struct customer* curr_cust = malloc(sizeof(struct customer));
   int line_num;
   
   new_cust->ticket_number = ticket_number;
   new_cust->next_customer = NULL;


   //Find which service line
   if( priority == 0) {
      line_num = 0;
   } 
   else if ( priority == 1) {
      line_num = 1;
   }
   else {
      line_num = 2;
   }

   //check head of list
   if(line[line_num].head_of_line == NULL) {
      line[line_num].head_of_line = new_cust;
   }
   else{
      //place new_cust at the end of list
      curr_cust = line[line_num].head_of_line;

      while(curr_cust->next_customer != NULL) {
        curr_cust = curr_cust->next_customer;   
      }
       curr_cust->next_customer = new_cust;
   }
}

/*
 * Return the ticket number of the first customer in the
 * line for <priority> after removing the customer from the
 * associated service_line.
 *
 * Return NO_CUSTOMER if there are no customers in the indicated line.
 */
int serve_customer(char priority) {
	return 0 ; // Placeholder for your code.
}

/*
 * Return the ticket number of the first customer in the highest
 * priority line that has customers after removing the customer
 * from the line. 'A' is highest priority and 'C' is lowest.
 *
 * Return NO_CUSTOMER if there are no customers in any of the lines.
 *
 * Example: if there are 0 customers in the 'A' line, 3 customers in the 'B'
 *          line and 2 customers in the 'C' line, then the first customer in
 *          the 'B' line would be removed and his/her ticket number returned.
 */
int serve_highest_priority_customer() {
	return 0 ; // Placeholder for your code
}

/*
 * Return the number of customers in the service line for <priority>
 */
int customer_count(char priority) {
	return 0 ; // Placeholder for your code.
}

/*
 * Return the number of customers in all service lines.
 */
int customer_count_all() {
	return 0 ; // Placeholder for your code.
}
