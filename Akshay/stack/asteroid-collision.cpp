//https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;

        for (int i : asteroids){
            if (i >= 0){
                s.push(i);
            } 
            else {
                while (!s.empty() && s.top() > 0 && s.top() < abs(i)){
                    s.pop();
                }

                if (!s.empty() && s.top() > 0 && s.top() == abs(i)){
                    s.pop();
                    continue;
                }

                if (s.empty() || s.top() < 0){
                    s.push(i);
                }
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
