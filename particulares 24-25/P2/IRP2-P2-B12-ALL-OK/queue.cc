#include "queue.h"
#include "lib/error.h"

QueuePtr queueCreate(){
	QueuePtr ptr = new Queue;
	ptr->l.head = nullptr; // listInit(&(ptr->l));
	return ptr;	
}

void queueEnqueue(QueuePtr q, Element x){
	if(q){
		listInsert(&(q->l), x, listSize(&(q->l)) + 1);
	}
}

Element queueHead(QueuePtr q){
	Element key = ' ';
	if(q == nullptr || q->l.head == nullptr){
		set_error(1);
	}
	else{
		// key = q->l.head->key;
		key = listRetrieve(&(q->l), 1)->key;
	}
	return key;
}

Element queueDequeue(QueuePtr q){
	Element key = ' ';
	if(q == nullptr || q->l.head == nullptr){
		set_error(1);
	}
	else{
		// key = q->l.head->key;
		key = listRetrieve(&(q->l), 1)->key;
		listRemove(&(q->l), 1);
	}
	return key;
}

// cantame me dijiste cantame...!!
bool queueEmpty(QueuePtr q){
	return q && !(q->l.head);
}



