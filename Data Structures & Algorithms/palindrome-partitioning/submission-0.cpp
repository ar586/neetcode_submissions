class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void finder(int ind, string &s, vector<vector<string>>& ans,
                string temp, vector<string>& temp1) {
        if(ind == s.size()) {
            if(isPalindrome(temp)) {
                temp1.push_back(temp);
                ans.push_back(temp1);
                temp1.pop_back();
            }
            return;
        }
        finder(ind + 1, s, ans, temp + s[ind], temp1);
        if(isPalindrome(temp)) {
            temp1.push_back(temp);
            string next(1, s[ind]);
            finder(ind + 1, s, ans, next, temp1);
            temp1.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp1;
        string temp(1, s[0]);
        finder(1, s, ans, temp, temp1);
        return ans;
    }
};