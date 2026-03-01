//https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> result;
        
        for (int idx : indices) {
            int count = 0;
            for (int j = idx + 1; j < n; j++) {
                if (arr[j] > arr[idx])
                    count++;
            }
            result.push_back(count);
        }
        
        return result;
    }
};
