// Link: https://www.geeksforgeeks.org/problems/insertion-sort/1

#include <bits/stdc++.h>
using namespace std;


void insertionSort(vector<int>& v){

    int n = v.size();

    for(int i = 1; i < n; i++){
        int curr = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > curr){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = curr;
    }
}


int main(){

    vector<int> v = {};
    insertionSort(v);

    for(auto i : v)
        cout << i << " ";

    return 0;
}
