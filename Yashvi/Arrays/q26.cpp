/* Remove duplicates from arrays 
Question Link (LeetCode) - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=problem-list-v2&envId=two-pointers*/

/* First approach that came to mind */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = n; 

        for (int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i] = INT_MAX;  /* Will replace the repeating numbers with int_max, and then after sorting, all these numbers would go to the end of the array*/
                count -= 1;
            }
        }

        sort(nums.begin(), nums.end());
        return count;
    }
};

/*Two Pointer Approach */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        for(int i=1; i<n; i++){
            if (nums[i]!=nums[index]){
                index+=1;
                nums[index] = nums[i];
            }
        }

        return (index+1);
    }
};


