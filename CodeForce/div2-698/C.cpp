
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

int main()
{
#ifdef OHSOLUTION
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt; ci(cnt);
	while (cnt--)
	{
		LL n; ci(n);
		map<LL, int> xset;
		fa(i, 0, 2 * n)
		{
			LL x; ci(x); ++xset[x];
		}

		vector <LL> vi;
		bool ck = true;
		for (auto x : xset)
		{
			if (x.second != 2)
			{
				ck = false;
				break;
			}

			vi.push_back(x.first);
		}

		if (!ck)
		{
			co("NO\n");
			continue;
		}

		reverse(vi.begin(), vi.end());

		LL l = 0;

		for (auto& x : vi)
		{
			//ce(x << endl);
			x -= l;

			if (x <=0|| x % (n * 2) != 0)
			{
				ck = false;
				break;
			}

			LL tar = x / (n * 2);
			//ce(tar << endl);
			l += tar * 2;
			--n;
		}

		ck ? co("YES\n") : co("NO\n");
		AE;
	}
	return 0;
}
