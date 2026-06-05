class Solution {
public:
    int helper(vector<int>& weights, int days,int c){
          int sum=weights[0];
          int count=1;
          for(int i=1;i<weights.size();i++){
            if(sum+weights[i]<=c){
                sum+=weights[i];
                continue;
            }else{
                count++;
                sum=weights[i];
            }
          }
          return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int h=sum;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(helper(weights,days,mid)<=days){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};