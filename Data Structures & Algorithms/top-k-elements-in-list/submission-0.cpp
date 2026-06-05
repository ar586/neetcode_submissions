class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>checker;
       for(int i=0;i<nums.size();i++){
        checker[nums[i]]++;
       }
       vector<pair<int,int>> vec(checker.begin(), checker.end());
       sort(vec.begin(), vec.end(), cmp);
       vector<int>ans;
       reverse(vec.begin(),vec.end());
       for(int i=0;i<k;i++){
        ans.push_back(vec[i].first);
       }
       return ans;
    }
};