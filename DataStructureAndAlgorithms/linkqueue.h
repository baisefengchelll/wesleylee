#define MAXQSIZE 100
#include <stdlib.h>
typedef int QElemType;
typedef struct Qnode
{
    QElemType data;
    struct Qnode *next;
} Qnode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void initLinkQueue(LinkQueue &lq)
{
    lq.front = lq.rear = new Qnode;
    if(!lq.front) exit(false);
    lq.front->next = nullptr;
}

void destroyQLinkQueue(LinkQueue &lq)
{
    while(lq.front){
        Qnode* p = lq.front->next;
    }
}