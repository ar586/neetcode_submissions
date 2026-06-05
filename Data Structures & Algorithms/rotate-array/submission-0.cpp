class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int p=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+p);
        reverse(nums.begin()+p,nums.end());
    }
};