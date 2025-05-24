class MyStack {
    int* arr;
    int top1=-1;
    public:
    
    MyStack() {
        arr=new int[100];
    }
    
    void push(int x) {
        top1++;
        arr[top1]=x;
    }
    
    int pop() {
        top1--;
        return arr[top1+1];
    }
    
    int top() {
        return arr[top1];
    }
    
    bool empty() {
        return top1==-1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */