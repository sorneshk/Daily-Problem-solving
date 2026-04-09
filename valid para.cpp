class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch); continue;
            }
            if(st.empty()) return 0;
            else if((ch==')' && st.top()=='(') || (ch=='}' && st.top()=='{') || (ch==']' && st.top()=='[')){
                
                st.pop(); continue;
            }
            else return 0;
        }
        return st.empty();
    }
};