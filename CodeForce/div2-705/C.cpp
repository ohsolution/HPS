
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
#define ULL LL
#define ld long double
#define fa(i,a,b) for(LL i=(a);i<(LL)(b);++i)
#define fd(i,a,b) for(LL i=(a);i>(LL)(b);--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>
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




pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,0},{1,0}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)5e18 + 7ll;
const LL mod = 1e9 + 7;


int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	int cnt; ci(cnt);
	while (cnt--)
	{
		vector <int> alph(26, 0);
		int n, k; ci(n >> k);

		
		string s; ci(s);
		
		if ((n % k) != 0)
		{
			co(-1 << "\n");
			continue;
		}


		for (auto& x : s) ++alph[x - 'a'];
		
		bool ck = false;
		int r = 0;

		auto check = [&](int re)
		{
			int ret = 0;
			fa(i, 0, 26)
			{
				ret += (k - alph[i] % k) % k;
				if (ret > re) return false;
			}

			return true;
		};

		if (check(0))
		{
			co(s << "\n");
			continue;
		}
		
		fd(i, s.size() - 1,-1)
		{			
			--alph[s[i] - 'a'];			
			
			int tmp = (s[i] - 'a')+1;

			while (tmp <= 25)
			{
				++alph[tmp];
				if (check(r))
				{
					ck = true;
					string ans = "";
					fa(j, 0, i) ans += s[j];
					ans +=( tmp + 'a');

					fa(j, 0, 26)
					{
						int tt = (k - alph[j] % k) % k;
						r -= tt;
					}

					assert(r >= 0);
					while (r--) ans += 'a';

					fa(j, 0, 26)
					{
						int tt = (k - alph[j] % k) % k;
						while (tt--) ans += (j + 'a');
					}

					co(ans << "\n");
				}
				--alph[tmp];
				++tmp;

				if (ck) break;
			}

			if (ck) break;
			++r;
		}


		if (!ck) co("-1\n");
	}
	return 0;
}
