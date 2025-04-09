//Qlink ->https://leetcode.com/problems/course-schedule-ii/description/
class Solution {
public:
//kahns algorithm -> basically have to return the topological sorting 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //converting into adjacent list
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
      
        //kahns algorithm
        queue<int> q;
        //finding indegrees
        vector<int> indegree(numCourses,0);

for(int i = 0; i< numCourses; i++) {
    for(auto j : adj[i]) {
        indegree[j]++;
    }
}
      vector<int> topo;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){ 
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
      //THE CODE TILL HERE IS ALSO the SECOND APPRAOCH OF COURSE SCHEDULE 1 Q.
        if(topo.size()==numCourses) return topo;
        else return {};
    }
};
