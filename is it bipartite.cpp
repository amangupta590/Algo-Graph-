class Solution {
public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int>&col,vector<int>&vis,int c){
        vis[node]=1;
        col[node]=c;
        for(auto nbr:adj[node]){
            if(vis[nbr]==0){
                if(dfs(nbr,adj,col,vis,c^1)==0)
                    return false;
            }
            else{
                if(col[nbr]==col[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size()+1);
        vector<int>col(graph.size()+1,0);
        vector<int>vis(graph.size()+1,0);
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<graph.size();i++){
            if(vis[i]==0){
                if(dfs(i,adj,col,vis,1)==0)
                    return false;
            }   
        }       
        return true;
    }
};