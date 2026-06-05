class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;

        int i = 0;
        int p = 0;

        while (p <= k && p < nums.size()) {

            if (st.find(nums[p]) != st.end()) {
                return true;
            } else {
                st.insert(nums[p]);
                p++;
            }
        }

        while (p < nums.size()) {

            st.erase(nums[i]);
            i++;

            if (st.find(nums[p]) != st.end()) {
                return true;
            } else {
                st.insert(nums[p]);
                p++;
            }
        }

        return false;
    }
};