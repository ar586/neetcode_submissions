class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0]){
                vector<int>temp;
                temp.push_back(ans.back()[0]);
                temp.push_back(max(ans.back()[1],intervals[i][1]));
                ans.pop_back();
                ans.push_back(temp);
            }else{
               ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
