// Version 2 of the problem code 166 on UVA
// The second idea: Store the optimized amount of coins to changes money j in F[i][j] and G[i][j]. The only distinction is that F has been build from unlimited money resource whilst G hasn't
// Finally, the result is came up with the sum of F[5][x] + G[5][x]. where the expected money given by x; the solution is only feasible when the maximum payable money is "tiny" enough
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define prev HNhu_prev
#define next HNhu_next
#define X first
#define Y second
#define oo 1000000000
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define DWN(i,x,y) for(int i=(x);i>(y);--i)
#define ii pair<ll, ll>
#define umap unordered_map // rare
#define MAXN 5001
using namespace std;

int a[] = {5, 10, 20, 50, 100, 200};
int number[6], sum;
char buf[10005];
double tmp;
int F[11][MAXN];
int G[11][MAXN];
int result = oo;
int n;

void compute () { // build the F table where minimum number of coin used to change money j is stored
	FOR (j, 0, MAXN) 
 		if (j % a[0] == 0) F[0][j] = j/a[0]; else F[0][j] = oo;
 	FOR (i, 1, 6) {
 		F[i][0] = F[i-1][0];
 		FOR (j, 0, MAXN) { 
 			int x = oo, y = F[i-1][j];
 			if (j >= a[i]) x = F[i][j-a[i]] + 1;
 			F[i][j] = min (x, y);
 		}
 	}
}

void limit () { // Then build G, but with a given bound - number [i]

	FOR (j, 0, sum+1)
		if (j % a[0] == 0 && j/a[0] <= number[0]) G[0][j] = j/a[0]; else G[0][j] = oo;

	FOR (i,1,6) {
		FOR (j, 0, sum+1) {
			G[i][j] = oo;
			FOR (k, 0, number[i]+1) {
				if (j >= k * a[i]) G[i][j] = min (G[i][j], G[i-1][j-k*a[i]] + k);
			}
		}
	}
}


void brute (int i, int k, int sum) {
	if (k>result)
		return;
	if (i>5) {
		if (sum>=n) result = min (result, k+F[5][sum-n]);
	} else {
		FOR (u,0,number[i]+1)
			brute (i+1, k+u, sum + a[i]*u);
	}
}
int main () {	
	ios_base::sync_with_stdio (0);

	compute ();
	// printf ("%d\n", F[2][20]);

	while (1){
		int pre, post;
		sscanf (gets (buf), "%d %d %d %d %d %d %d.%d", 
			&number[0], &number[1], &number[2], &number[3], &number[4], &number[5], &pre, &post);
		sum = 0;
		FOR (i,0,6) sum += a[i] * number[i];
		if (!sum) return 0;

		n = pre*100+post;
		result = oo;
		limit (); // compute the G[i][j] again when bound is refresh (i.e. new test case)

		FOR (i,n, sum+1) {			
			result = min (result, G[5][i] + F[5][i-n]); // collect all possible result and look for a min
		}
		printf ("%3d\n", result);
	}	
}
