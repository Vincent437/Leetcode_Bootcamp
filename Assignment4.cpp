class MyQueue {
    public:
        stack<int> s;
        stack<int> tmp;
    
        MyQueue() {}
        
        void push(int x) {
            while (!s.empty()) {  
                tmp.push(s.top());
                s.pop();
            }
            s.push(x);  // 把新元素放入 s
            while (!tmp.empty()) {  // 再把 tmp 里的数据放回 s
                s.push(tmp.top());
                tmp.pop();
            }
        }
        
        int pop() {
            int t = s.top();
            s.pop();
            return t;
        }
        
        int peek() {
            return s.top();
        }
        
        bool empty() {
            return s.empty();
        }
    };