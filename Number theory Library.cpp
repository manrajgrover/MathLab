/*
This file contains:
1.GCD: gcd(a,b)
2.LCM: lcm(a,b)
3.Extended Euclid Algorithm : exeuclid(a,b)
4.Mod Inverse: modinv(a,m)
5.Multiplication Expo Squaring: mulexp(base,exp)
6.Mod Inverse using Fermet: fermet_inv(a,m)
7.Eulers Totient Function: fi(n)
8.Euler's method: euler_inv(a,m)
9.Inverse of first 'n' numbers: first_n_inv(n,m)
10.Combination Modular: comb_mod(n,r,m)
 
Some theory:
> For Extended Euclid Algorithm:
	ax+by=gcd(a,b)
	if a and b are coprime then x is multiplicative inverse of a mod b and y is multiplicative inverse of b mod a
 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
 
ll fi(ll n) {
    ll result = n;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0){
        	result-=result/i;
        }
        while(n%i==0){
        	n/=i;
        }
    }
    if(n>1){
    	result-=result/n;
    }
    return result;
}
 
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	else{
		gcd(b,a%b);
	}
}
 
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
 
pair<ll, pair<ll,ll> > exeuclid(ll a, ll b){
	ll x=1,y=0,lastx=0,lasty=1,q,r,m,n;
	while(a!=0){
		q=b/a;
		r=b%a;
		m=lastx-q*x;
		n=lasty-q*y;
		lastx=x,lasty=y;
		x=m,y=n;
		b=a,a=r;
	}
	return make_pair(b,make_pair(lastx,lasty));
}
 
ll modinv(ll a,ll m){
	pair<ll, pair<ll,ll> > p=exeuclid(a,m);
	return ((p.second.first+m)%m);
}
 
ll mulexp(ll b,ll e){
	ll res=1;
	while(e>0){
		if(e%2==1){
			res=(res*b)%MOD;
		}
		b=(b*b)%MOD;
		e=e/2;
	}
	return res%MOD;
}
 
ll pow_mod(ll b,ll e,ll m){
	ll res=1;
	while(e>0){
		if(e%2==1){
			res=(res*b)%m;
		}
		b=(b*b)%m;
		e=e/2;
	}
	return res%m;
}
 
ll fermet_inv(ll a,ll m) {
    return pow_mod(a,m-2,m);
}
 
/*If m is not prime but a and m are co-prime */
ll euler_inv(ll a,ll m){
	//ll fi_m=fi(m);
	return pow_mod(a,m-2,m);
}


vector<ll> first_n_inv(ll n,ll m){
	vector<ll> v_inv(n+1,0);
	v_inv[1]=1;
	for(ll i=2;i<=n;i++){
		v_inv[i]=(-(m/i)*v_inv[m%i])%m+m;
	}
	return v_inv;
}
 
/*Find nCr mod m */
ll comb_mod(ll n,ll r,ll m){
	vector<ll> f(n+1,1);
	for(ll i=2;i<=n;i++){
		f[i]=(f[i-1]*i)%m;
	}
	return (f[n]*(euler_inv(f[r],m)*euler_inv(f[n-r],m))%m)%m;
}
 
 
int main(){
 	// Call functions here!
	return 0;
}
