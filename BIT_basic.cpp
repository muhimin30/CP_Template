//Muhimin
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 23;
int n; //----> Size of the array
struct fanT{
	ll arr[N];
	fanT(){
		memset(arr, 0, sizeof(arr));
	}
	void upd(int i, int x){ //---------> add x to ith index
		while(i <= n){
			arr[i] += x;
			i += (i & (-i));
		}
	}
	ll sum(int i){ //----> sum from 1 to i;
		ll x = 0;
		while(i > 0){
			x += arr[i];
			i -= (i & (-i));
		}
		return x;
	}

	ll query(int l, int r){ //-----> sum from l to r;
		return sum(r) - sum(l - 1);
	}
}bt;
int main(){
	
}

