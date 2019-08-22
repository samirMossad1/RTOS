

.syntax unified
.cpu cortex-m4
.thumb

.global RTOS_SVC_threadCreate

.text


.type RTOS_SVC_threadCreate, %function
RTOS_SVC_threadCreate:
    svc 1
    bx lr

