class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n1+n2);
            }else if(tokens[i]=="-"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2-n1);
            }else if(tokens[i]=="*"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2*n1);
            }else if(tokens[i]=="/"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2/n1);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
