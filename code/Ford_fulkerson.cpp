#include<bits/stdc++.h>

using namespace std;
///---------------------- Ford-Fulkerson O(MaxFlow * |E|) ----------------------

//tested on AIZU online Judge

struct OutEdge {
	int to, cap, rIdx;
	OutEdge ( ) { }
	OutEdge(int to, int cap, int rIdx) :
		to(to), cap(cap), rIdx(rIdx) { }
};

struct Network{
	vector<vector<OutEdge> > out;
	vector<bool> seen;

	int sink;
	int augment ( int i, const int cur ) {
		if ( i == sink ) return cur;
		if ( seen[i] ) return false;
		seen[i] = true;
		int ans;
		for ( OutEdge& e : out[i] )
			if ( e.cap > 0 && ( ans = augment(e.to,min(cur,e.cap)) ) ) {
				e.cap -= ans;
				out[e.to][e.rIdx].cap += ans;
				return ans;
			}
		return 0;
	}

	int maxflow ( int source, int _sink ) {
		sink = _sink;
		int curflow = 0, aug;
		while ( true ) {
			fill ( seen.begin(), seen.end(), false );
			aug = augment(source,INT_MAX);
			if ( aug == 0 ) break;
			curflow += aug;
		}
		return curflow;
	}

	void addEdge ( int fr, int to, int c ) {
		assert ( fr != to );
		out[fr].push_back(OutEdge(to, c, out[to].size()));
		out[to].push_back(OutEdge(fr, 0, out[fr].size() - 1));
	}

	Network(int n) {
		out.assign(n, vector<OutEdge>());
		seen.resize(n);
	}
};
