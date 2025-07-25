//link https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        //2 pointer- Could not think of intuition at first
        int maxlen=0;
        int l=0,r=0;
        int maxf=0;
        int cnt=0;
        int n=s.size();
        map<char, int> mpp;
        while(r<n){
            
            mpp[s[r]]++;
            maxf=max(maxf, mpp[s[r]]);
            cnt=r-l+1-maxf;
            if(cnt<=k){
                maxlen=max(maxlen, r-l+1);
               
            }
            else{
                mpp[s[l]]--;
                l++; 
                if(mpp[s[l]]==0) mpp.erase(mpp[s[l]]);
            }
         
            r++;
        }
        return maxlen;
    }
};
