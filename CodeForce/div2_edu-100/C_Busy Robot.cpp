#include <bits/stdc++.h>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<LL,LL>
#define M_PI 3.14159265358979323846
#define micro 0.000001

using namespace std;

int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }

pair <int, int> vu[8] = { {0,1}, {0,-1} , {1,0},{-1,0},{1,-1},{-1,1},{0,1}, {1,0} }; // EWSN

template<typename T, typename U>
void ckmax(T& a, U b) { a = a < b ? b : a; }
struct gcmp { bool operator()(LL a, LL b) { return a < b; } };
struct lcmp { bool operator()(LL a, LL b) { return a > b; } };

const int max_v = 1e5 + 7;
const LL INF = 1e18 + 7;
const LL mod = 20090711;

setl arr[max_v];
vector <setl> sch;
vector <setl> tsc;
int n;

void get_sch()
{
	setl cp = { arr[0].first,arr[0].first + abs(arr[0].second) };
	sch.push_back(cp);
	tsc.push_back({ 0,arr[0].second });

	fa(i, 1, n)
	{
		if (arr[i].first >= sch.back().second)
		{
			sch.push_back({ arr[i].first,arr[i].first + abs(tsc.back().second - arr[i].second) });
			tsc.push_back({ tsc.back().second,arr[i].second });
		}
	}

	return;
}

LL f(LL x,LL y,LL tar)
{
	int idx = lower_bound(sch.begin(), sch.end(), make_pair(x, y)) - sch.begin();

	if (idx == sch.size()) --idx;
	else if (sch[idx].first != x) --idx;
	
	setl tp = sch[idx];
	setl vp = tsc[idx];

	LL sp, ep;
	
	if (vp.first < vp.second)
	{
		sp = (x - tp.first) + vp.first;
		ep = min((y - tp.first) + vp.first,vp.second);
	}
	else
	{
		ep = vp.first - (x - tp.first);
		sp = max(vp.first - (y - tp.first),vp.second);
	}

	return (sp <= tar && tar <= ep);
	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt; ci(cnt);

	while (cnt--)
	{
		ci(n);
		fa(i, 0, n) ci(arr[i].first >> arr[i].second);
		arr[n].first = INF;
		get_sch();
	
		LL ans = 0;
		fa(i, 0, n) ans += f(arr[i].first, arr[i + 1].first, arr[i].second);
		co(ans << "\n");
		
		sch.clear();
		tsc.clear();
	}
	return 0;
}
