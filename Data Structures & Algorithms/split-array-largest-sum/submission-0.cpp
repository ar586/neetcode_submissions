class Solution {
public:
    int helper(vector<int>& nums, int p){
       int temp=0;
       int count=1;
       for(int i=0;i<nums.size();i++){
          if(temp+nums[i]<=p){
             temp+=nums[i];
          }else{
            count++;
            temp=nums[i];
          }
       }
       return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int h=0;
        for(int i=0;i<nums.size();i++){
            h+=nums[i];
        }
        int l=*max_element(nums.begin(),nums.end());
        int ans;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(helper(nums,mid)<=k){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};