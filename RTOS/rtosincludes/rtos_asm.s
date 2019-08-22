
.syntax unified
.cpu cortex-m4
.thumb

.global RTOS_SVC_Handler
.global RTOS_PendSV_Handler

.text

.type RTOS_SVC_Handler, %function
RTOS_SVC_Handler:
    tst lr, #4                /* Test bit 2 of the link register to find current stack */
    ite eq                    /* eq when zero flag is set */
    mrseq r0, msp             /* msp when bit 2 is cleared */
    mrsne r0, psp             /* msp when bit 2 is set */
    ldr r1,=svcEXEReturn      /* Load the address of svcEXEReturn in r1 */
    str lr,[r1]               /* Store lr in svcEXEReturn */
    bl RTOS_SVC_Handler_main  /* Run C part of SVC Handler */
    ldr r1,=svcEXEReturn      /* Load the address of svcEXEReturn in r1 */
    ldr lr,[r1]               /* Load lr with updated svcEXEReturn value */
    bx lr                     /* Return */

.type RTOS_PendSV_Handler, %function
RTOS_PendSV_Handler:


    bx lr                        /* Return */
