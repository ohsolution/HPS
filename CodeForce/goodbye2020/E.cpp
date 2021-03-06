
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
const LL mod = 1e9 + 7;

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
		vector <LL> brr(64, 0);

		vector <LL> vi(n);

		fa(i, 0, n) ci(vi[i]);

		for (auto x : vi)
		{
			fa(i, 0, 61)
			{
				LL bit = 1ll << i;

				brr[i] += x & bit;
				brr[i] %= mod;
			}
		}

		LL sum = 0;

		for (auto x : vi)
		{
			LL l, r;
			l = r = 0;

			LL y = ~x;

			fa(i, 0, 61)
			{
				LL bit = 1ll << i;

				if (x & bit)
				{
					l += brr[i];
					l %= mod;
				}

				if (y & bit)
				{
					r += brr[i];
					r %= mod;
				}
			}
			
			r += (x%mod) * n;
			r %= mod;
			l %= mod;

			sum += (l * r) % mod;
			sum %= mod;
		}

		AT;
		co(sum << "\n");
		AE;

	}
	return 0;
}
