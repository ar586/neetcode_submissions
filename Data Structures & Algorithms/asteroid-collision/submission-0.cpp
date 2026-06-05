class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {

            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {

                bool destroyed = false;

                while(!st.empty() && st.top() > 0) {

                    if(st.top() > abs(asteroids[i])) {
                        destroyed = true;
                        break;
                    }
                    else if(st.top() == abs(asteroids[i])) {
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else {
                        st.pop();
                    }
                }

                if(!destroyed) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};