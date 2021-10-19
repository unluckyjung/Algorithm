# 225. Implement Stack using Queues

## cpp-1
> 큐를 두개쓴 경우

```cpp
class MyStack {
public:
    
    queue<int> q;
    
    void push(int x) {
        queue<int> tmpQ;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            tmpQ.push(cur);
        }
        
        q.push(x);
        
        while(!tmpQ.empty()){
            int cur = tmpQ.front(); tmpQ.pop();
            q.push(cur);
        }
    }
    
    int pop() {
        int ret = q.front(); q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
```

## cpp-2
> 큐를 한개쓴 버전

```cpp
class MyStack {
public:
    
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
        for(int i = 0; i < (int)q.size() - 1; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ret = q.front(); q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
```