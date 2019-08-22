/*
 * rtos.h
 *
 *  Created on: Aug 21, 2019
 *      Author: Samir Mossad
 */

#ifndef RTOSINCLUDES_RTOS_H_
#define RTOSINCLUDES_RTOS_H_


#include "rtos_thread.h"
#include "rtos_list.h"









/* ------------------------------------------------------------
 *Function-Name:RTOS_threadInitLists
 *
 *Description: This function is to be branched to from the SVC handler
 *			   it will extract the SVC number
 *			   based on this number it will call other functions
 *
 *Inputs:	reference to uint32_t (The process stack pointer addresse)
 *
 *Returns: None
 *
 *--------------------------------------------------------------*/
void RTOS_SVC_Handler_main(uint32_t*);


#endif /* RTOSINCLUDES_RTOS_H_ */
