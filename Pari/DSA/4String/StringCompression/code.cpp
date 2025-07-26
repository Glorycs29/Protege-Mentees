//link https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {

    //optimal -O(n)
    //sc=o(1)
    int i=0;
    int ansind=0;
    int n=chars.size();
    while(i<n){
      char ch=chars[i];
      int j=i+1;
      while(j<n && chars[i]==chars[j]){
        j++;
      }
    chars[ansind]=ch;
    ansind++;
    int count=j-i; //no of times current character appears
    if(count>1){
        string strcount=to_string(count);
      
        for(auto ab: strcount) chars[ansind++]=ab;
    }
    //move to new char
    i=j;
    }
    return ansind;
    }
};
