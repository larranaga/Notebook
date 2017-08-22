/* Fenwick tree or Binary Indexed Tree
 * query time O(logN)
 * update time O(logN)
 * LOGSZ must be higher than log(SIZE)
 * operations must have inverse

 * tested on AIZU online Judge
 */

#include<bits/stdc++.h>

using namespace std;

const int LOGSZ = 17;

int tree[(1<<LOGSZ) + 1];
int n = (1<<LOGSZ);

void add(int x, int v){
  while(x<=n){
    tree[x] += v;
    x+= (x & -x);
  }
}

int get(int x){
  int ans = 0;
  while(x){
    ans += tree[x];
    x-= (x & -x);
  }
  return ans;
}


int rsq(int x, int y){
    return get(y) - get(x - 1);
}
