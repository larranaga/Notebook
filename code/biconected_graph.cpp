/* Tarjan Algorithm to find Biconnected graph
 * single dfs O(|v| + |e|)
 * visited =[false]
 * disc = [0]
 * low = [0]
 * parent = [-1]  */

bool isBiconnected(vector<vector<int> > G, int u, bool visited[], int disc[], int low[], int parent[]){
    static int time = 0;

    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    for(int i = 0; i<G[u].size(); i++){
        int v = G[u][i];

        if(!visited[v]){
            children++;
            parent[v] = u;

            if (isBiconnected(G, v, visited, disc, low, parent)) return true;

            low[u] = min(low[u], low[v]);

            if(parent[u] == -1 && children > 1) return true;

            if(parent[u] != -1 && low[v] >= disc[u]) return true;
        }
        else if(v != parent[v]) low[u] = min(low[u], disc[v]);
    }
    return false;
}
