#include "bits/stdc++.h"
#define ll long long
#define ull unsigned ll
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

ll a[21][5003];
ll sum[21];
int idx = 0; // node count, too
vector<ll> graph[5003*16];
int color[5003*16], par[5003*16];
umap<ll, vector<pair<ii, ll>>> trace;
umap<ll, vector<ii>> nodes;

bool cycle (int p, int u) {

	par[u] = p;
	if (color[u] == 1)
		return true;
	color[u] = 1;
	for (auto v: graph[u]) {
		if (color[v] != 2)
			if (!cycle (v)) 
				return false;
	}
	color[u] = 2;
	return true;
}

bool testCycle (vector<ll>& cy) {
	bool vis[21];
	memset (vis, 0, sizeof (vis));
	int cnt = 0;
	for (auto u: cy) {
		ll v = nodes[u].Y.X;
		if (!vis[v]) {
			++cnt;
			vis[v] = 1;
		} else 
			return false;
	}
	return (cnt == k);
}

void printResult (ll u) {
	
	cout << "Yes" << endl;
	vector<ii> res(k+1);
	do {
		ll parent = nodes[par[u]].X.X;
		ll index = nodes[u].X.X;
		ll value = a[index][nodes[u].X.Y];
		res[index].push_back ({value, parent});		
	}
	for (int i = 1; i<=k; ++i)
		cout << res[i].X << " " << res[i].Y << endl;
}

int main () {	
	cin >> k;
	ll total = 0;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i][0];

		for (int j = 1; j<=a[i][0]; ++j) {
			int u;
			cin >> u;

			a[i][j] = u;
			sum[i] += u;

			++idx;
			nodes[idx].push_back ({i, j});
			trace[u].push_back ({{i,j}, idx}); 
		}

		total += sum[i];
	}

	if (total % k != 0) {
		cout << "No";
	} else {
		ll equalSum = total/k;
		ll index = 0;
		for (int i = 1; i<=k; ++i) {
			for (int j = 1; j<=a[i][0]; ++j) {
				index++;
				ll target = equalSum - (sum[i]-a[i][j]);
				if (trace.find (target) != trace.end()) {
					for (auto it: trace[target]) {
						ll row = it.X.X;
						if (row != i) {
							graph[index].push_back (it.Y);
						}
					}
				}
			}
		}

		for (int i = 1; i <= index; ++i)
			if (color[i] == 0) {
				if (cycle(i)) {
					
					vector<ll> cy;
					int u = i;
					do {
						cy.push_back (u);
						u = par[u];
					} while (u != i);

					if (testCylce (cy)) {
						printResult (i);
						return 0;
					}
				} 
			}

		cout << "No";
	}
}
