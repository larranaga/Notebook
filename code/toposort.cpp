char c[TAM];
int l[TAM];
int r[TAM];
int in[TAM];

//can be priority queue
queue<int> Q;

void reset(){
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(in, 0, sizeof in);
    memset(balls, 0, sizeof balls);
    c[0] = 'L';
}

void topo(vector<vector<int> > G, int u){
    while(!Q.empty()){
        u = Q.front();Q.pop();
        update(u);
        for(int i = 0; i <G[u].size(); i++){
            int v = G[u][i];
            in[v]--;
            if(in[v] == 0) Q.push(v);
        }
    }
}

int main(){
    ll n;
    int m;
    while(cin>>n>>m){
        reset();
        vector< vector<int> > G(m + 1);
        for(int i = 1; i <=m; i++){
            int u,v;
            cin>>c[i]>>u>>v;
            G[i].push_back(u);
            G[i].push_back(v);
            in[u] ++; in[v]++;
            l[i] = u;r[i] = v;
        }
        for(int i = 1; i <=m; i++){
            if(in[i] == 0)Q.push(i);
        }
        topo(G, 1);
    }
}
