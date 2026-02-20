#include <bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[minIndex])
                minIndex = j;
        }

        if(minIndex != i)
            swap(v[i], v[minIndex]);
    }
}


int main(){
    vector<int> v = {};
    selectionSort(v);
    for(auto i : v)
        cout << i << " ";

    return 0;
}
