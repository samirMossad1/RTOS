
#ifndef INCLUDES_RTOS_CONFIG_H_
#define INCLUDES_RTOS_CONFIG_H_



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





#endif
