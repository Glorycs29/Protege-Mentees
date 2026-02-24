//https://leetcode.com/problems/largest-number/?envType=problem-list-v2&envId=string

class Solution {
public:
     static bool comp(string a, string b){
        return a + b > b + a;
    }   

    string largestNumber(vector<int>& nums) {
        vector<string> numsstr;
        
        for (auto it : nums){
            numsstr.push_back(to_string(it));
        }
        sort(numsstr.begin(), numsstr.end(), comp);
        if (numsstr[0] == "0") return "0";

        string ans = "";
        for (int i = 0; i<numsstr.size(); i++){
            ans += numsstr[i];
        }
        return ans;
    }
};
