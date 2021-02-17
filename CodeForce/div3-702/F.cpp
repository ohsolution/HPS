
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


#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define ld long double
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
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


pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,0},{1,1}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 1e4 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)1e18 + 7ll;
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
		int n; ci(n);
		map<int, int> xh;
		fa(i, 0, n)
		{
			int x; ci(x);
			++xh[x];
		}

		
		vector <int> tar;
		for (auto x : xh) tar.push_back(x.second);
		n = tar.size();

		sort(tar.begin(), tar.end());
		vector <int> ldp(n, 0);
		vector <int> rdp(n, 0);

		ldp[0] = tar[0];
		fa(i, 1, n) ldp[i] = ldp[i - 1] + tar[i];
		rdp[n - 1] = tar[n - 1];
		fd(i, n - 2, -1) rdp[i] = rdp[i + 1] + tar[i];

		LL ans = LNF;

		fa(i, 0, n)
		{
			LL l = i ? ldp[i - 1] : 0;
			LL r = rdp[i] - (n - i) * tar[i];
			ckmin(ans, l + r);
		}
		co(ans << "\n");
	}
	return 0;
} 
