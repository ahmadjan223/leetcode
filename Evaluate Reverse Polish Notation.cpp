// note: reversed polish notation is type of expressing mathamatical expression, we use this notation bcz expression in this notation is very easy to evaluate with linear time complexity.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                if (token == "-") st.push(a - b);
                if (token == "*") st.push(a * b);
                if (token == "/") st.push(a / b);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
