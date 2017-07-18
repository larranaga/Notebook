#include<iostream>
#include<algorithm>
#include<complex>
#include<cstdio>
#include<iomanip>
#include<vector>
#define x real()
#define y imag()
#define dot(A,B)		real(conj((A))*(B))
#define cross(A,B)		imag(conj((A))*(B))
#define PI 3.1415926
#define EPS 1e-9

using namespace std;
typedef double lf;
typedef complex<lf> pt;

istream& operator >> ( istream& in, pt& p ) {
  lf a,n; in >> a >> n;
  p = pt(a,n); return in;
}

bool cmp(pt &p, pt &q) {
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

int ccw(pt& p1, pt& p2, pt& p3) {
  lf ans = (cross(p1 - p3, p2 - p3));
  if(-EPS <= ans && ans <= EPS)
    return 0;
  else if(ans <= -EPS)
    return -1;
  else
    return 1;
}

lf dist ( pt A, pt B ) { return abs(A-B); }


vector<pt> convex_hull(vector<pt> P){
	int n = P.size(); int k = 0;
	vector<pt> H(2*n);

	sort(P.begin(), P.end(), cmp);

	for (int i = 0; i < n; i++) {
		while (k >= 2 && ccw(H[k-2], H[k-1], P[i]) == 1) k--;
		H[k++] = P[i];
	}


	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && ccw(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	if(n>1)
    k--;
	H.resize(k);
	return H;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifdef LOCAL
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  #endif // LOCAL
  int n;
  cin>>n;
  vector<pt> p(n);
  for(int i = 0; i < n; i++)
    cin>>p[i];
  vector<pt> hull = convex_hull(p);
  for(auto &pt: hull)
    cout<<pt<<endl;
}
