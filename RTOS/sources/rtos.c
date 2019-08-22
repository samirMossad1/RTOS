

#include "../rtosincludes/rtos.h"


uint32_t svcEXEReturn;




void RTOS_SVC_Handler_main(uint32_t* svc_argument)
{


	uint8_t svc_number= ( (char*)svc_argument[6] )[-2]; /*Stacked (PC-2) (which points to the svc instruction)*/


	switch(svc_number)
	{

	case 1 :
		RTOS_threadCreate((RTOS_thread_t*)svc_argument[0],
				(RTOS_threadStack_t*)svc_argument[1],
				(uint8_t)svc_argument[2],
				(void*)svc_argument[3]);
		break;

	default:
		CHECK_ERROR(TRUE);
		break;
	}

}
