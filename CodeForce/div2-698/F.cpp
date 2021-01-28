
//================code===================//

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>
#define M_PI 3.14159265358979323846
#define micro 0.000001

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
#else
#define AT
#define AE
#define ce(t)
#endif

using namespace std;

LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }

pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,0},{1,1}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 6e3 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 1e9 + 7;

bool vist[max_v];
inline LL ptp(setl x, setl y) { return (y.first - x.first) * (y.first - x.first) + (y.second - x.second) * (y.second - x.second);}

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; ci(n); vector <setl> vs(n);
	fa(i, 0, n) ci(vs[i].first >> vs[i].second);
	int sp = 0;
	
	int sz = n;
	while (sz--)
	{
		vist[sp] = 1;
		co(sp + 1 << " ");

		LL ret = 0;
		LL rp = -1;

		fa(i, 0, n)
		{
			if (!vist[i] && ptp(vs[sp], vs[i]) > ret)
			{
				ret = ptp(vs[sp], vs[i]);
				rp = i;
			}
		}

		sp = rp;
	}


	return 0;
}
