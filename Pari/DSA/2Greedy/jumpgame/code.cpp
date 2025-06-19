//link- https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //greedy
        int maxind=0;
        for(int i=0;i<nums.size();i++){
            if(maxind>=i)
            maxind=max(maxind, nums[i]+i);
            else{
                return false;
            }

        }
return true;
    }
};
