//================code===================//
#include <bits/stdc++.h>
#include <unordered_map>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<int,int>
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

const int max_v = 1e2 + 7;
const int INF = 1e9 + 7;
const LL LNF = 1e18 + 7;
const LL mod = 1e9 + 7;

vector <int> va, vb;
vector <setl> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ci(n);
	va.resize(n); vb.resize(n);
	
	fa(i, 0, n)
	{
		int x, y; ci(x >> y);
		
		int lb = x - y;
		int ub = x + y;

		if (lb > ub) swap(lb, ub);

		va[i] = lb;
		vb[i] = ub;

		vi.push_back({ lb,ub });
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());


	AT
	for (auto x : vi)
	{
		int lidx = lower_bound(vb.begin(), vb.end(), x.first) - vb.begin();

		ce("lidx : " << lidx << endl);

		co(lidx + 1);

		co(" " << upper_bound(va.begin(), va.end(), x.second) - va.begin()<<"\n");
	}
	AE

	return 0;
}
