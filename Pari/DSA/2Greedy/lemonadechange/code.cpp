//link- https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, tens=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) five+=5;
            else if(bills[i]==10){
                if(five<5) return false;
                else{
                    tens+=10;
                    five-=5;
                }
            }
            else { //=20
              
                 if(five>=15){
                    five-=15;
                 }
                  else  if(tens>=10 && five>=5) {
                    tens-=10;
                    five-=5;
                }
                 else return false;
            }
        }
        return true;
    }
};
