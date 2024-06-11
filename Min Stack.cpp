class MinStack {
    vector<int> st;
    vector<int> min;
public:
    MinStack() {
        // Initialize min stack with a large initial value to handle empty comparisons
        min.push_back(INT_MAX);
    }

    void push(int val) {
        st.push_back(val);
        if (val <= min.back()) {
            min.push_back(val);
        }
    }

    void pop() {
        if (st.back() == min.back()) {
            min.pop_back();
        }
        st.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return min.back();
    }
};
