
#ifndef RTOSINCLUDES_RTOS_THREAD_H_
#define RTOSINCLUDES_RTOS_THREAD_H_


/*Includes*/

#include "../includes/std_types.h"
#include "../includes/macros.h"
#include "rtos_list.h"
#include "rtos_config.h"



/*Structures*/

/*
 *
 * This is the thread structure which resembles a thread/task
 *
 */
typedef struct
{

	uint32_t stack_ptr;		/*The thread stack pointer*/
	uint32_t priority;		/*The thread priority level*/
	RTOS_listItem_t item;   /*The thread item which will be placed inside the ready list*/


}RTOS_thread_t;



/*
 * This is the stack structure for any thread which resemble the thread Stack space
 *
 */
typedef struct
{

	uint64_t threadStack[THREAD_STACK_SIZE]; /*Double word(4Bytes) alignment,
											   Stack size=1024*8 Bytes per thread*/

}RTOS_threadStack_t;



/*Prototypes*/


/* ------------------------------------------------------------
 *Function-Name:RTOS_threadCreate
 *
 *Description: This function creates a new thread
 *
 *Inputs: reference to a RTOS_thread_t structure,
 *		  reference to a RTOS_threadStack_t structure,
 *		  Priority number,
 *		  void pointer (Pointer to the task/thread function)
 *
 *Returns: None
 *
 *--------------------------------------------------------------*/
void RTOS_threadCreate(RTOS_thread_t*,RTOS_threadStack_t*,uint16_t,void*);


/* ------------------------------------------------------------
 *Function-Name:RTOS_SVC_threadCreate
 *
 *Description: This function issues SVC interrupt which calls the RTOS_threadCreate,
 *			   function to create a new thread
 *
 *Inputs: reference to a RTOS_thread_t structure,
 *		  reference to a RTOS_threadStack_t structure,
 *		  Priority number,
 *		  void pointer (Pointer to the task/thread function)
 *
 *Returns: None
 *
 *--------------------------------------------------------------*/

void RTOS_SVC_threadCreate(RTOS_thread_t*,RTOS_threadStack_t*,uint16_t,void*);





#endif
