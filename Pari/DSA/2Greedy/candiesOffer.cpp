//link -https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution {
  public:
    vector<int> candyStore(int candies[], int N, int K) {
        sort(candies, candies+N);
        //min
        int min=0,max=0;
        int i=0,j=N-1;
        while(i<=j){
            min+=candies[i];
            int cnt=0;
               while(i<j && cnt<K){
                   j--;
                   cnt++;
               }
               i++;
        }
        //max
        i=0,j=N-1;
        
        while(i<=j){
            int counter=0;
            max+=candies[j];
            while(i<j && counter< K){
                counter++;
                i++;
            }
            j--;
        }
        return {min,max};
    }
};
