#include "bits/stdc++.h"
#define ll long long
#define ull unsigned ll
#define prev HNhu_prev
#define next HNhu_next
#define X first
#define Y second
#define oo 2000000000
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define DWN(i,x,y) for(int i=(x);i>(y);--i)
#define ii pair<ll, ll>
#define umap unordered_map // rare
using namespace std;

ostream& operator << (ostream& o, std::vector<int>& v) {
	for (auto it: v)
		o << it << " ";
	return o;
}
template<typename... Ts> void print (Ts... args){ // inferred from https://en.cppreference.com/w/cpp/language/parameter_pack
	int t = sizeof...(Ts);
    int dummy[t] = { (std::cout << args << " ", 0)... };
}

int main () {	
	ios_base::sync_with_stdio (0);
	
}
