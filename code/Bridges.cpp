/* Tarjan Algorithm to find bridges
 * single dfs O(|v| + |e|)
 * visited =[false]
 * disc = [0]
 * low = [0]
 * parent = [-1]  */

 void bridges(vector<vector<int> > G, int u, bool visited[], int disc[], int low[], int parent[], priority_queue< pair<int, int> > *bridge) {

    static int time = 0;

    int children = 0;
    visited[u] = true;

    disc[u] = low[u] = ++time;

    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];

        if(!visited[v]){
            children++;
            parent[v] = u;
            bridges(G, v, visited, disc, low, bridge);

            low[u] = min(low[u], low[v]);

            if(low[v] > disc[u])bridge->push({u,v});
        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}
