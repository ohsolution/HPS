#include <bits/stdc++.h>
 
#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>
#define M_PI 3.14159265358979323846
#define micro 0.000001
 
using namespace std;
 
int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
 
pair <int, int> vu[8] = { {0,1}, {0,-1} , {1,0},{-1,0},{1,-1},{-1,1},{0,1}, {1,0} }; // EWSN
 
template<typename T, typename U>
void ckmax(T& a, U b) { a = a < b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } };
 
const int max_v = 2e5 + 7;
const LL INF = 1e18 + 7;
const LL mod = 20090711;
 
LL arr[57];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt; ci(cnt);
	while (cnt--)
	{
		LL a, b, c;
		ci(a >> b >> c);
 
		LL sum = 0;
		sum += (a - 1) + (b - 1) + (c - 1);
 
		LL t = sum / 9;
 
		if (a <= t || b<= t || c<=t || sum == 0 || (sum % 9 != 6)) co("NO\n");
		else co("YES\n");
 
	}
	return 0;
}
