/*
Implement a stack with min() function, which will return the smallest number in the stack.
It should support push, pop and min operation all in O(1) cost.

min operation will never be called if there is no number in the stack
*/

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
        array = new int [1000];
        min_ = new int [1000];
        top = -1;
    }

    void push(int number) {
        // write your code here
        if(++top > 1000)
            return;
            
        array[top] = number;
        if(top == 0){
            min_[top] = number;
            return;
        }
        
        if(top > 0 && number < min_[top-1])
            min_[top] = number;
        else
            min_[top] = min_[top-1];
    }

    int pop() {
        // write your code here
        if(top < 0)
            return -1;
        
        return array[top--];
    }

    int min() {
        // write your code here
        return min_[top];
    }
    
private:
    int *array;
    int *min_;
    int top;
};