// Find an edge to erase so that diameter of the tree decreased
// Solution leaved empty
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
#define ii pair<int, int> // change to <int, int> if need
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

umap<int, umap<int, int>> a;
vector<ii> edges;
int p[100005];

void dfs (umap<int, umap<int, int>>& a, int par, int u, int d, int& mx, int& f) {
	if (mx < d) {
		mx = d, f = u;
	}
	p[u] = par;
	for (auto it:a[u]) {
		int v = it.X;
		if (v == par) continue;
		dfs (a, u, v, d+1, mx, f);
	}
}

int diameter (umap<int, umap<int, int>>& a, int u, int& centeroid) {

	int tmp = -1, x;
	dfs (a, -1, u, 0, tmp, x);
	int result = -1, y;
	dfs (a, -1, x, 0, result, y);

	vector<int> trace;
	while (y != -1) {
		trace.push_back (y);
		y = p[y];
	} 
	centeroid = trace[trace.size () / 2];
	return result;
}

int main () {	
	// ios_base::sync_with_stdio (0);
	int T;
	cin >> T;
	// print (T); 
	while (T--) {
		int n;
		cin >> n;

		edges.clear ();
		a.clear ();
		FOR (i, 1, n) {
			int u, v;
			cin >> u >> v;
			a[u][v] = a[v][u] = 1;
			edges.push_back ({u,v});
		}

		// print (a, "\n");
		int result = oo;
		ii del, add;
		// print (edges.size ());

		for (auto edge : edges) {
			int u = edge.X, v = edge.Y;
			a[u].erase (v); 
			a[v].erase (u);
			// print (a, "\n");

			int cen_1, cen_2, tmpcen;
			diameter (a, u, cen_1);
			diameter (a, v, cen_2);
			a[cen_1][cen_2] = a[cen_2][cen_1] = 1;

			int tmp = diameter (a, u, tmpcen);
			if (result > tmp) {
				result = tmp;
				del = edge, add = {cen_1, cen_2};
			}
			a[cen_1].erase (cen_2);
			a[cen_2].erase (cen_1);
			
			a[u][v] = 1;
			a[v][u] = 1;
		}

		print (result, "\n");
		print (del.X, " ", del.Y, "\n");
		print (add.X, " ", add.Y, "\n");
		
	}	
}
