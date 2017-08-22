/*Tarjan Algorithm to find articulation points
 * single dfs O(|v| + |e|)
 * visited =[false]
 * disc = [0]
 * low = [0]
 * parent = [-1]
 * ap = [false]
 * result is stored in ap boolean array

 * Tested in AIZU online Judge*/
#include<bist/stdc++.h>

using namespace std;

const int SIZE = 100013;

bool visited[SIZE], ap[SIZE];
int disc[SIZE], low[SIZE], parent[SIZE];

vector<int> G[SIZE];

void articulation(int u){
  static int time = 0;
  int children = 0;
  visited[u] = true;
  disc[u] = low[u] = ++time;
  for(int i = 0; i < G[u].size(); i++){
      int v = G[u][i];
      if(!visited[v]){
          children++;
          parent[v] = u;
          articulation(v);
          low[u] = min(low[u], low[v]);
          if(parent[u] == -1 && children > 1)
            ap[u] = true;
          if(parent[u] != -1 && low[v] >= disc[u])
            ap[u] = true;
      }
      else if(v != parent[u])
        low[u] = min(low[u], disc[v]);
  }
}
