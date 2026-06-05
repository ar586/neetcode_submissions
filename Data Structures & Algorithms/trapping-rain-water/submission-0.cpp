class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pre(height.size());
        vector<int>post(height.size());
        int g1=INT_MIN;
        for(int i=0;i<height.size();i++){
              pre[i]=g1;
              g1=max(g1,height[i]);
        }
        int g2=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
              post[i]=g2;
              g2=max(g2,height[i]);
        }
        int ans=0;
        for(int i=1;i<height.size()-1;i++){
            if(min(pre[i],post[i])-height[i]>0){
                ans+=min(pre[i],post[i])-height[i];
            }else{
                continue;
            }
        }
        return ans;
    }
};
