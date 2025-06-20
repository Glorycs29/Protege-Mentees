//link- https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        //o(n) greedy soln
        int l=0,r=0;
        int jumps=0;
        int n=nums.size();
       while(r<n-1){ //not n as cant take any jumps from n-1 index
        int farthest=0;
        for(int i=l;i<=r;i++){
            farthest=max(farthest, i+nums[i]);
        }   
        l=r+1;
        r=farthest;
    jumps+=1;
       }
       return jumps;
    }
};  
