class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> adjrev(v);
        vector<int> indegree(v,0);
        
        for(int i=0;i<v;i++){
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;                

    }
};