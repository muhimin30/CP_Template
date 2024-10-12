//Muhimin
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 23;
int n;
struct fanT{
	ll A[N], M[N];

	fanT(){
		memset(A, 0, sizeof(A));
		memset(M, 0, sizeof(M));
	}

	void update(int i, ll add, ll mul){
		while(i <= n){
			A[i] += add;
			M[i] += mul;
			i += (i & (-i));
		}
	}
	void upd(int l, int r, ll x){
		update(l, x, x * (l - 1));
		update(r + 1, -x, -x * r);
	}

	ll sum(int i){
		ll add = 0, mul = 0;
		int ind = i;
		while(i > 0){
			add += A[i];
			mul += M[i];
			i -= (i & (-i));
		}
		return (add * ind) - mul;
	}		
	ll query(int l, int r){
		return sum(r) - sum(l - 1);
	}
}bt;

int main()
{

}


 