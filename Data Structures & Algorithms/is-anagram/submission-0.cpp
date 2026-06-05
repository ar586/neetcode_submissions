class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        map<char,int>mp1;
        for(int i=0;i<t.size();i++){
            mp1[t[i]]++;
        }
        
        return mp==mp1;
    }
};
