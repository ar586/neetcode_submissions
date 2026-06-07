class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int count = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] > intervals[i][0]) {
                count++;
                continue;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return count;
    }
};
