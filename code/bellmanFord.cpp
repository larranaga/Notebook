/* Bellman Ford's algorithm to find SSSP with negative cycles O(V^3)
 * returns true if it detects a negative cycle
 * dist [i] contains distance to i
 * parent[i] contains parent on path to i from source

 * tested on AIZU online judge
 */
#include<bits/stdc++.h>

const int SIZE = 1013;
const int oo = 999999;

typedef pair<int, int> pii;

int dist[SIZE];
int parent[SIZE];

bool bellmanFord(vector<vector<pii> > &G, int &source, int &N){
    for(int i = 0; i < N; i++)
      dist[i] = oo;
    dist[source] = 0;
    for(int k = 0; k < N; k++){
      for(int u = 0; u < N; u++){
        for(int i = 0; i < G[u].size(); i++){
          pii v = G[u][i];
          if(dist[v.first] > dist[u] + v.second && dist[u] != oo){
            if(k == N-1)
              return true;
            dist[v.first] = dist[u] + v.second;
            parent[v.first] = u;
          }
        }
      }
    }
    return false;
}
