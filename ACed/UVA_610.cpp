// Actually, not it is my own solution, I have to read the reference books and contents on the Internet
// Trick:
// Run the "bridge detection" method, while traversing through adjancent vertex, notice that:
// We never want a back edge to be existed unless the forward edge is a bridge (where low[v] > num[u]), so only turn the 'back edge' on if forward edge is a bridge (since we couldn't remove the forward edge, but keep it does not make it one strongly connected components, i.e. we need the help of the back edges
// Keep in mind that if we turn off an edge, we never use it again 
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

// below is tarjan (u) function traversing through the graph using DFS 
void tarjan (int u) {// it is not really tarjan, but I personally think it should be named after it
	
	num[u] = low[u] = ++k;
	for (auto v: a[u]) {
		if (keep[u][v] == 0) continue;

		keep[v][u] = 0; // disable the reversing edge
		if (num[v] == 0) {
			parent[v] = u;
			tarjan (v);
			if (low[v] > num[u]) // edge [u,v] is a bridge
				keep[v][u] = 1; // enable the edge [v,u] due to the fact that we have to take advantage of it to create only one strongly connected component
			low[u] = min (low[u], low[v]); // update low[u] value
		} else if (parent[u] != v) { 
			low[u] = min (low[u], num[v]);
		}
	}

}

int main () {	
	ios_base::sync_with_stdio (0); // for 'faster' cout
	int n, m, cnt = 0;
	while (1) {
		scanf ("%d%d", &n, &m);
		if (n == 0 && m == 0) return 0;
		a.clear ();
		a.resize (n+1, {}); // a.resize () seems efficient
		FOR (u, 1, n+1)
			FOR (v, 1, n+1) keep[u][v] = 0;

		FOR (i,0,m) {
			int u, v;
			scanf ("%d%d", &u, &v);
			a[u].push_back (v);
			a[v].push_back (u);
			keep[u][v] = keep[v][u] = 1; // initially, every edge must be activated
		}

		FOR (i, 1, n+1) num[i] = low[i] = parent[i] = 0; // clean up
		printf ("%d\n\n", ++cnt);
		FOR (i, 1, n+1) {
			
			// Run the tarjan (u) wherever num[i] is ZERO, I just worried about disconnected components
			
			if (!num[i]) tarjan (i);
		}

		// print the result, it preserve the order of edges matching UVA output utterly
		FOR (u, 1, n+1)
			FOR (v, 1, n+1) {
				if (keep[u][v]){
					print (u, " ", v, "\n");
				}
			}
				
		
		printf ("#\n");
	}
}
