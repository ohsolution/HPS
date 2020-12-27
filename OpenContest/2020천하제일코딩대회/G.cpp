//================code===================//
#include <bits/stdc++.h>
#include <unordered_map>

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
#define AT cerr << "\n=================ANS=================\n";
#define AE cerr << "\n=====================================\n";
#else
#define AT
#define AE
#define ce(t)
#endif

using namespace std;

LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }

pair <int, int> vu[8] = { {0,1},{-1,0},{0,-1} ,{1,0},{0,1}, {0,-1} , {1,0},{-1,0} }; //RLDU EWSN

template<typename T, typename U>
void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U>
void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } };

const int max_v = 1e2 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 998244353;

vector <int> vi;
vector <setl> key[max_v];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; ci(n >> m);
	vi.resize(n);
	fa(i, 0, n) ci(vi[i]);
	fa(i, 0, n)
	{
		int cnt; ci(cnt);
		while (cnt--)
		{
			int x; ci(x);
			key[x].push_back({ vi[i],i });
		}
	}

	fa(i, 0, m+1) sort(key[i].begin(), key[i].end());

	int q; ci(q);

	fa(i, 0, q)
	{
		int t; ci(t);

		if (key[t].empty())
		{
			co(-1 << "\n");
			continue;
		}

		for (auto x : key[t]) co(x.second + 1 << " ");
		co("\n");
	}

	return 0;
}
