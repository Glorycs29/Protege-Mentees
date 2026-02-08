/* Question Link - https://leetcode.com/problems/valid-palindrome/description/ */

/* Logic Applied - if the string equals the reversed string, there is a palindrome */

class Solution {
public:
    bool isPalindrome(string s) {

        string filtered;
    
        for (char ch : s) {
            if (isalnum(ch))
                filtered += tolower(ch);
        }

        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());

        return filtered == reversed;

    }
};
