//Qlink -https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //Just check the outdegree and indegree of nodes( Veasy)
        vector<int> outdegree(n+1, 0);
        for(auto i : trust){
           outdegree[ i[0]]++;
        }
        vector<int> indegree(n+1, 0);
        for(auto i : trust ){
            indegree[i[1]]++;
        }
         for(int i=1; i<outdegree.size();i++){
           if(outdegree[i]==0 &&indegree[i]==n-1 ) return i;
        }
       return -1;
    }
};
