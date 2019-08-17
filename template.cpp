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

int main () {	
	ios_base::sync_with_stdio (0);
	// umap <string, vector<int>> m = {
	// 	{"hello", {1, 1}},
	// 	{"world", {2, 3, 4}}
	// };
	// print (m);
}
