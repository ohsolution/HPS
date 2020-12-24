#include <bits/stdc++.h>

#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<int,int>
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

const int max_v = 2e5 + 7;
const LL INF = 1e18 + 7;
const LL mod = 20090711;

int arr[max_v][2];
int lk, rk;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt; ci(cnt);
	while (cnt--)
	{
		int n; ci(n);
		vector <int> va(n);
		vector <int> vb;

		fa(i, 0, n) ci(va[i]);

		fa(i, 1, va[0]) vb.push_back(i);

		fa(i, 0, va.size()-1) fa(j, va[i] + 1, va[i + 1]) vb.push_back(j);
		
		fa(i, va.back() + 1, 2 * n + 1) vb.push_back(i);

		fa(i, 0, va.size())
		{
			auto x = va[i];

			int idx = lower_bound(vb.begin(), vb.end(), x) - vb.begin();

			arr[i+1][0] = vb.size() - idx;
			arr[i+1][1] = idx;
		}

		lk = rk = 0;
		int s = 0;

		fd(i, n, 0)
		{
			if (arr[i][0] - s > 0 )
			{
				++rk;
				++s;
			}
		}

		s = 0;

		fa(i, 1, n + 1)
		{
			if (arr[i][1] - s > 0)
			{
				++lk;
				++s;
			}
		}

		co(rk + 1 - (n - lk) << "\n");

	}
	return 0;
}
