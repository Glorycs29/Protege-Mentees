// problem : https://leetcode.com/problems/sort-an-array/description/

class Solution {
public:

    // func to merge two sorted halves
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;   // size of left half
        int n2 = right - mid;      // size of right half
        // temp array
        vector<int> L(n1), R(n2);
        // copy data into temp arrays
        for (int i = 0; i < n1; i++)
            L[i] = nums[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = nums[mid + 1 + j];
        // merge the two halves back into original array
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2){
            // pick the smaller element and move forward
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        // copy remaining elements (if any)
        while (i < n1){
            nums[k] = L[i];
            i++; k++;
        }

        while (j < n2){
            nums[k] = R[j];
            j++; k++;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right){
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        // sort left half
        mergeSort(nums, left, mid);

        // sort right half
        mergeSort(nums, mid + 1, right);

        // merge both sorted halves
        merge(nums, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums){
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

