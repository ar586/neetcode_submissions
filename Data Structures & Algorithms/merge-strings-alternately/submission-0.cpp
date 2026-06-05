class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string p="";
        while(i<word1.size() && j<word2.size()){
          p+=word1[i];
          p+=word2[j];
          i++;
          j++;
        }
        while(i<word1.size()){
          p+=word1[i];
          i++;
        }
        while(j<word2.size()){
          p+=word2[j];
          j++;
        }
        return p;
    }
};