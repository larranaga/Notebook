///------------------- Maximum Bipartite Matching O(|V|*|E|) -------------------

bool findMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < int(w[i].size()); j++) {
		if (w[i][j] && !seen[j]) {
			seen[j] = true;
			if (mc[j] < 0 || findMatch(mc[j], w, mr, mc, seen)) {
				mr[i] = j; mc[j] = i;
				return true;
			}
		}
	}
	return false;
}

int maxBipartiteMatching(const VVI &w ) {
	if ( w.empty() || w[0].empty() ) return 0;
	VI mr(w.size(),-1), mc(w[0].size(), -1);
	int ct = 0;
	for (int i = 0; i < int(w.size()); i++) {
		VI seen(w[0].size());
		if (findMatch(i, w, mr, mc, seen)) ct++;
	}
	return ct;
}
