#include <bits/stdc++.h>
using namespace std;
 
const int sz = 1e6 + 23;
int mx = 1e6;
bitset<sz> is_prime;
 
void prime(){
	for(int i = 3; i <= mx; i += 2){
		is_prime[i] = 1;
	}
 
	is_prime[2] = 1;
	for(int i = 3; i <= sqrt(mx); i += 2){
		for(int j = i * i; j <= mx; j += i){
			is_prime[j] = 0;
		}
	}
 
}
 
int main()
{
	prime();

}