class Solution {
public:
  
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            int k=nums[i];
            int count=0;
            while(st.find(k)!=st.end()){
               count++;
               maxi=max(maxi,count);
               k--;
            }
        }
        return maxi;
    }
};
