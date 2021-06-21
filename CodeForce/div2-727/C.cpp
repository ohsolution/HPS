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
#include <random>
#include <chrono>
//#include <stdint.h>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define ld long double
#define fa(i,a,b) for(LL i=(a);i<(LL)(b);++i)
#define fd(i,a,b) for(LL i=(a);i>(LL)(b);--i)
#define setp tuple<LL,LL,LL>
#define setl pair<LL,LL>

#define micro 0.000000000001

using namespace std;

ld PI = acos(-1);

LL gcd(LL a, LL b)
{
	if (!(a && b)) return max(a, b);
	return a % b ? gcd(b, a % b) : b;
}

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#define LLL LL
#else
#define AT
#define AE
#define ce(t)
#define LLL __int128
#endif

pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{-1,0},{-1,-1}, {0,-1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl& a, setl& b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl& a, setl& b) { return a.second > b.second; } };

const int max_v = 2e3 + 27;
const int max_k = 5e1 + 7;
const int bsz = (1ll << 10) + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
LL mod = 1e9 + 7;//998244353;
template<typename T, typename U> void MOD(T& a, U b) { a += b; if (a >= mod) a -= mod; };

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n, k, x; ci(n >> k >> x);

	vector<LL> vi(n);
	for (auto& x : vi) ci(x);
	sort(vi.begin(), vi.end());

	map<LL, int> nk;

	fa(i, 1, vi.size())
	{
		LL dif = vi[i] - vi[i - 1];

		if (dif > x)
		{
			++nk[ceil(dif / (ld)x) - 1];
		}
	}

	LL ans = 1;

	for (auto& x : nk)
	{
		while (x.second--)
		{
			if (k >= x.first)
			{
				k -= x.first;
			}
			else ++ans;
		}
	}

	co(ans);


	return 0;
}
