

/* Tarjan Algorithm to find connected components
 * single dfs O(|v| + |e|)
 * visited =[false]
 * disc = [0]
 * low = [0]
 * parent = [-1]  */

 void dfsSCC(vector<vector<int> > G, int u, int disc[], int low[], stack<int> *st, bool stackMember[]){
     static int time = 0;

     disc[u] = low[u] = ++time;

     st->push(u);
     stackmember[u] = true;

     for(int i = 0; i < G[u].size(); i++){
         int v = G[u][i];

         if(disc[v] == -1){

             dfsSCC(G, v, disc, low, st, stackmember);

             low[u] = min(low[u], low[v]);
         }
         else if(stackmember[v] == true) low[u] = min(low[u], disc[v]);
     }

     int w = 0;

     if(low[u] == disc[u]){

         while(st->top() != u){
             w = st->top();
             cout<<w<<" ";
             stackmember[w] = false;
             st->pop();
         }

         w = st->top();
         cout<<w<<"\n";
         stackmember[w] = false;
         st->pop();
     }
 }

 void scc(G){
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();

    memset(disc, -1, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(stackMember, false, sizeof(stackMember));

    for(int i = 0; i < G.size(); i++)
        if(disc[i] == -1) dfsScc(G, i, disc, low, st, stackMember);
 }
