class MinStack {
    public:
        stack<long long> st;
        long long mini = INT_MAX;
        MinStack() {}
        
        void push(int val) {
            long long v = val;
            if(st.empty()){
                st.push(v);
                mini = v;
            }else{
                if(v > mini){
                    st.push(v);
                }else{
                    st.push(2LL*v - mini);
                    mini = v;
                }
            }
        }
        
        void pop() {
            if(st.top() > mini){
                st.pop();
            }else{
                mini = 2*mini - st.top();
                st.pop();
            }
        }
        
        int top() {
            if(st.top() > mini){
                return st.top();
            }else{
                return mini;
            }
        }
        
        int getMin() {
            return mini;
        }
    };