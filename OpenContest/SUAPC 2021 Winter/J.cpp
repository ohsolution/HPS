
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

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9 + 7;
const int sz = 1 << 20;

int n, k;

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ci(n >> k);
	vector <int> vi(n);
	fa(i, 0, n) ci(vi[i]);
	fa(i, 0, n) vi.push_back(vi[i]);
	n <<= 1;

	int l = 0;
	int r = k-2;
	int ans = k-1;

	int mid;


	while (l <= r)
	{
		mid = (l + r) >> 1;

		bool ck = false;

		map<int, int> xh;

		int c = k - mid;
		int csz = 0;

		fa(i, 0, c)
		{
			if (++xh[vi[i]] == 1) ++csz;
		}

		
		if (csz + mid == k)
		{
			int u = max(0, (*(--xh.end())).first - (*xh.begin()).first - 1-csz+2);
			if (u <= mid) ck = true;
		}

		if (!ck)
		{
			int l = 0;

			fa(i, c, n) 
			{
				if (++xh[vi[i]] == 1) ++csz;
				if (--xh[vi[l]] == 0) --csz,xh.erase(vi[l]);
				++l;

				if (csz + mid == k)
				{
					int u = max(0, (*(--xh.end())).first - (*xh.begin()).first - 1 - csz + 2);
					if (u <= mid) ck = true;
				}

				if (ck) break;
			}
		}


		if (ck) r = mid - 1, ckmin(ans, mid);
		else l = mid + 1;
	}

	co(ans);

	return 0;
}
