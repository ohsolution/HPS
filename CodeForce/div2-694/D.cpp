

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

const int max_v = 1e6 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e16 + 7;
const LL mod = 1e9 + 7;

int arr[max_v];

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt; ci(cnt);

	fa(i, 1, 1000001)
	{
		int x = i;
		int tn = 0;
		int s = 1;

		while (x % 2 == 0)
		{
			x /= 2;
			++tn;
		}

		if (tn & 1) s *= 2;

		for (int t = 3; t * t <= x; t+=2)
		{
			int cn = 0;
			while (x % t == 0)
			{
				x /= t;
				++cn;
			}

			if (cn & 1) s *= t;
		}

		s *= x;

		arr[i] = s;
	}

	while(cnt--)
	{
		int n; ci(n);
		vector <int> vi(n);
		fa(i, 0, n) ci(vi[i]);

		LL lmaxi = 1;
		LL rmaxi = 1;

		map <LL, LL> xhash;

		fa(i, 0, n)
		{
			++xhash[arr[vi[i]]];
		}

		for (auto x : xhash)
		{
			ckmax(lmaxi, x.second);
			if (x.second & 1) ckmax(rmaxi, x.second);
		}

		for (auto x : xhash)
		{
			if (x.first != 1 && x.second % 2 == 0) xhash[1] += x.second;
		}

		ckmax(rmaxi, xhash[1]);

		int q; ci(q);
		AT;
		fa(i, 0, q)
		{
			LL x; ci(x);
			if (x == 0) co(lmaxi << "\n");
			else co(rmaxi << "\n");
		}
		AE;

	}

	
	return 0;
}
