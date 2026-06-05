class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i = 0; i < operations.size(); i++) {

            if(operations[i] != "+" && operations[i] != "C" && operations[i] != "D") {

                st.push(stoi(operations[i]));

            } else if(operations[i] == "+") {

                int n1 = st.top();
                st.pop();

                int n2 = st.top();

                st.push(n1);

                st.push(n1 + n2);

            } else if(operations[i] == "C") {

                st.pop();

            } else {

                int n3 = st.top();

                st.push(n3 * 2);
            }
        }

        int ans = 0;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};