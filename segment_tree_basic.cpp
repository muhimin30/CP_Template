#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 23;

int arr[N];
struct SegT{
	#define l_c (n << 1)
	#define r_c ((n << 1) | 1)
	ll t[4 * N];
	SegT(){
		memset(t, 0, sizeof(t));
	}
	ll combine(ll a, ll b){
		return a + b; 				//change
	}
	void pull(int n){
		t[n] = t[l_c] + t[r_c];
	}
	//build tree
	void build(int n, int b, int e){
		if(b == e){
			t[n] = arr[b];
			return;
		}
		int mid = (b + e) >> 1;

		build(l_c, b, mid);
		build(r_c, mid + 1, e);

		pull(n);
	}
	//range query
	ll query(int n, int b, int e, int i, int j){
		if(e < i || b > j) return 0;

		if(b >= i && e <= j) return t[n];

		int mid = (b + e) >> 1;

		return combine(query(l_c, b, mid, i, j) , query(r_c, mid + 1, e, i, j));
	}
	//single update
	void upd(int n, int b, int e, int i, int x){
		if(e < i || b > i) return;

		if(b == e && b == i){
			t[n] = x;					//update
			return;
		}
		int mid = (b + e) >> 1;

		upd(l_c, b, mid, i, x);
		upd(r_c, mid + 1, e, i, x);
		//pull(n);
		t[n] = t[l_c] + t[r_c];
	}

}ST;
