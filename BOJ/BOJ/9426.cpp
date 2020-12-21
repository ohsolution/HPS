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

const int max_v = 3e5 + 7;
const LL INF = 1e18 + 7;
const LL mod = 20090711;

LL arr[max_v];
multiset<LL> hmax, hmin;
LL ans;

void rminsert(LL val)
{
	int sz = hmax.size() - hmin.size();

	if (sz)
	{
		if (*(--hmax.end()) < val) hmin.insert(val);
		else
		{
			hmin.insert(*(--hmax.end()));
			hmax.erase(--hmax.end());
			hmax.insert(val);
		}
	}
	else
	{
		if (*hmin.begin() < val)
		{
			hmax.insert(*hmin.begin());
			hmin.erase(hmin.begin());
			hmin.insert(val);
		}
		else hmax.insert(val);
	}
}

void rmdelete(LL val)
{
	if (hmax.find(val) != hmax.end())
	{		
		if (hmax.size() == hmin.size())
		{
			hmax.insert(*hmin.begin());
			hmin.erase(hmin.begin());
		}
		hmax.erase(hmax.find(val));
	}
	else
	{
		if (hmax.size() != hmin.size())
		{
			hmin.insert(*(--hmax.end()));
			hmax.erase(--hmax.end());
		}
		hmin.erase(hmin.find(val));		
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	ci(n >> k);
	fa(i, 0, n) ci(arr[i]);

	if (k <= 2)
	{
		if (k & 1) fa(i, 0, n) ans += arr[i];
		else fa(i, 0, n - 1) ans += min(arr[i], arr[i+1]);
		co(ans);
		return 0;
	}

	hmax.insert(min(arr[0], arr[1]));
	hmin.insert(max(arr[0], arr[1]));
	fa(i, 2, k) rminsert(arr[i]);

	ans += *(--hmax.end());
	fa(i, k, n)
	{
		rmdelete(arr[i - k]);
		rminsert(arr[i]);
		ans += *(--hmax.end());
	}

	co(ans);

	return 0;
}
