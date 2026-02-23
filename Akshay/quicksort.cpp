// problem : https://leetcode.com/problems/sort-an-array/description/

class Solution {
public:

    // func to place pivot at correct position
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];   // choosing last element as pivot
        int i = left - 1;          // index of smaller element

        for (int j = left; j < right; j++){
            // if current element is smaller than pivot
            if (nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }

        // place pivot in its correct sorted position
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    void quickSort(vector<int>& nums, int left, int right){
        if (left >= right) return;

        // partition the array and get pivot index
        int pi = partition(nums, left, right);

        // sort elements before pivot
        quickSort(nums, left, pi - 1);

        // sort elements after pivot
        quickSort(nums, pi + 1, right);
    }

    vector<int> sortArray(vector<int>& nums){
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
