//================code===================//

#define TLE

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
#define __popcnt __builtin_popcountll
#define gcd __gcd
#define lcm __lcm
#endif


pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,1},{1,0}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 2.5e3 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9 + 7;

ld dp[max_v][11];
int n, k;
ld p[max_v];
ld nxt[max_v][11];

ld dnq(int idx, int r)
{
	if (r < 0) return 0.0;
	if (idx >= n) return 0.0;

	ld& ret = dp[idx][r];

	if (ret > -0.05) return ret;

	ret = 0;
	ld pr = 1;	
	ld pp = 0;

	fa(i, idx, n)
	{
		pr *= (1.0 - p[i]);		
		pp += pr;
		ckmax(ret, pp + nxt[i][r]);
	}
	return ret;
}

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ci(n >> k);
	fa(i, 0, n) ci(p[i]);
	p[n] = 1;
	fa(i, 0, n + 1) fa(j, 0, k + 1) dp[i][j] = -1;
	--k;

	fa(i, 0, k)
	{
		ld maxi = 0;

		fd(j, n - 1, -1)
		{
			
			nxt[j][i + 1] = maxi;
			ckmax(maxi, dnq(j, i));
		}
	}

	ld ans = dnq(0, k);

	co(setprecision(9) << fixed << ans);

	return 0;
}
