class DisjointSet {
public:
    vector<int> rank , parent , size;
    DisjointSet(int n) {
     size.resize(n , 1);
     parent.resize(n);
     for(int i=0;i<n;i++){
        parent[i]=i;
     }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool find(int u, int v) {
        return findParent(u)==findParent(v);
    }
    void unionBySize(int u, int v) {
       int ulp_u = findParent(u);
       int ulp_v = findParent(v);
       if(ulp_u == ulp_v) return ;

        if(size[ulp_u]< size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtras = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v)) countExtras++;
            else {
                ds.unionBySize(u,v);
            }
        }
        int countconnected_components = 0; 
        for(int i= 0 ; i<n ; i++){
            if(ds.parent[i]==i)  countconnected_components++;
        }

        int ans = countconnected_components-1;
        if(countExtras >= ans) return ans;
        return -1;
    }
};