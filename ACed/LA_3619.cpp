// Find number of combinations of exactly k different primes summing up to n
// Classical knap-sack 
// Idea: 
// let F[i][j][k] (can be optimized) be the result (the number of set of k-diffent primes <= prime[j], sum of which is i)
// obviously, F[0][j][0] = 1
// We then calculating F[i][j][k] where i!=0&&k!=0, follow the formula below
// Clearly, F[n][num_prime-1][k] is result of the problem indicated by pair (n,k)
// Since all calculation have been done once, overall complexity is O(n*num_prime*k), where num_prime is number of prime numbers <= max (n)
#include <bits/stdc++.h>
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

ll F[1302][1302][15];
ll primes [1003];

bool prime (int x) { // whether x is prime or not
	// Erathones could be better, but this one is implemented for speedy coding
	// Maybe that's my inaccuracy, or bad coding skill
	if (x == 2)
		return true;
	FOR(i,2,sqrt (x)+1){
		if (x%i==0)
			return false;
	}
	return true;
}

int generate (){ // generate array containing primes
	int cnt = 0;
	FOR(i,2,1500){
		if (prime (i))
			primes [++cnt] = i;
	}
	return cnt;
}

int main () {	
	ios_base::sync_with_stdio (0);
	int num_prime = generate ();

	FOR(i,0,num_prime)
		F[0][i][0] = 1;

	// Traverse and compute all states 
	FOR(k,1,15){
		FOR(j,0,num_prime)
			FOR (i,0,1121)
				if (j == 0) {
					F[i][j][k] = 0;
				} else if (i >= primes[j]) {
					F[i][j][k] = F[i-primes[j]] [j-1] [k-1] + F[i] [j-1] [k];
				} else
					F[i][j][k] = F[i] [j-1] [k];
	}

	int n, m, k;

	while (1) {
		
		// Then easily determine the solution in O(1)
		scanf ("%d%d", &n, &k);
		if (n == 0 && k == 0)
			break;
		// printf ("%lld ", primes [m]);
		printf  ("%lld\n", F[n][num_prime-1][k]);
	}
	
	return 0;
}
	
