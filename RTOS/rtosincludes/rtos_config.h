
#ifndef RTOSINCLUDES_RTOS_CONFIG_H_
#define RTOSINCLUDES_RTOS_CONFIG_H_


#include "../includes/std_types.h"
#include "../includes/macros.h"


/*
 * to access any hardware register with no compiler optimization
 *
 */
#define _MEMORY_32_ACCESS(ADDRESSE)   (*( (volatile uint32_t *) (ADDRESSE) ))


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
#define CHECK_ERROR(X)    if((X)==1)while(1);



/*
 *Indicates the last element in the context switch (Execption Return)
 *
 */
#define STACK_CONTEXT_DATA_START		((uint32_t)(18U))


/*
 *  the word size is 4 bytes
 */
#define SINGLE_WORD_SIZE				((uint32_t)(4U))


/*
 *  the double word size is 8 bytes
 */
#define DOUBLE_WORD_SIZE				((uint32_t)(8U))




/*
 * Exception word shift related to the stack design
 * Exception Return value
 */
#define EXCEPTION_WORD_SHIFT				(0X01)
#define EXCEPTION_RETURN_PSP_UNPR_NO_FPU	((uint32_t)(0xFFFFFFFD))





/*
 * Control word shift related to the stack design
 * Control Register value
 */
#define CONTROL_WORD_SHIFT					(0X10)
#define CONTROL_REGISTER_PSP_UNPR_NO_FPU	((uint32_t)(0x03))





/*
 * Program Status Register word shift related to the stack design
 * Program Status Register value
 */
#define PSRT_WORD_SHIFT						(0X11)
#define PSR_THUMB_ACTION					((uint32_t)(0x01000000))






#endif
