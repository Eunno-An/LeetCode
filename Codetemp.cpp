//Author @Harsh_xerus
 
#include<bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define rep(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long 
#define INF 1e18
#define nl '\n'
const ll maxn = 2e5 + 100;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
 
//--------------------------Helper_functions-------------------------------//
 
//-------------------------------GCD---------------------------------------//
 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
 
//-------------------------------LCM---------------------------------------//
 
ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}
 
//----------------------------Factorial------------------------------------//
 
ll fact(ll x){if(x==0)return 1;return (x*fact(x-1))%mod;}
 
//-----------------------------Bin_Expo------------------------------------//
 
ll binpow(ll a,ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}
 
//-------------------------Sum/Count of digits----------------------------//
 
ll sd(ll x){ll temp=0;while(x>0){temp+=x%10;x/=10;}return temp;}
ll cd(ll x){ll temp=0;while(x>0){temp++;x/=10;}return temp;}
 
//-------------------------------START------------------------------------//
 
void solve(){ 
    
    
}
 
int main(){
   solve();
}
