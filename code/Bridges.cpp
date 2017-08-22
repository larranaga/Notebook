/* Tarjan Algorithm to find bridges
 * single dfs O(|v| + |E|)
 * visited =[false]
 * disc = [0]
 * low = [0]
 * parent = [-1]
 * the priority queue orders the bridges in ascending order,
 * use the function like: bridges(0, &queue)

 * tested in AIZU online Judge
 */
#include<bits/stdc++.h>

using namespace std;

const int SIZE = 100013;

typedef pair<int, int> pii;

bool visited[SIZE];
int disc[SIZE], low[SIZE], parent[SIZE];

vector<int> G[SIZE];


void bridges(int u, priority_queue<pii, vector<pii>, greater<pii> > *bridge){
  static int time = 0;
  int children = 0;
  visited[u] = true;
  disc[u] = low[u] = ++time;
  for(int i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if(!visited[v]){
      children++;
      parent[v] = u;
      bridges(v, bridge);
      low[u] = min(low[u], low[v]);
      if(low[v] > disc[u]) bridge->push({min(u,v),max(u,v)});
    }
    else if(v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
}
