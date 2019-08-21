
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






#endif
