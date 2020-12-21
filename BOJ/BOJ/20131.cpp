#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define ci(t) cin>>t
#define co(t) cout<<t
#define LL long long
#define fa(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>b;--i)
#define setp pair<pair<int,int>,int>
#define setl pair<int,LL>
using namespace std;

int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
LL lcm(LL a, LL b) { return (a * b) / gcd(a, b); }
//vector <bool> prime(max_v, true); for (int i = 2; i * i < max_v; ++i) if (prime[i]) for (int j = i * 2; j < max_v; j += i) prime[j] = false; // get prime under max_v	

const int msz = 5e5 + 7;
const LL INF = 1e18 + 7;
const int mod = 1e9 + 7;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int p[msz];
vector <int> vi, num;
int n;
vector <setl> ans;
priority_queue <int, vector<int>, cmp> pq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ci(n);
	vi.resize(n - 2); num.resize(n + 1);
	fa(i, 0, n - 2) ci(vi[i]);
	for (auto x : vi) ++num[x];
	fa(i, 1, n + 1) if (!num[i]) pq.push(i);

	int c = 0;

	while (!pq.empty())
	{
		int cur = pq.top(); pq.pop();

		p[cur] = vi[c];
		if (--num[vi[c]] == 0) pq.push(vi[c]);
		ans.push_back({ min(cur,vi[c]),max(cur,vi[c]) });
		if (++c == n - 2) break;
	}

	if (pq.size() != 2 && c != n - 2 && ans.size() != n - 2) co(-1);
	else
	{
		int tmp = pq.top(); pq.pop();
		ans.push_back({ min(tmp,pq.top()),max(tmp,pq.top()) });
		sort(ans.begin(), ans.end());

		for (auto x : ans)
		{
			co(x.first << " " << x.second << "\n");
		}
	}

	return 0;
}
