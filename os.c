/*
 * os.c
 *
 * Created: 26-Dec-20 9:53:47 PM
 *  Author: MohamedMerdan
 */ 
#include "os.h"
#include "queue.h"

static uint8_ut os_task_queue[OS_SCHEDULER_MAX_TASKS] = {0};
static Queue_Status_t os_task_queue_status = {(uint8_ut*)(os_task_queue), sizeof(*os_task_queue), OS_SCHEDULER_MAX_TASKS, 0};

static OS_Task_t tasks_vector[OS_SCHEDULER_MAX_TASKS];
static uint8_ut tasks_index = 0;

void QInit(uint8_ut* queue_entry){
	*queue_entry = 0xFF;
}

uint8_ut os_add_task(void(*pTask)(void), uint16_ut period, uint8_ut priority){
	tasks_vector[tasks_index].status = BLOCKED;
	tasks_vector[tasks_index].priority = priority;
	tasks_vector[tasks_index].wait = 0;
	tasks_vector[tasks_index].period = period;
	tasks_vector[tasks_index].pTaskFunction = pTask;
	return ++tasks_index;
}