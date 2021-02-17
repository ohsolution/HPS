

//================code===================//

//#define TLE

#ifdef TLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>


#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define ld long double
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>

#define M_PI 3.14159265358979323846
#define micro 0.000001

using namespace std;

#ifdef OHSOLUTION
#define ce(t) cerr<<t
#define AT cerr << "\n=================ANS=================\n"
#define AE cerr << "\n=====================================\n"
LL gcd(LL a, LL b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
#else
#define AT
#define AE
#define ce(t)
#define __popcnt __builtin_popcount
#define gcd __gcd
#define lcm __lcm
#endif


pair <int, int> vu[9] = { {0,1},{1,0},{0,-1} ,{-1,0},{0,0},{1,1}, {-1,1} , {1,-1},{-1,-1} }; //RDLU EWSN

template<typename T, typename U> void ckmax(T& a, U b) { a = a < b ? b : a; }
template<typename T, typename U> void ckmin(T& a, U b) { a = a > b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } bool operator()(setl a, setl b) { return a.second < b.second; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } bool operator()(setl a, setl b) { return a.second > b.second; } };

const int max_v = 1e4 + 7;
const int INF = 1e9 + 7;
const LL LNF = (LL)1e18 + 7ll;
const LL mod = 1e9 + 7;

struct node
{
	LL first, second;
	LL u,v;
};

bool cmp(node a,node b)
{
	if (a.v == b.v) return a.first < b.first;
	return a.v < b.v;
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
		LL n,k; ci(n>> k);
		vector <LL> vi(n);
		vector <node> tar(k, {-1,-1,-1,-1});

		LL s = 0;
		LL maxi = -INF;

		fa(i, 0, n) ci(vi[i]),s+= vi[i],ckmax(maxi,s);
		fa(i, 0, k) ci(tar[i].first), tar[i].second = i;
		vector <LL> ans(k, -1);

		sort(tar.begin(), tar.end(),cmp);

		if (s <= 0)
		{
			LL t = 0;
			int c = 0;
			fa(i, 0, n)
			{
				t += vi[i];
				while (c<k && t >= tar[c].first) ans[tar[c++].second] = i;								
			}

			fa(i, 0, k) co(ans[i] << " ");
			co("\n");
		}
		else
		{
			
			fa(i, 0, k)
			{
				tar[i].u = (LL)ceil((max(tar[i].first - maxi,0ll)) / (ld)s);			
				tar[i].v = tar[i].first - (tar[i].u) * s;		
				//assert(tar[i].v >= 0);
			}
			
			sort(tar.begin(), tar.end(), cmp);

			LL t = 0;
			int c = 0;
			fa(i, 0, n)
			{
				t += vi[i];
				while (c < k && t >= tar[c].v)
				{
					ans[tar[c].second] = tar[c].u*(LL)n+(LL)i;
					++c;
				}
			}
			fa(i, 0, k) co(ans[i] << " ");
			co("\n");
			
		}
		
	}
	return 0;
}
