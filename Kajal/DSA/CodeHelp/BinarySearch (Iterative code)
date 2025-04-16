/*Most important topic for interviews and Online test(OA)

in linear search, hum key element ko array ka har ek element sa compare karta tha
then agar key element array ka element sa match ho jata tha then the key element found
otherwise the key element is absent in the array

linear search syntax
For(0->n){    //T.C. -> O(n)
    if(arr[i]==Key){
        return i;
    }
}
return -1; 
Worst case -> n comparision, O(n)

If you have an array of 1000 values then for 
linear search worst case will be 1000 comparision

we use binary search only on monotonic function ya tu values 
increasing order ma ho ya tu decreasing order ma
The only condition for binary search the elements should be in 
monotonic function.

Example 1:
arr[] = {3,5,9,13,27}
humne key element 13 liya hai then the first step is
choose the middle element like here 9, then compare 9 with 
13, thye condition will be false.
9==13 -> No
agar humara key element 9 hota then 9==9 ho jata and 
2 (index of 9) return kar deta 

13>9 so huma pata chal gaya ki 9 ki increasing order wali side 
ma huma search karna hai means right side ma

now we take arr[] = {13,27}
mid = (starting index + ending index)/2
    = (3+4)/2 = 3

then we compare 13==13 (True) -> return 3
So, we get ans as 3   

Algorithm:
1) Find mid
2) Compare mid with key
3) = -> return index
4) != -> then decide part for searching
5) then again we find mid and compare mid with key
6) this process continues untill key element is equal 
to array element

Example 2:
arr[] = {3,7,11,13,19,27}
key = 27
mid = (s+e)/2 = (0+5)/2 = 5/2 = 2
11 != 27
27>11 then search in right side
arr[] = {13,19,27}
mid = (3+5)/2 = 8/2 = 4
19 != 27
27>19 then search in right side
arr[] = {27}
mid = (s+e)/2 = (5+5)/2 = 5
27 == 27 (True) 
return 5
we get answer as 5

Example 3:
arr[] = {4,8,16,22,34}
key = 4
mid = (0+4)/2 = 4/2 = 2
16 != 4
4<16
arr[] = {4,8}
mid = (s+e)/2 = (0+1)/2 = 0
4 == 4 (True)
return 0
we get answer as 0

when key is 8 then
4!=8
8>4 then move to right side
arr[] = {8}
mid = (1+1)/2 = 1
8 == 8 (True)
return 1
we get answer as 1

Example 4:
arr[] = {5,11,13,17,19,27}
key = 25
mid = (s+e)/2 = (0+5)/2 = 2
13!=25
25>13 then search in right side
arr[] = {17,19,27}
mid = (s+e)/2 = (3+5)/2 = 8/2 = 4
19!=25
25>19 then search in right side
arr[] = {27}
mid = (s+e)/2 = (5+5)/2 = 5
27!=25
25<27 becoz ab koi part nahi bacha hai jaha 
hum search kar sakta hai
return -1;
we get "NOT FOUND" as answer

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;   
    int end = size-1;  //size(n) end = n - 1;
    
    //on big array, this formula will create overflow issue
    int mid = (start + end)/2; //valid for small array

    while(start<=end){

        if(arr[mid] == key){
            return mid;
        }
        
        //go to right wala part
        if(key > arr[mid]){
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = (start+end)/2;    
    }
    return -1;
}

int main(){

    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3,8,11,14,16};

    int evenindex = binarySearch(even, 6, 18);

    cout << " Index of 18 is " << evenindex << endl;

    int oddIndex = binarySearch(odd, 5, 8);

    cout<< " Index of 8 is " << oddIndex << endl;
}

Optimisation:
mid = (start + end)/2
int -> 2^31 -1
start = 2^31 - 1
end = 2^31 - 1 
when we add start and end, we get a value which is out 
of range of int
int range ka bahar wali value aa gayi
we resolve this problem by changing the formula a little bit
mid = s + (e-s)/2;

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;   
    int end = size-1;  //size(n) end = n - 1;

    int mid = start + (end - start)/2; //to avoid overflow

    while(start<=end){

        if(arr[mid] == key){
            return mid;
        }
        
        //go to right wala part
        if(key > arr[mid]){
            start = mid + 1; //right part
        }
        else{ //key < arr[mid]
            end = mid - 1; //left part
        }

        mid = start + (end - start)/2; //Same here  
    }
    return -1;
}

int main(){

    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3,8,11,14,16};

    int evenindex = binarySearch(even, 6, 18);

    cout << " Index of 18 is " << evenindex << endl;

    int oddIndex = binarySearch(odd, 5, 8);

    cout<< " Index of 8 is " << oddIndex << endl;
}

Linear Search -> 1000 values -> array
Worst case -> 1000 comparison -> O(n)

Binary Search -> 1000 value -> sorted array
1000 size -> 500 size -> 250 size -> 125 size 
-> 62 size -> 31 size -> 15 size -> 7 size -> 3 size -> 1 size -> 0 size

N size -> N/2 size -> N/4 size -> N/8 size ->....-> N/2^k

N/2^k = 1
N = 2^k
k = logN

Total 10 comparison are done 
T.C. -> O(logn)
*/
