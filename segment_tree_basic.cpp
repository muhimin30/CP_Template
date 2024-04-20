#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+23;
int arr[N], t[4 * N];

//build the tree
void build(int n, int b, int e){
	if(b == e){
		t[n] = arr[b];
		return;
	}
	int mid = (b + e) / 2, l_c = 2 * n, r_c = 2 * n  + 1;

	build(l_c, b, mid);
	build(r_c, mid + 1, e);

	t[n] = t[l_c] + t[r_c];
}

//range query
ll query(int n, int b, int e, int i, int j){
	//fully outside
	if(e < i || b > j) return 0;

	//fully inside
	if(b >= i && e <= j) return t[n];

	//intersect
	int mid = (b + e) / 2, l_c = 2 * n, r_c = 2 * n + 1;
	return query(l_c, b, mid, i, j) + query(r_c, mid + 1, e, i , j);
}

//single update
void upd(int n, int b, int e, int i , int x){
	//outside
	if(e < i || b > i) return;

	//inside
	if(b == i && e == i){
		t[n] = x;
		return;
	}
	//intersect
	int mid = (b + e) / 2 , l_c = 2 * n, r_c = 2 * n + 1;

	upd(l_c, b, mid, i, x);	
	upd(r_c, mid + 1, e, i, x);

	t[n] = t[l_c] + t[r_c];
}