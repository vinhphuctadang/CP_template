// Read the problem on UVA (code 166) first

/*
>>> This is a kind of DP problem
My solution:
Since the shop keeper has adequate types of money (i.e. enough coins of 5, 10, ...) to change back, then first calculate solution for exchange money j in to coins, which I have stored in F[i][x] (use the categories of [0..i] to change money which amount was given by j)
This can be done with simple DP approach

Now, with the goods' price (let's denote n), do a simple bruteforce that tries all the possible sum of money, then we can incur result = min {total coin = F[5][sum-n] + used_coin_to_create_sum} (see the code for clarification}
But the solution will result in a TLE verdict. LOL
A little trick is that terminate the "bruteforce" searching early by check whether the total_coin_to_make_sum > current "result" (Branching and Bound, alike)

The solution below could be optimized (especially in memmory allocating)
*/


// Code has been shown beblow
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
int number[6];
char buf[10005];
double tmp;
int F[11][MAXN];
int result = oo;
int n;

void compute () {
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

void brute (int i, int k, int sum) {
	if (k>result) // Termiate
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
		bool flag = 0;
		FOR (i,0,6) if (number[i]) {flag = 1; break;}
		if (!flag) return 0;
		n = pre*100+post;
		result = oo;
		brute (0, 0, 0);
		printf ("%3d\n", result);
	}	
}
