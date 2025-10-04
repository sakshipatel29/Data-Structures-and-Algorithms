#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MyStack {
    public:
        queue<int> q;
        int size = 0;
        MyStack() {
        }
        
        void push(int x) {
            if(size == 0){
                q.push(x);
                size++;
            }else{
                q.push(x);
                for(int i = 1; i <= size; i++){
                    q.push(q.front());
                    q.pop();
                }
                size++;
            }
        }
        
        int pop() {
            if(size == 0) return NULL;
            int x = q.front();
            q.pop();
            size--;
            return x;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };
