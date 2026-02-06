/* Strivers Sheet 
Array - Easy questions
Largest element in and array - https://takeuforward.org/data-structure/find-the-largest-element-in-an-array */

#include <iostream>
using namespace std;

int LargestElementInArray(int *a, int n){      /* a function is made which takes the array a and its size n as it parameters */
    int largest = a[0];

    for(int i=0; i<n; i++){
        if(largest<a[i]){
            largest = a[i];
        }
    }

    return largest;
}

int main(){
    int a[10] = {1,2,34,5,6,7,8,9,46};
    int n = 10;

    int ans = LargestElementInArray(a,n);

    cout<<"The Largest Element in the array is: "<<ans << endl;

    return 0;
}

  
