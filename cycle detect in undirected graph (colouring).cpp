class Solution {
public:
    bool dfs(vector<int>&visited,vector<vector<int>>&adj,int numCourses,int curr){
        if(visited[curr]==2){
            return true;
        }
       
        visited[curr]=2;
        for(int i=0;i<adj[curr].size();i++){
            if(visited[adj[curr][i]]!=1){
                if(dfs(visited,adj,numCourses,adj[curr][i])){
                    return true;
                }
            }
        }
        visited[curr]=1;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(dfs(visited,adj,numCourses,i)){
                return false;
            }            
        }
        return true;
        
    }
};
