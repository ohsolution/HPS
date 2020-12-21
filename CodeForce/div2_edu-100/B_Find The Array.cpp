
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
LL tp[37];
 
LL f(LL x)
{
	LL idx = 0;
	LL ret = abs(x - tp[0]);
	fa(i, 1, 30)
	{
		if (abs(x - tp[i]) > ret) break;
		ret = abs(x - tp[i]);
		idx = i;
	}
	return tp[idx];
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt; ci(cnt);
	tp[0] = 1;
	fa(i, 1, 30) tp[i] = tp[i - 1]<<1;
 
	while (cnt--)
	{
		int n; ci(n);
		fa(i, 0, n) ci(arr[i]);
 
		fa(i, 0, n)
		{
			co(f(arr[i]) << " ");
		}
		co("\n");
	}
	return 0;
}
