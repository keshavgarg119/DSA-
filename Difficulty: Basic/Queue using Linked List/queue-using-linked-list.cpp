/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* temp = new QueueNode(x);
        if(front == nullptr) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code       
        if(front == nullptr) return -1;
        
        QueueNode* temp = front;
        front = front -> next;
        
        if(front==nullptr) {
            rear = nullptr;
        }
        int poppedData = temp->data;
        delete(temp);
        return poppedData;
        
        
    
         
}
