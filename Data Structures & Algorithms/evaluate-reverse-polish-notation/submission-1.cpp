class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        
        for(auto str : tokens){
            if(str == "+" || str == "-"
                || str == "/" || str == "*" ){
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    int temp1;
                    if(str == "+"){
                        temp1 = num2 + num1;
                    }else if(str == "-"){
                        temp1 = num2 - num1;
                    }else if(str == "/"){
                        temp1 = num2 / num1;
                    }else{
                        temp1 = num2 * num1;
                    }
                    st.push(temp1);
            }else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
