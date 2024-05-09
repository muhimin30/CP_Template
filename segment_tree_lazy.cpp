#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N = 1e5 + 23;
int arr[N];
struct SegT {
  #define l_c (n << 1)
  #define r_c ((n << 1) | 1)

  ll t[4 * N], lazy[4 * N];
  SegT() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
	//clear pending lazy
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if (b != e) {
      lazy[l_c] = lazy[l_c] + lazy[n];
      lazy[r_c] = lazy[r_c] + lazy[n];
    }
    lazy[n] = 0;
  }
  ll combine(long long a,long long b) {
    return a + b;
  }
  void pull(int n) {
    t[n] = t[l_c] + t[r_c];
  }
	//build
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n] = arr[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(l_c, b, mid);
    build(r_c, mid + 1, e);
    pull(n);
  }
	//range update
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(l_c, b, mid, i, j, v);
    upd(r_c, mid + 1, e, i, j, v);
    pull(n);
  }
	//range query
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(l_c, b, mid, i, j), query(r_c, mid + 1, e, i, j));
  }
}st;
