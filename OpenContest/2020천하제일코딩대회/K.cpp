//================code===================//
#include <bits/stdc++.h>
#include <unordered_map>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(LL i=a;i<b;++i)
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
const LL mod = 1e9 + 7;

struct node
{
	LL h;
	LL ssz;
};

struct cmp
{
	bool operator()(setl x, setl b)
	{
		return x.second < b.second;
	}
};

node arr[max_v];
vector <int> adj[max_v];
int p[max_v];
int root;
priority_queue <setl, vector<setl>, cmp> pq;
bool vist[max_v];
LL ans, bns;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ci(n);
	fa(i, 1, n+1) ci(p[i]);
	fa(i, 1, n + 1)
	{
		if (p[i]) adj[p[i]].push_back(i);
		else root = i;
	}

	queue <setl> bq; bq.push({ root,0 });


	while(!bq.empty())
	{
		setl cur = bq.front(); bq.pop();
		
		arr[cur.first].h = cur.second;

		for (auto x : adj[cur.first]) bq.push({ x,cur.second+ 1 });

		if (adj[cur.first].empty())
		{
			pq.push(cur);
		}
	}

	while (!pq.empty())
	{
		setl cur;

		do {
			cur = pq.top(); pq.pop();
		} while (!pq.empty() && vist[cur.first]);

		if (!cur.second || vist[cur.first]) break;

		vist[cur.first] = true;

		arr[p[cur.first]].ssz += arr[cur.first].ssz+1;
		pq.push({ p[cur.first],arr[p[cur.first]].h });
	}

	//fa(i, 1, n + 1) ce(i << "th ssz: " << arr[i].ssz << "\n");

	LL tar = 0;

	fa(i, 1, n + 1)
	{
		LL x = 1;
		x += arr[i].ssz << 1;

		LL y = 0;

		fa(j, 0, adj[i].size())
		{
			fa(t, j+1, adj[i].size())
			{
				y += (arr[adj[i][j]].ssz + 1) * (arr[adj[i][t]].ssz + 1);
			}
		}

		y *= 2;

		if (adj[i].size()>1) x += y;

		ce(i << "th num :" << x << endl);

		LL sum = i * x;

		if (tar & 1) //cur odd
		{
			if (x & 1)
			{
				ans += (sum + i) / 2;
				bns += (sum - i) / 2;
			}
			else
			{
				ans += sum / 2;
				bns += sum / 2;
			}
		}
		else // cur even
		{
			if (x & 1)
			{
				ans += (sum - i) / 2;
				bns += (sum + i) / 2;
			}
			else
			{
				ans += sum / 2;
				bns += sum / 2;
			}
		}

		tar += x;
	}

	ce(tar << endl);

	AT
	co(ans << " " << bns);
	AE
	
	return 0;
}
