class MyCircularQueue {
public:
        int front=-1;
        int rear=-1;
        int *queue ;
        int size;
    MyCircularQueue(int k) {
        queue=new int[k];
         size=k;
    }
    
    bool enQueue(int value) {
        int flag=0;
        if(isFull())
        {
            flag=0;
        }
        else if(rear==-1 && front==-1)
        {
            rear=front=0;
            flag=1;
        }
        else {
            rear=(rear+1)%size;
            flag=1;
        }
        if(flag==1)
        {
            queue[rear]=value;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deQueue() {
        int flag=0;
        if(isEmpty())
        {
            flag=0;
        }
        else if(front==rear)
        {
            front=rear=-1;
            flag=1;
        }
        else{
            front=(front+1)%size;
            flag=1;
        }
        if(flag==1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        else{
            return(queue[front]);
        }
        
    }
    
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        else{
            return(queue[rear]);
        }
    }
    
    bool isEmpty() {
        if(rear==-1 && front==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((rear+1)%size==front)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */