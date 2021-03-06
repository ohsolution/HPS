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
#define ULL LL
#define ld long double
#define fa(i,a,b) for(LL i=(a);i<(LL)(b);++i)
#define fd(i,a,b) for(LL i=(a);i>(LL)(b);--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>
#define micro 0.000001

using namespace std;

LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"

LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
#else
#define AT
#define AE
#define ce(t)
#define __popcnt __builtin_popcountll
#define lcm __lcm
#endif




pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,0},{1,0}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9 + 7;


vector <LL> prime;
int sp[max_v];
map<int, int> xh[200000];
LL arr[max_v];

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fa(i, 2, max_v)
	{
		if (!sp[i]) prime.push_back(i);
		for (auto& x : prime)
		{
			if (x * i >= max_v) break;
			sp[x * i] = x;
			if (i % x == 0) break;
		}
	}

	int n,q; ci(n>>q);
	fa(i, 0, n) ci(arr[i]);

	LL ans = arr[0];
	fa(i, 1, n) ans = gcd(ans, arr[i]);
	fa(i, 0, n) arr[i] /= ans;

	auto update = [&](LL x)
	{
		LL tar = INF;

		for (auto t : xh[x]) ckmin(tar, t.second);
		
		vector <int> gar;
		for (auto& t : xh[x])
		{
			if((t.second -= tar)==0) gar.push_back(t.first);

		}

		for (auto xp : gar) xh[x].erase(xp);

		LL base = 1;

		while (tar--)
		{
			base = base * x % mod;
		}

		return base;
	};


	fa(i, 0, n)
	{		
		for (auto& x : prime)
		{
			if (x * x > arr[i]) break;

			int ct = 0;
			while (arr[i] % x == 0)
			{
				++ct;
				arr[i] /= x;
			}

			if (ct) xh[x][i]+=ct;
		}

		if (arr[i] != 1) xh[arr[i]][i] += 1;
	}

	fa(i, 0, q)
	{
		int idx;
		LL v; ci(idx >> v); --idx;

		for (auto& x : prime)
		{
			if (x * x > v) break;

			int ct = 0;
			while (v % x == 0)
			{
				++ct;
				v /= x;
			}

			if (ct)
			{
				xh[x][idx] += ct;
				if (xh[x].size() == n)
				{					
					ans = ans * update(x) %mod;
				}
			}
		}

		if (v != 1)
		{
			xh[v][idx] += 1;
			if (xh[v].size() == n)
			{
				ans = ans * update(v) % mod;
			}
		}

		co(ans << "\n");
	}



	return 0;
}
