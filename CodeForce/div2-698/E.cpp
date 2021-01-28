
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

const int max_v = 2e5 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 1e9 + 7;

vector <int> arr;
vector <int> lazy;

void propagate(int node, int nl, int nr)
{
	if (lazy[node])
	{
		if (nl != nr)
		{
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}

		if (lazy[node] == 2) arr[node] = (nr - nl + 1);
		else arr[node] = 0;
		lazy[node] = 0;
	}
	
}

void update(int l, int r, int val, int node, int nl, int nr)
{
	propagate(node, nl, nr);

	if (nr < l || nl > r) return;

	if (l <= nl && nr <= r)
	{
		lazy[node] = val;
		propagate(node, nl, nr);
		return;
	}

	int mid = (nl + nr) >> 1;

	update(l, r, val, node * 2, nl, mid);
	update(l, r, val, node * 2 + 1, mid + 1, nr);

	arr[node] = arr[node * 2] + arr[node * 2 + 1];
}

LL query(int l, int r, int node, int nl, int nr)
{
	propagate(node, nl, nr);

	if (nr <l || nl > r) return 0;

	if (l <= nl && nr <= r) return arr[node];

	int mid = (nl + nr) >> 1;

	return query(l, r, node * 2, nl, mid) + query(l, r, node * 2 + 1, mid + 1, nr);
}

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt; ci(cnt);
	while (cnt--)
	{
		int n, q; ci(n >> q);

		vector <int> vf(n),ve(n);
		arr.resize((n+7) * 4, 0);
		lazy.resize((n+7) * 4, 0);

		string a, b; ci(a >> b);
		fa(i, 0, n) vf[i] = a[i] == '1';
		fa(i, 0, n) ve[i] = b[i] == '1';

		fa(i, 0, n) update(i, i, ve[i]+1, 1, 0, n - 1);

		vector <setl> vq(q);
		fa(i, 0, q) ci(vq[i].first >> vq[i].second);
		for (auto& x : vq) --x.first, --x.second;
		reverse(vq.begin(), vq.end());


		bool ck = true;
		for (auto x : vq)
		{
			int pn = x.second - x.first+1;
			int cn = (x.second - x.first)/2;
			int s = query(x.first, x.second, 1,0,n-1);
			
			if (s*2 == pn)
			{
				ck = false;
				break;
			}

			int up = s > cn;

			update(x.first, x.second, up+1,1,0,n-1);
		}
		AT;
		if (!ck)
		{
			co("NO\n");
		}
		else
		{
			bool tk = true;
			fa(i, 0, n)
			{
				if (query(i, i, 1, 0, n - 1) != vf[i])
				{
					tk = false;
					break;
				}
			}

			tk ? co("YES\n") : co("NO\n");

		}
		AE;
	}
	return 0;
}
