class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        bool active = true;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        while (i < intervals.size()) {
            if (ans.size() == 0) {
                if (active && newInterval[0] < intervals[i][0]) {
                    ans.push_back(newInterval);
                    active = false;
                } else {
                    ans.push_back(intervals[i]);
                    i++;
                }
            } else {
                if (active && ans.back()[1] >= newInterval[0]) {
                    active = false;
                    vector<int> temp;
                    temp.push_back(ans.back()[0]);
                    temp.push_back(max(ans.back()[1], newInterval[1]));
                    ans.pop_back();
                    ans.push_back(temp);
                } else if (active && newInterval[0] < intervals[i][0]) {
                    active = false;
                    ans.push_back(newInterval);
                } else if (ans.back()[1] >= intervals[i][0]) {
                    vector<int> temp;
                    temp.push_back(ans.back()[0]);
                    temp.push_back(max(ans.back()[1], intervals[i][1]));
                    ans.pop_back();
                    ans.push_back(temp);
                    i++;
                } else {
                    ans.push_back(intervals[i]);
                    i++;
                }
            }
        }
        if (active) {
            if (ans.back()[1] >= newInterval[0]) {
                active = false;
                vector<int> temp;
                temp.push_back(ans.back()[0]);
                temp.push_back(max(ans.back()[1], newInterval[1]));
                ans.pop_back();
                ans.push_back(temp);
            } else {
                active = false;
                ans.push_back(newInterval);
            }
        }
        return ans;
    }
};
