

//================code===================//

//#define TLE

#ifdef TLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <ctime>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define ld long double
#define fa(i,a,b) for(LL i=(a);i<(LL)(b);++i)
#define fd(i,a,b) for(LL i=(a);i>(LL)(b);--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>

#define M_PI 3.14159265358979323846
#define micro 0.000001

using namespace std;

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
#else
#define AT
#define AE
#define ce(t)
#define __popcnt __builtin_popcount
#define gcd __gcd
#define lcm __lcm
#endif


pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,1},{1,0}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 998244353;

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);				
	int a, b, k;
	ci(a >> b >> k);

	if (a == 0 || b == 1)
	{
		if (k)
		{
			co("No\n");
		}
		else if (a == 0)
		{
			string ans = "";
			while (b--) ans += "1";
			co("Yes\n" << ans << "\n" << ans << "\n");
		}
		else if (b == 1)
		{
			string ans = "1";
			while (a--) ans += "0";
			co("Yes\n" << ans << "\n" << ans << "\n");
		}

		return 0;
	}

	if (k > a + b - 2) co("No\n");
	else
	{	
		int sz = a + b;
		string ans = "1";
		fa(i, 0, sz - 1) ans += "0";
		string bns = ans;
		
		ans[1] = '1';
		bns[1 + k] = '1';
		b -= 2;

		fa(i, 2, sz)
		{
			if (b && ans[i] == '0' && bns[i] == '0')
			{
				--b;
				ans[i] = '1';
				bns[i] = '1';
			}
		}

		co("Yes\n" << ans << "\n" << bns << "\n");
	}


	return 0;
}
