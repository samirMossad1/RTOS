
#ifndef RTOSINCLUDES_RTOS_CONFIG_H_
#define RTOSINCLUDES_RTOS_CONFIG_H_


#include "../includes/std_types.h"
#include "../includes/macros.h"


/*
*
*Maximum thread stack size is 1024 words
*Note: we will use double word stack alignment thus maximum size is 1024*8 bytes
*
**/
#define THREAD_STACK_SIZE			((uint32_t)(1024u))



/*
 *
 * We will set the number of priority levels to 16 level
 *
 */
#define THREAD_PRIORITY_LEVELS 		((uint32_t)(16u))


/*
 * Macros to enter a busy-wait condition to avoid
 * accessing null pointers(uninitialized)
 *
 * */
#define CHECK_ERROR(X)    if(X==1)while(1)




#endif
