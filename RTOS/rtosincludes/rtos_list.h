
#ifndef RTOSINCLUDES_RTOS_LIST_H_
#define RTOSINCLUDES_RTOS_LIST_H_


/*Includes*/





/*Structures*/


/*
 * it is the list item which will represent the thread in any list(ready/waiting)
 *
 */
typedef struct
{

	struct RTOS_listItem_t * nextItem_ptr;	/*pointer to the next element*/
	struct RTOS_listItem_t * prevItem_ptr;	/*pointer to the previous element*/

	void*				  	 thread_ptr;	/*pointer to the list Item's thread structure*/
	void*					 list_ptr;		/*pointer to the list Item's list structure*/

}RTOS_listItem_t;


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





#endif
