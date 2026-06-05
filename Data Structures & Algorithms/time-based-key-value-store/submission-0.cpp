class TimeMap {
public:
    TimeMap() {
        
    }
    map<int,map<string,string>>mp;
    void set(string key, string value, int timestamp) {
        mp[timestamp][key]=value;
    }
    
    string get(string key, int timestamp) {
        int n=timestamp;
        string ans="";
        while(n!=0){
            if(mp[n][key]!=""){
                ans= mp[n][key];
                break;
            }else{
                n--;
            }
        }
        return ans;
    }
};
