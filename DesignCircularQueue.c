typedef struct {
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->queue = (int*)malloc(sizeof(int) * k);
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        return false; 
    }
    obj->queue[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity; 
    obj->size++;
    return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false; 
    }
    obj->front = (obj->front + 1) % obj->capacity; 
    obj->size--;
    return true;
}
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1; 
    }
    return obj->queue[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1; 
    }
    int rearIndex = (obj->rear - 1 + obj->capacity) % obj->capacity; 
    return obj->queue[rearIndex];
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}
