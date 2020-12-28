/*
 * queue.h
 *
 * Created: 26-Dec-20 7:54:13 PM
 *  Author: MohamedMerdan
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#include "Std_Types.h"

typedef struct{
	uint8_ut* pQueue;
	uint8_ut bSize;
	uint8_ut qSize;
	uint8_ut index;
} Queue_Status_t;

void queue_Transverse(Queue_Status_t*, void(*pQT)(uint8_ut*));
void queue_Push(Queue_Status_t*, uint8_ut*);
uint8_ut* queue_Pop(Queue_Status_t*);

#endif /* QUEUE_H_ */