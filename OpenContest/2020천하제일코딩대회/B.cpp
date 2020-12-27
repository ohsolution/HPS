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

struct info
{
	int x, y, cr;
};

int n;
string arr[17];
int colo[17][17];
int ans;
queue <info> bq;

int f(int x, int y)
{
	memset(colo, 0, sizeof(colo));
	while (!bq.empty()) bq.pop();
	
	char ori = arr[x][y];
	arr[x][y] = 'S';

	int c = 1;

	fa(i, 0, 4)
	{
		int nx = x + vu[i].first;
		int ny = y + vu[i].second;


		if (nx == -1 || ny == -1 || nx == n || ny == n || arr[nx][ny] != '.') continue;

		bq.push({ nx,ny,c++ });
	}

	ce(x << " " << y <<" "<< bq.size() << endl);

	if (bq.size() < 2)
	{
		arr[x][y] = ori;
		return 0;
	}

	while (!bq.empty())
	{
		info cur = bq.front(); bq.pop();

		colo[cur.x][cur.y] = cur.cr;

		fa(i, 0, 4)
		{
			int nx = cur.x + vu[i].first;
			int ny = cur.y + vu[i].second;

			if (nx == -1 || ny == -1 || nx == n || ny == n || arr[nx][ny] != '.') continue;

			if (colo[nx][ny] < cur.cr)
			{
				colo[nx][ny] = cur.cr;
				bq.push({ nx,ny,colo[nx][ny]});
			}
		}
	}

	fa(i, 0, n)
	{
		fa(j, 0, n)
		{
			if (colo[i][j] && colo[i][j] != c - 1)
			{
				arr[x][y] = ori;
				return 1;
			}
		}
	}


	arr[x][y] = ori;

	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ci(n);
	fa(i, 0, n) ci(arr[i]);

	fa(i, 0, n)
	{
		fa(j, 0, n)
		{
			if (arr[i][j] == '.') ans += f(i, j);
		}
	}

	AT
		co(ans);
	AE

	return 0;
}
