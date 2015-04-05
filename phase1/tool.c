// tool.c, 159

#include "spede.h"
#include "type.h"
#include "extern.h"

int EmptyQ(q_t *p){
	return (p->size == 0);// try <=0
}

int FullQ(q_t *p){
	return (p->size==MAX_PROC);
}


void MyBzero(q_t *p, int size) {//trying changing char to Q_t
	p->size = size;
	p->head = size;
	p->tail = size;
}

void EnQ(int pid, q_t *p) {
// ?????????????????????????????????????????????????
// show error msg and return if queue's already full
// needs coding
// ?????????????????????????????????????????????????

	if(FullQ(p) ){
		cons_printf("Que is full!\n");	
		return;
	}

	p->q[p->tail] = pid;
	p->tail +=1;
	
	if(p->tail >= MAX_PROC) p->tail=0;

	p->size +=1;
}

int DeQ(q_t *p) { // return -1 if q is empty
	int pid;
	if(EmptyQ(p)) return -1;////////try Empty(&p)
	pid = p->q[p->head];
	p->head +=1;
	if(p->head >= MAX_PROC) p->head=0;
	p->size -= 1;
	return pid;	
}
