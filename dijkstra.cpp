#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define prev HNhu_prev
#define next HNhu_next
#define X first
#define Y second
#define oo (ll) 2000000000
#define FOR(i,x,y) for(int i=(x);i<=(y);++i)
#define DWN(i,x,y) for(int i=(x);i>=(y);--i)
#define umap unordered_map 

#define ii pair<ll, ll>
using namespace std;
	
vector<ll> dijsktra (int n, umap<ll, umap<ll, ll> > &a, int pr[], int src){

	vector<ll> d(n+1, oo);
	vector<bool> vis(n+1,0);

	d[src] = 0;
	priority_queue <ii, vector<ii>, greater <ii> > q;
	q.push ({0, src});

	FOR(i,1,n-1) {

		auto p = q.top ();
		q.pop ();
		ll u = p.Y, du = p.X;
		vis[u] = 1;
		for (auto pv:a[u]) {
			int v = pv.X, w = pv.Y;
			if (vis[v]) continue;
			// printf ("OK");
			if (du + w < d[v]) 
				q.push ({d[v]=du + w, v}),	pr[v] = u;
		}
	}

	return d;
}

int pr[100005];

int main () {	
	ios_base::sync_with_stdio (0);
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	// printf ("%d %d ", n, m);
	umap <ll, umap <ll, ll> > a;

	FOR(i,1,m) {
		ll u, v, w; 
		cin >> u >> v >> w;
		a[u][v] = w;
		printf ("%d %d %d \n", u, v, w);
	}

	vector<ll> res = dijsktra (n, a, pr, s);
	cout << res[d];
}
