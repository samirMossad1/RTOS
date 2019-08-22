

#include "../rtosincludes/rtos.h"


uint32_t svcEXEReturn;


#define SYSTEM_SVC_PRIORITY_0_MASK				(0X1FFFFFFF)
#define SYSTEM_PENDSV_PRIORITY_7_MASK			(0X000000E0)
#define SYSTEM_SYSTICK_PRIORITY_1_MASK			(0X20000000)
#define STACK_ALLIGNMENT_BIT					(9U)



static void Systick_Config(uint16_t);



void RTOS_init(void)
{


	/*Disable INTERRUPTS*/
	__disable_irq();

	/*Double Stack Alignment*/
	SET_BIT(SYSTEM_CONFIGURATION_CONTROL_REGISTER,STACK_ALLIGNMENT_BIT);


	/*Configure The Systick Timer*/
	Systick_Config(1);

	/*Configure The Priorities*/

	/*Systick Timer Priority*/
	SYSTEM_HANDLER_PRIORITY_2__REGISTER|=SYSTEM_SYSTICK_PRIORITY_1_MASK;

	/*SuperVisor Call Priority*/
	SYSTEM_HANDLER_PRIORITY_2__REGISTER &=SYSTEM_SVC_PRIORITY_0_MASK;


	/*Pendable Service Priority*/
	SYSTEM_HANDLER_PRIORITY_3_REGISTER|=SYSTEM_PENDSV_PRIORITY_7_MASK;

	/*Set The Base Priority*/
	__set_BASEPRI(0x02);

	/*Initialize the ready list*/
	RTOS_threadInitLists();

	/*Enable Interrupts*/
	__enable_irq();

}



void RTOS_SVC_Handler_main(uint32_t* svc_argument)
{


	uint8_t svc_number= ( (char*)&svc_argument[6] )[-2]; /*Stacked (PC-2) (which points to the svc instruction)*/


	switch(svc_number)
	{

	case 1 :
		RTOS_threadCreate((RTOS_thread_t*)&svc_argument[0],
				(RTOS_threadStack_t*)&svc_argument[1],
				(uint8_t)svc_argument[2],
				(void*)&svc_argument[3]);
		break;

	default:
		CHECK_ERROR(TRUE);
		break;
	}

}




static void Systick_Config(uint16_t reload_value)
{





}
