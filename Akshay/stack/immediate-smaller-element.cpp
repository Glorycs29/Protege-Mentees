// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st; 
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return result;
    }
};
