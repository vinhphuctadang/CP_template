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
template<typename... Ts> void print (Ts... args){int dummy[sizeof...(Ts)] = { (cout << args, 0)... };}

vector <vector <int> > a;

int num[2003], low[2003], parent[2003];
bool keep[2003][2003];
int k;
map <ii, int> result;


void tarjan (int u) {
	num[u] = low[u] = ++k;
	for (auto v: a[u]) {
		if (keep[u][v] == 0) continue;

		keep[v][u] = 0;
		if (num[v] == 0) {
			parent[v] = u;
			tarjan (v);
			if (low[v] > num[u]) 
				keep[v][u] = 1;
			low[u] = min (low[u], low[v]);
		} else if (parent[u] != v) { 

			low[u] = min (low[u], num[v]);
		}
	}

}

int main () {	
	// ios_base::sync_with_stdio (0);
	int n, m, cnt = 0;
	while (1) {
		scanf ("%d%d", &n, &m);
		if (n == 0 && m == 0) return 0;
		a.clear ();
		a.resize (n+1, {});
		FOR (u, 1, n+1)
			FOR (v, 1, n+1) keep[u][v] = 0;

		FOR (i,0,m) {
			int u, v;
			scanf ("%d%d", &u, &v);
			a[u].push_back (v);
			a[v].push_back (u);
			keep[u][v] = keep[v][u] = 1;
		}

		FOR (i, 1, n+1) num[i] = low[i] = parent[i] = 0;
		printf ("%d\n\n", ++cnt);
		FOR (i, 1, n+1) {
			if (!num[i]) tarjan (i);
		}

		FOR (u, 1, n+1)
			FOR (v, 1, n+1) {
				if (keep[u][v]){
					print (u, " ", v, "\n");
				}
			}
				
		
		printf ("#\n");
	}
}
