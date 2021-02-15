#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 9223372036854775807;
const ll MOD = 1000000007;
const long double PI = acos(-1);
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a, b) cout<<a<<" "<<b<<"\n"
#define o3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define i1(a) cin>>a
#define i2(a, b) cin>>a>>b
#define i3(a, b, c) cin>>a>>b>>c
#define i4(a, b, c, d) cin>>a>>b>>c>>d
#define fi first
#define se second

inline ll power(ll a, ll b, ll z = MOD)
{
	ll res = 1;
	a = (a%z);
	while(b)
	{
		if(b&1)
			res = (res*a)%z;
		a = (a*a)%z;
		b = b>>1;
	}
	return res;
}

inline ll inverse(ll a, ll z = MOD)
{
	return power(a, z-2, z);
}

ll extend(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll g = extend(b, a%b, x1, y1);
	x = y1;
	y = x1- (a/b)*y1;
	return g;
}

class matrix
{
	public:
	ll n, aray[5][5], z = MOD;
	matrix(ll n)
	{
		this->n = n;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
				aray[i][j] = (i == j);
		}
	}
	matrix operator+(const matrix& a)
	{
		matrix ans = matrix(n);
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
				ans.aray[i][j] = (a.aray[i][j] + aray[i][j])%z;
		}
		return ans;
	}
	matrix operator*(const matrix& a)
	{
		matrix ans = matrix(n);
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				ans.aray[i][j] = 0;
				for(ll k=0;k<n;k++)
					ans.aray[i][j] = (ans.aray[i][j] + aray[i][k]*a.aray[k][j])%z;
			}
		}
		return ans;
	}
};

inline matrix mat_power(matrix x, ll b, ll z = MOD)
{
	matrix ans = matrix(x.n);
	while(b)
	{
		if(b&1)
			ans = ans*x;
		x = x*x;
		b = b>>1;
	}
	return ans;
}

// void build(ll node, ll l, ll r)
// {
//     lazy[node] = 0;
//     if(l == r)
//     {
//         tree[node] = aray[l];
//         return ;
//     }
//     ll mid = (l+r)>>1;
//     build(node<<1, l, mid);
//     build((node<<1)+1, mid+1, r);
//     tree[node] = tree[node<<1] + tree[(node<<1)+1];
//     return ;
// }

// void update(ll node, ll l, ll r, ll left, ll right, ll val)
// {
//     if(lazy[node] != 0)
//     {
//         tree[node] += (r-l+1)*lazy[node];
//         if(l != r)
//         {
//             lazy[node<<1] += lazy[node];
//             lazy[(node<<1)+1] += lazy[node];
//         }
//         lazy[node] = 0;
//     }
//     if(left > r || l > right)
//         return ;
//     if(left <= l && right >= r)
//     {
//         tree[node] += val*(r-l+1);
//         if(l != r)
//         {
//             lazy[node<<1] += val;
//             lazy[(node<<1)+1] += val;
//         }
//         return ;
//     }
//     ll mid = (l+r)>>1;
//     update(node<<1, l, mid, left, right, val);
//     update((node<<1)+1, mid+1, r, left, right, val);
//     tree[node] = tree[node<<1] + tree[(node<<1)+1];
//     return ;
// }

// ll query(ll node, ll l, ll r, ll left, ll right)
// {
//     if(left > r || l > right)
//         return 0;
//     if(lazy[node] != 0)
//     {
//         tree[node] += (r-l+1)*lazy[node];
//         if(l != r)
//         {
//             lazy[node<<1] += lazy[node];
//             lazy[(node<<1)+1] += lazy[node];
//         }
//         lazy[node] = 0;
//     }
//     if(left <= l && right >= r)
//         return tree[node];
//     ll mid = (l+r)>>1;
//     return query(node<<1, l, mid, left, right) + query((node<<1)+1, mid+1, r, left, right);
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
    n = n%m;
    ll x = 1, low = n%m, y = 1, high = n%m, curr = 1;
    for(int i=1;i<=m;i++)
    {
        curr = (curr*n)%m;
        if(curr > high)
        {
            high = curr;
            y = i;
        }
        if(curr < low)
        {
            low = curr;
            x = i;
        }
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}