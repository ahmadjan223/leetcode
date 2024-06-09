class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char chr:s){
            if(chr == '(' || chr == '{' || chr == '['){
                st.push(chr);
            }
            else{
                 if(st.empty() ||
                (chr == ')' && st.top() != '(' ) ||
                (chr == '}' && st.top() != '{' ) ||
                (chr == ']' && st.top() != '[' )
                ){
                    return false;
                 }
                st.pop();
            }
        }
        return st.empty();
    }
};
