# 232. Implement Queue using Stacks

## CPP-1

```cpp
class MyQueue {
public:
    stack<int> output, input;

    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ret = peek();
        output.pop();
        return ret;
    }

    int peek() {
        if(output.empty()){
            while(!input.empty()){
                int cur = input.top();
                input.pop();
                output.push(cur);
            }
        }
        return output.top();
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};
```