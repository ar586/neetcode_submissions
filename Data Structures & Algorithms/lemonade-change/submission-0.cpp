class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int fives=0;
       int tens=0;
       for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            fives++;
            continue;
        }else if(bills[i]==10){
            if(fives!=0){
                fives--;
                tens++;
                continue;
            }else{
                return false;
            }
        }else{
            if(fives>=1 && tens>=1){
                fives--;
                tens--;
                continue;
            }else if(fives>=3){
                fives=fives-3;
                continue;
            }else{
                return false;
            }
        }
       } 
       return true;
    }
};