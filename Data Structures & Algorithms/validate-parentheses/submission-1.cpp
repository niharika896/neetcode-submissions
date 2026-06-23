class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else {
                if(st.empty())return false;
                char ct = st.top();
                if ((c == ']' && ct != '[') || (c == '}' && ct != '{') || (c == ')' && ct != '('))
                    return false;
                st.pop();
            }
        }
        if(st.empty())return true;
        return false;
    }
};
