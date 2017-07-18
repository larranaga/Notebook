/*---------------- disjoint sets-----------*/
#include<bits/stdc++.h>
#define TAM 10000

using namespace std;

class UnionFind{
    private:
        vector<int> p, rank, ssize;
        int numSets;
    public:
        UnionFind(int N){
            rank.assign(N, 0);
            ssize.assign(N, 1);
            numSets = N;
            p.assign(N,0);
            for(int i = 0; i < N; i++)
                p[i] = i;
        }
        int findSet(int i){
            return (p[i] == i)? i: (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                numSets--;
                int x = findset(i), y = findSet(j);
                if(rank[x] > rank[y]){
                    p[y] = x;
                    ssize[x] += ssize[y];
                }
                else{
                    p[x] = y;
                    ssize[y] += ssize[x];
                    if(rank[x] == rank[y])
                        rank[y]++;
                }

            }
        }

        int numDisjointSets(){
            return numSets;
        }

        int sizeOfSet(int i){
            return ssize[findSet(i)];
        }
};
