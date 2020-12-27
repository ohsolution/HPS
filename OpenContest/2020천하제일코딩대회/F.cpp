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

const int max_v = 2e3 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 1e9 + 7;

LL arr[max_v][32];
string s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ci(n);
	fa(i, 0, n)
	{
		ci(s);
		LL t = 0;
		int c = 0;
		fa(j, 0, n)
		{
			arr[i][c] |= ((LL)(s[j] == '1') << t);
			if (++t == 64)
			{
				t = 0;
				++c;
			}
		}
	}

	int q; ci(q);

	fa(i, 0, q)
	{
		LL ans = 0;
		int x, y; ci(x >> y);
		--x;--y;
		fa(j, 0, (LL)(n/64 + 1))
		{
			ans += __builtin_popcountll(arr[x][j] & arr[y][j]);
		}

		co(ans << "\n");
	}

	return 0;
}
