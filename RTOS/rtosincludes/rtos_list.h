
#ifndef RTOSINCLUDES_RTOS_LIST_H_
#define RTOSINCLUDES_RTOS_LIST_H_


/*Includes*/

#include "../includes/macros.h"
#include "../includes/std_types.h"
#include "rtos_config.h"


/*Structures*/


/*
 * it is the list item which will represent the thread in any list(ready/waiting)
 *
 */

struct listItem_t
{

	struct listItem_t*  nextItem_ptr;	/*pointer to the next element*/
	struct listItem_t*  prevItem_ptr;	/*pointer to the previous element*/

	void*				  	 thread_ptr;	/*pointer to the list Item's thread structure*/
	void*					 list_ptr;		/*pointer to the list Item's list structure*/

};
typedef struct listItem_t RTOS_listItem_t;



/*
 * This is considered as the first element of the list(with the same priority level)
 * It is very similar to the head of a linked list
 *
 */
typedef struct
{
	RTOS_listItem_t* next_ptr;  /*pointer to the first element of the list*/
	RTOS_listItem_t* prev_ptr;	/*pointer to the last element of the list*/

}RTOS_listEnd_t;



/*
 * List structure which will resembles the ready/waiting list
 *
 * */
typedef struct
{
	uint32_t 		 number_elements;	/*number of elements of same priority in the list*/
	RTOS_listItem_t* index_ptr;			/*pointer to the index element of addition and selection of new items*/
	RTOS_listEnd_t	 list_end;			/*the head/end of the list*/

}RTOS_list_t;




/*Prototypes*/



/* ------------------------------------------------------------
 *Function-Name:RTOS_listInit
 *
 *Description: This function initializes and rtos list
 *
 *
 *Inputs: reference to a RTOS_list_t structure,
 *
 *
 *Returns: None
 *
 *--------------------------------------------------------------*/
void RTOS_listInit(RTOS_list_t*);




/* ------------------------------------------------------------
 *Function-Name:RTOS_listInit
 *
 *Description: This function inserts an element inside the list
 * 	  	  	   most probably at the end (index position)
 *
 *
 *Inputs: reference to a RTOS_list_t structure,
 *		  reference to a RTOS_listItem_t structure
 *
 *
 *Returns: None
 *
 *--------------------------------------------------------------*/
void RTOS_listInsert(RTOS_list_t*,RTOS_listItem_t*);




/* ------------------------------------------------------------
 *Function-Name:RTOS_listRemove
 *
 *Description: This function removes a list item from its list
 *
 *
 *Inputs: reference to a RTOS_listItem_t structure,
 *
 *
 *Returns: None
 *
 *--------------------------------------------------------------*/
void RTOS_listRemove(RTOS_listItem_t*);


#endif
