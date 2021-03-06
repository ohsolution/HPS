

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

pair <int, int> vu[8] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,1}, {0,-1} , {1,0},{-1,0} }; //RDLU EWSN

template<typename T, typename U>
void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U>
void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } };

const int max_v = 1e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e12 + 7;
const LL mod = 1e4 + 7;

struct cmp
{
	bool operator()(setl x, setl y)
	{
		return x.second < y.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt; ci(cnt);
	while (cnt--)
	{
		int n; ci(n);
		vector <LL> degree(n+1,0);
		priority_queue<setl, vector<setl>, cmp> pq;

		LL sum = 0;

		fa(i, 0, n)
		{
			LL x; ci(x); sum += x;
			pq.push({ i + 1,x });
		}

		fa(i, 0, n - 1)
		{
			LL x, y; ci(x >> y);
			++degree[x];
			++degree[y];
		}

		AT;

		co(sum << " ");

		fa(i, 1, n - 1)
		{
			while (1)
			{
				setl cur = pq.top(); pq.pop();
				if (degree[cur.first] > 1)
				{
					sum += cur.second;
					if (--degree[cur.first] > 1) pq.push(cur);
					break;
				}
			}

			co(sum << " ");
		}
		co("\n");
		AE;
	}
	return 0;
}
