#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#define round_int(n) floor(n+0.5)
#define round_up(n,s) round_int(n*pow(10,s))/pow(10,s) 
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define mod 1000000007
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline lld input()
{
	lld n=0;
	char ch=getchar_unlocked();
	while(ch>='0' && ch<='9')
		n=(n<<3)+(n<<1)+ch-'0', ch=getchar_unlocked();
	return n;
}


lld modPow(lld a ) {
	lld x = mod-2;
    //calculates a^x mod p in logarithmic time.
    lld res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        x /= 2;
    }
    return res;
}
lld modInverse(lld a) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a);
}
lld modBinomial(lld n, lld k) {
// calculates C(n,k) mod p (assuming p is prime).

    long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % mod;
    }
    
    long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % mod;
    }
    
    // numerator / denominator mod p.
    return ( (numerator)* modInverse(denominator) ) % mod;
}


int main()
{
	int i;
	for(i=2;i<=1000;i+=2)
		cout<<modBinomial(i,i/2)<<",";
	return 0;
}
