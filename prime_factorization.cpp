#include <bits/stdc++.h>
using namespace std;

//sieve code;
const int sz = 1e7 + 23;
int mx = 1e7;
bitset<sz> is_prime;
vector<int> primes;
 
void prime(){
	for(int i = 3; i <= mx; i += 2){
		is_prime[i] = 1;
	}
	for(int i = 3; i <= sqrt(mx); i += 2){
		for(int j = i * i; j <= mx; j += i){
			is_prime[j] = 0;
		}
	}
	primes.push_back(2);

	for(int i = 3; i <= mx; i++){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
 
}

// can generate upto n == 1e14; 
// return vector of all Prime Factorization
// complexity (sqrt(n) / ln(sqrt(n))) * 2log(sqrt(n));
vector<int> primefac(long long n){
	vector<int> ans;

	for(auto a: primes){

		if(1LL * a * a > n) break;

		if(n % a == 0){
			while(n % a == 0){
				ans.push_back(a);
				n /= a;
			}
		}
	}

	if(n > 1){
		ans.push_back(n);
	}
	return ans;
}

int main()
{	
	prime();

	return 0;
}
