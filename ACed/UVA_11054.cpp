// CP1 suggest reader should solve with SCCs, but after referring to many algo sources I come up with a solution (just modification of Kosaraju's algo)
// First using TOPO sort to gain a topological order of the nodes on graph then iterate through the order and check again (in case the given graph is not DAG)

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


vector <vector <int>> a;
vector<int> result;

int vis[100005], k;
void dfs (int u, bool get) { // get = True then u is pushed into the "result" vector
	
	vis[u] = 1;
	for (auto v: a[u]) {
		if (!vis[v]) dfs (v, get);
	}
	if (get) result.push_back (u);
}
int main () {	

	ios_base::sync_with_stdio (0);
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n, m;
		scanf ("%d%d", &n, &m);
		a.clear ();
		a.resize (n+1, {});
		FOR (i, 0, m) {
			int u, v;
			scanf ("%d%d", &u, &v);
			a[u].push_back (v);
		}

		int ans = 0;
    
    // do the topo sort
		result.clear ();
		FOR (i,1,n+1) vis[i] = 0;
		FOR (i,1,n+1)
			if (!vis[i]) dfs (i, true);

		reverse (result.begin (), result.end ());
  
    // then we will have a sorted for traversing of dfs 
		FOR (i,1,n+1) vis[i] = 0;
		FOR (i, 0, result.size ()) {
			auto u = result[i];
			if (!vis[u]) {
				dfs (u, false);
				++ans;
			}
		}
		print (ans, "\n");
	}
}
