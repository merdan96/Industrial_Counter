/*
 * os.h
 *
 * Created: 21-Dec-20 8:10:09 PM
 *  Author: MohamedMerdan
 */ 


#ifndef OS_H_
#define OS_H_

#include "std_Types.h"
#include "OS_Config.h"

typedef enum{
	RUNNING,
	WAITING,
	BLOCKED
}OS_Task_Status_e;

typedef struct{
	OS_Task_Status_e status;
	uint8_ut priority;
	uint16_ut wait;
	uint16_ut period;
	void(*pTaskFunction)(void);
}OS_Task_t;

void QInit(uint8_ut*);

uint8_ut os_add_task(void(*pTask)(void), uint16_ut, uint8_ut);
#endif /* OS_H_ */