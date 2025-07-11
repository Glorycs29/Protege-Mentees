// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1585983985/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //2 pointer
        //all +ve elements
        int lsum=0;
        int maxs=0;
        int rsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        maxs=lsum;
        int j=0;
        for(int i=k-1;i>=0;i--){
            //remove one ele from left and add 1 from right
            lsum-=cardPoints[i];
            rsum=rsum+cardPoints[n-1-j];
            j++;
            maxs=max(maxs,lsum+rsum);
        }
        return maxs;
    }
};
