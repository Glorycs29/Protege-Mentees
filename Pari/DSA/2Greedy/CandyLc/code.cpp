
class Solution {
public:
    //brute T.C.->o(3n)+ SC=(2N)->O(2n)+ SC=O(n just storing acc. to left neighbours values)
    //MOST OPTIMAL -> Slope approach 
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1;
        int i=1;

        while( i<n){
            //no slope
            if(ratings[i]==ratings[i-1]){
                sum=sum+1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak=peak+1;
                sum+= peak;
                i++;
            }

            int down=1;
            while(i<n&& ratings[i]<ratings[i-1] ){
                
                sum+=down;
                i++;
                down=down+1;
            }

            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
    }
};
