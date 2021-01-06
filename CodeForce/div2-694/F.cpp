
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

pair <int, int> vu[8] = { {0,-1},{0,1},{-1,0} ,{1,0},{-1,1}, {0,1} , {1,1},{1,-1} }; //RDLU EWSN

template<typename T, typename U>
void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U>
void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } };

const int max_v = 3e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e16 + 7;
const LL mod = 1e9 + 7;

int color[max_v];
vector <int> adj[max_v];

void dfs(int idx)
{
	bool ck = true;

	for (auto x : adj[idx]) if (color[x] == 1) ck = false;

	color[idx] = ck ? 1 : -1;

	for (auto x : adj[idx]) if (!color[x]) dfs(x);

}

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt; ci(cnt);
	while (cnt--)
	{
		int n, m; ci(n >> m);


		// clear
		fa(i, 1, n + 1) adj[i].clear(), color[i] = 0;


		fa(i, 0, m)
		{
			int x, y; ci(x >> y);

			adj[x].push_back(y);
			adj[y].push_back(x);			
		}

		dfs(1);

		vector <int> ans;

		bool ck = true;

		fa(i, 1, n + 1)
		{
			if (!color[i])
			{
				ck = false;
				break;
			}
			else if (color[i] == 1) ans.push_back(i);
		}

		AT;

		ck ? co("YES\n") : co("NO\n");
		if (ck)
		{
			co(ans.size() << "\n");
			for (auto x : ans) co(x << " ");
			co("\n");
		}

		AE;
	}
		
	
	return 0;
}
