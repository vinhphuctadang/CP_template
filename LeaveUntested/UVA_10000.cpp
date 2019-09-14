#include "bits/stdc++.h"
#define ll long long
#define ull unsigned ll
#define prev HNhu_prev // since default std already has prev, next
#define next HNhu_next
#define X first
#define Y second
#define oo 2000000000
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define DWN(i,x,y) for(int i=(x);i>(y);--i)
#define ii pair<ll, ll> // change to <int, int> if need
#define umap unordered_map // rarely used
using namespace std;

template <typename T>
ostream& operator << (ostream& o, std::vector<T>& v) {o << "[";FOR(i,0,v.size()) {o << v[i];	if (i < v.size () - 1) o << ", ";}o << "]";return o;}
template <typename U, typename V>
ostream& operator << (ostream& o, std::map<U, V>& v) {o << "{"; int __len = v.size (), i = 0;	for (auto& it: v) {i++;	o << it.first << ":" << it.second; if (i<__len) o << ", ";} o << "}";	return o;}
template <typename U, typename V>
ostream& operator << (ostream& o, std::umap<U, V>& v) {o << "{"; int __len = v.size (), i = 0;	for (auto& it: v) {i++;	o << it.first << ":" << it.second; if (i<__len) o << ", ";} o << "}";	return o;}
// below function inferred from https://en.cppreference.com/w/cpp/language/parameter_pack
template<typename... Ts> void print (Ts... args){int dummy[sizeof...(Ts)] = { (cout << args, 0)... };}

vector<int> topo;
vector<bool> vis;
int dp[1003];

void dfs (int u) {
	vis[u] = 1;
	for (auto v : a[u]) {
		if (!vis[v]) dfs (v);
	}
	topo.push_back (u);
}

int main () {	
	ios_base::sync_with_stdio (0);
	int T, tt = 0;
	cin >> T;
	while (T--) {

		int n, u;
		cin >> n;
		if (n == 0) break;
		cin >> u;

		do {
			int u, v;
			cin >> u >> v;
		}

		dfs (u);		
		topo.clear ();
		reverse (topo.begin (), topo.end ());
		dp[topo[0]] = 0;
		FOR (i, 0, n+1) d[i] = 0;
		int mx = 0, ep = 0;

		FOR (i, 0, topo.size ()-1) {
			FOR (auto v: a[u]) {

				d[v] = max (d[v], d[u] + 1);
				if (d[v] > mx) {
					ep = v;
					mx = d[v];
				}
			}
		}
		if (tt) printf ("\n");
		printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n", ++tt, u, mx, ep);
	}


}
