/*
 * queue.c
 *
 * Created: 26-Dec-20 9:27:08 PM
 *  Author: MohamedMerdan
 */ 

#include "queue.h"

void queue_Transverse(Queue_Status_t* pQStatus, void(*pQT)(uint8_ut*)){
	for(uint8_ut i = 0u; i < (pQStatus -> qSize); i++){
		(*pQT)((pQStatus -> pQueue) + i * (pQStatus -> bSize));
	}
}
void queue_Push(Queue_Status_t* queue_status, uint8_ut* queue_entry){
	*((uint8_ut*)((queue_status -> pQueue) + (queue_status -> index))) = *queue_entry;//to be modified for multi-byte structures
	(queue_status -> index)++;
}
uint8_ut* queue_Pop(Queue_Status_t* queue_status){
	*((uint8_ut*)((queue_status -> pQueue) + (queue_status -> index))) = *((uint8_ut*)(queue_status -> pQueue));//to be modified for multi-byte structures
	uint8_ut i;
	for(i = 1;i < (queue_status -> index);i++){
		*((uint8_ut*)((queue_status -> pQueue) + i - 1)) = *((uint8_ut*)((queue_status -> pQueue) + i));//to be modified for multi-byte structures
	}
	(queue_status -> index)--;
	return ((uint8_ut*)((queue_status -> pQueue) + (queue_status -> index) + 1));
}
