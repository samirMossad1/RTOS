

/*Includes*/

#include "../rtosincludes/rtos_thread.h"




static RTOS_list_t readyList_g[THREAD_PRIORITY_LEVELS];

static RTOS_thread_t* runningThread_gptr;

static uint8_t RTOS_currentTopPriority=THREAD_PRIORITY_LEVELS-1;



void RTOS_threadCreate(RTOS_thread_t* thread_ptr,RTOS_threadStack_t* threadStack_ptr,uint8_t priority_t,void* threadFun_ptr)
{


	/*Check Errors*/
	CHECK_ERROR(thread_ptr==NULL_PTR);
	CHECK_ERROR(threadStack_ptr==NULL_PTR);
	CHECK_ERROR(threadFun_ptr==NULL_PTR);
	CHECK_ERROR(priority_t>((uint8_t)(0xF)));


	thread_ptr->stack_ptr=((uint32_t)threadStack_ptr+(THREAD_STACK_SIZE*DOUBLE_WORD_SIZE)-(STACK_CONTEXT_DATA_START*SINGLE_WORD_SIZE));

	_MEMORY_32_ACCESS(&thread_ptr->stack_ptr)=EXCEPTION_RETURN_PSP_UNPR_NO_FPU;

	_MEMORY_32_ACCESS(&(thread_ptr->stack_ptr) + (EXCEPTION_WORD_SHIFT<<2) )=CONTROL_REGISTER_PSP_UNPR_NO_FPU;

	_MEMORY_32_ACCESS((thread_ptr->stack_ptr) + (CONTROL_WORD_SHIFT<<2) )=(uint32_t)threadFun_ptr;

	_MEMORY_32_ACCESS((thread_ptr->stack_ptr) +   (PSRT_WORD_SHIFT<<2) )=PSR_THUMB_ACTION;


	thread_ptr->priority=priority_t;
	thread_ptr->item.list_ptr=NULL_PTR;
	thread_ptr->item.thread_ptr=(void*)(thread_ptr);


	RTOS_listInsert(&readyList_g[priority_t],&thread_ptr->item);


	if(priority_t<RTOS_currentTopPriority)
	{
		RTOS_currentTopPriority=priority_t;
	}


	if(runningThread_gptr!=NULL_PTR)
	{

		if(priority_t < runningThread_gptr->priority)
		{
			/*Context Switch : Trigger the Pendable Service Interrupt Handler*/

			//SET_BIT(NVIC_INT_CTRL_R,THE_PEND_SV_INT_BIT);

		}
		else
		{


		}

	}
	else
	{


	}



}
