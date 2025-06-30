class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* temp = new StackNode(x);
        temp->next = top;
        top = temp;
        
        
    }

    int pop() {
        
        // code here
        if(top == nullptr) return -1;
        StackNode* temp = top;
        int val = top->data;
        top = top->next;
        delete(temp);
        return val;
    }

    MyStack() { top = NULL; }
};