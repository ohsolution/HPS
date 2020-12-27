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

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 998244353;

int indeg[max_v];
vector <int> adj[max_v];
int n, m, q;
vector <int> ansset;
bool check[max_v];
bool vist[max_v];

void dfs(int idx)
{
	vist[idx] = true;
	for (auto x : adj[idx]) if (!vist[x]) dfs(x);
	return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ci(n >> m);
	fa(i, 0, m)
	{
		int x, y; ci(x >> y); --x; --y;

		if (x != y)
		{
			adj[x].push_back(y);
			++indeg[y];
		}
	}
	
	fa(i, 0, n) if (!indeg[i]) ansset.push_back(i);
	
	ci(q);
	fa(i, 0, q)
	{
		int x; ci(x); --x;
		check[x] = 1;
	}

	bool ck = true;

	for (auto x : ansset)
	{
		if (check[x]) continue;

		ck = false;
		break;
	}

	if (!ck) co("-1");
	else
	{
		for (auto x : ansset) dfs(x);

		LL ans = ansset.size();

		fa(i, 0, n)
		{
			if (!vist[i] && check[i])
			{
				++ans;
				dfs(i);
			}
		}


		co(ans);
	}

	return 0;
}
