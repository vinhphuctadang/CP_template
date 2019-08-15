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
ostream& operator << (ostream& o, std::map<U, V>& v) {o << "{"; int __len = v.size (), i = 0;	for (auto& it: v) {i++;	cout << it.first << ":" << it.second; if (i<__len) cout << ", ";} o << "}";	return o;}

// below function inferred from https://en.cppreference.com/w/cpp/language/parameter_pack
template<typename... Ts> void print (Ts... args){int dummy[sizeof...(Ts)] = { (cout << args, 0)... }; cout << endl;}

int low[2003], num[2003], parent[2003], k;
vector<vector<int>> a;

void dfs (int u) {
	low[u] = num[u]	= ++k;
	for (auto v: a[u]) {
		if (num[v] == 0) {
			parent [v] = u;
			dfs (v);
			if (low[v] > num[u]) {
				printf ("%d %d\n", u, v);
			}
			low[u] = min (low[u],  num[v]);
		} else if (parent[v] != u) {
			low[u] = min (low[u], num[v]);
		}
	}
}
int main () {	
//	ios_base::sync_with_stdio (0);
	freopen ("input.txt", "r", stdin);

	while (1) {
		int n, m;
		scanf ("%d%d", &n, &m);
		if (n==0 && m==0) break;
//		print (n, " ", m);
		a.resize (n+1, {});
		FOR (i,0,m) {
			int u, v;
			scanf ("%d%d", &u, &v);
			a[u].push_back (v);
			a[v].push_back (u);		
		}
		print (a);
		FOR (u, 1, n+1) num[u]=low[u]=parent[u]=0;
		FOR (u, 1, n+1) {
			if (num [u] == 0) {
				k = 0;
				dfs (u);
				// STUFF
			}
		}
		printf ("#\n\n");
		
	}			
}
