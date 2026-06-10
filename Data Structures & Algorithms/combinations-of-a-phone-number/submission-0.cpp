class Solution {
public:
    void finder(int ind,unordered_map<int, string> &mp,string &digits,string &temp,vector<string>&ans){
         if(ind>=digits.size()){
            ans.push_back(temp);
            return;
         }
         for(int i=0;i<mp[digits[ind]-'0'].size();i++){
            temp.push_back(mp[digits[ind]-'0'][i]);
            finder(ind+1,mp,digits,temp,ans);
            temp.pop_back();
         }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        unordered_map<int, string> mp = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};   
      vector<string>ans;
      string temp;
      finder(0,mp,digits,temp,ans);
      return ans;
    }
};
