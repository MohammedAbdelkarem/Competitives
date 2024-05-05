#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bestio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define cy cout<<"YES"
#define cn cout<<"NO"
#define cline cout<<"\n"
#define line "\n"
#define sp " "
#define fl(begin,end) for(ll i=begin;i<end;i++)
#define rfl(begin,end) for(ll i=end-1;i>=begin;i--)
#define lb lower_bound
#define ub upper_bound
#define spr setprecision
#define mod %
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define eh emplace_hint
#define mae *max_element
#define mie *min_element
#define rev reverse
#define tc ll tc;cin>>tc;while(tc--)
#define b() begin()
#define e() end()
#define donothing int vvvccc=0;
#define twoloops(n,m) for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)
#define fst first
#define sec second
const string alphabet="abcdefghijklmnopqrstuvwxyz";
const string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool ispositive(ll n)
{
    return n>0;
}
bool isnegative(ll n)
{
    return n<0;
}
bool iseven(ll n)
{
    return !(n&1);
}
bool isodd(ll n)
{
    return n&1;
}
ll the_current_range(ll n)
{
    ll c=1;
    while(n>9)
    {
        c*=10;
        n/=10;
    }
    return c;
}
int char_as_a_number(char c)
{
    return c-'0';
}
ll string_as_a_number(string s)
{
    ll value=0,ttt=1;
    for(ll i=0; i<s.size(); i++)
    {
        value+=char_as_a_number(s[i])*ttt;
        ttt*=10;
    }
    return value;
}
string number_as_a_string(ll n)
{
    string s="";
    while(n)
    {
        s+=char((n mod 10)+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

ll the_first_digit(ll n)
{
    return n/(the_current_range(n));
}
ll the_last_digit(ll n)
{
    return n mod 10;
}
ll nsize(ll n)
{
    ll c=0;
    while(n)
    {
        n/=10;
        c++;
    }
    return c;
}
bool isprime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
bool isunique(ll n)
{
    set<int>s;
    ll c=0;
    while(n)
    {
        auto it=s.begin();
        it=s.emplace_hint(it,(n%10));
        n/=10;
        c++;
    }
    return (s.size()==c) ? true : false;
}
bool isevenarr(int a[],ll sizeofarr)
{
    ll counter=0;
    for(ll i=0; i<sizeofarr; i++)
    {
        if(iseven(a[i]))counter++;
    }
    return (counter==sizeofarr) ? true : false;
}
bool isoddarr(int a[],ll sizeofarr)
{
    ll counter=0;
    for(ll i=0; i<sizeofarr; i++)
    {
        if(isodd(a[i]))counter++;
    }
    return (counter==sizeofarr) ? true : false;
}
bool ispalindrome(string s)
{
    string ss=s;
    reverse(ss.begin(),ss.end());
    return (s==ss) ? true : false;
}
ll digitsum(ll n)
{
    ll sum=0;
    while(nsize(n))
    {
        sum+=the_last_digit(n);
        n/=10;
    }
    return sum;
}
ll arrsum(int a[],int sizeofarr)
{
    ll sum=0;
    for(ll i=0; i<sizeofarr; i++)
        sum+=a[i];
    return sum;
}
/*
void trans_of_arr(int a[][],int n,int m)
{
	int b[m][n];
	for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		b[i][j]=a[j][i];
    	}
    }
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<b[i][j]<<sp;
    	    cline;
    	}
    }
}*/
string binary(ll n)
{
    string s="";
    while(n)
    {
        s+=char((n mod 2)+'0');
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
bool issubstring(string base,string part)
{
    int index=base.find(part);
    if(index==string::npos)
        return false;
    return true;
}
/*int charsnum(string s)
{
	int cnt[26]={0};
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'a']++;
}*/
ll gcd(ll a,ll b)
{
    if(!a or !b)
        return a | b;
    unsigned ll shift=__builtin_ctz(a | b);
    a >>=__builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if(a>b)
            swap(a,b);
        b-=a;
    }
    while(b);
    return a << shift;
}
ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
ll fact(ll n)
{
    ll ans=1;
    for(ll i=1; i<=n; i++)
        ans*=i;
    return ans;
}
bool issortedper(vector<int>a,int n)
{
    for(int i=0; i<n-1; i++)
        if(a[i+1]<=a[i])
            return false;
    return true;
}
bool vandvv(vector<char>v,vector<char>vv)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] != vv[i])
            return false;
    }
    return true;
}
ll p(ll a,ll b)
{
    if(b==0)
    {
        return 1LL;
    }
    return a*p(a,b-1);
}
ll f(ll x)
{
    for(ll i=2; i*i<=x; i++)
        if(x%i==0)
            return i;
    return x;
}
bool issorted(int a[],int n)
{
    set<int>v;
    auto it=v.begin();
    for(int i=0; i<n; i++)
        it=v.eh(it,a[i]);
    int c=0;
    for(auto j:v)
    {
        if(j != a[c++])
            return false;
    }
    return true;
}
ll strsum(string s,ll n)
{
    ll sum=0;
    for(int i=0; i<n; i++)
        sum+=s[i]-'0';
    return sum;
}
ll vectorsum(vector<int>v)
{
	ll sum=0;
	fl(0,v.size())
		sum+=v[i];
	return sum;
}
ll sum_to_n(ll n)
{
	return n*(n+1)/2;
}
ll rangesum(ll mx,ll mn)
{
	return mx*(mx+1)/2-mn*(mn+1)/2+mn;
}
bool isinarr(int a[],int size,int ele)
{
	return (*lb(a,a+size,ele) == ele);
}
bool isthree(ll n)
{
	if(!(n%3) or the_last_digit(n)==3)return true;
	return false;
}
bool islucky(ll n)
{
	while(n)
	{
		if(n  mod 10 == 7 or n mod 10 == 4)
			int c=0;
		else
			return false;
		n/=10;
	}
	return true;
}
ll last_degit_npm(ll n,ll m)
{
	int c=n mod 10;
	if(!c)
		return 1;
	else if(c == 1 or c == 5 or c == 6)
		return c;
	else if(c == 4 or c == 9)
	{
		int ans[2];
		if(c ==4)
		{
			ans[0]=4;ans[1]=6;
		}
		else
		{
			ans[0]=9;ans[1]=1;
		}
		return ans[(m-1) mod 2];
	}
	else
	{
		int ans[4];
		if(c == 2)
		{
			ans[0]=2;ans[1]=4;ans[2]=8;ans[3]=6;
		}
		else if(c == 3)
		{
			ans[0]=3;ans[1]=9;ans[2]=7;ans[3]=1;
		}
		else if(c == 7)
		{
			ans[0]=7;ans[1]=9;ans[2]=3;ans[3]=1;
		}
		else
		{
			ans[0]=8;ans[1]=4;ans[2]=2;ans[3]=6;
		}
		return ans[(m-1) mod 4];
	}
}
int chara(int a[],int n)
{
	vector<int>x,y;
	int yy=a[0];
	fl(0,n)
	{
		if(a[i] == yy)
			x.pb(a[i]);
		else
			y.pb(a[i]);
	}
	int p=x.size(),q=y.size();
	return (p*(p-1))/2 + (q*(q-1))/2;
}
void _swap(int a[],int i,int j)
{
	a[i] = a[i] ^ a[j];
    a[j] = a[j] ^ a[i];
    a[i] = a[i] ^ a[j];
}
ll num_of_divisors(ll n)
{
	vector<int>v;
	ll c=2;
	while(n > 1)
	{
		if(n mod c == 0)
		{
			v.pb(c);
			n/=c;
		}
		else
			c++;
	}
	sort(v.b(),v.e());
	vector<int>ans;
	ll cc=2;
	fl(0,v.size())
	{
		if(v[i] == v[i+1])
			cc++;
		else
		{
			ans.pb(cc);
			cc=2;
		}
	}
	ll z=1;
	fl(0,ans.size())
		z*=ans[i];
	return z;
}
int dif_between_chars(char c,char cc)
{
	return min({abs(c-cc),abs(cc-c),abs(c-cc-26),abs(cc-c-26)});
}
// two funs to return the sum of range
//build the pre array in main then use these funs to get the wanted vlaue
//these funs will take the pre array
// void build_one_pre()
// {
	// int pre[size+1]={0};
	// for(int i=1;i<size+1;i++)
		// pre[i]  +=  pre[i-1] + a[i-1];
// }
// void build_two_pre()
// {
	// int pre[n+1][m+1];
	// pre[0][0]=0;
	// for(int i=1;i<n;i++)
		// for(int j=1;j<m;j++)
			// a[i][j] += a[i][j-1];
	// for(int j=1;j<n;j++)
		// for(int i=1;i<m;i++)
			// a[i][j] += a[i-1][j];
// }
ll one_range_sum(ll pre[],ll start,ll end)
{
	return pre[end] - pre[start - 1];
}
// int two_range_sum(int pre[][m],int i,int j k,int l)
// {
	// return pre[k][l] - pre[k][j-1] - pre[i-1][l] + pre[i-1][j-1];
// }
vector<ll> initializeDiffArray(vector<ll>& A)
{
    int n = A.size();
    vector<ll> D(n + 1);
    D[0] = A[0], D[n] = 0;
    for (ll i = 1; i < n; i++)
        D[i] = A[i] - A[i - 1];
    return D;
}
void update(vector<ll>& D, ll l, ll r, ll x)
{
	l--;r--;
    D[l] += x;
    D[r + 1] -= x;
}
ll printArray(vector<ll>& A, vector<ll>& D)
{
    for (ll i = 0; i < A.size(); i++) {
        if (i == 0)
            A[i] = D[i];
        else
            A[i] = D[i] + A[i - 1];

        cout << A[i] << " ";
    }
    cout << endl;
}
vector<int>unique_vec(vector<int>&v)
{
	unordered_set<int>us;
	auto it=us.b();
	for(int i = 0; i < v.size(); i++)
		it=us.eh(it,v[i]);
	vector<int>ans;
	for(auto it:us)
		ans.pb(it);
	rev(ans.b(),ans.e());
	return ans;
}
int index_in_vec(vector<int>v,int k)
{
	auto it = find(v.b(),v.e(),k);
	int ans = it - v.b();
	return ans;
}
// vector<ll>subseq_sum(vector<ll>&v)
// {
	// int s = v.size()+1;
	// ll p[s]={0};
	// for(int i=1;i<s;i++)
		// p[i] = p[i-1] + v[i-1];
	// vector<ll>ans;
	// fl(1,s)
		// ans.pb(p[i]);
	// for(int i=1;i<s;i++)
	// {
		// for(int j=i+1;j<s;j++)
		// {
			// ans.pb(p[j] - p[i]);
		// }
	// }
	// return ans;
// }
ll sum(int a[] , int n,int m)
{
	if(n == m)
		return a[m-1];
	return a[n-1] + sum(a,n-1,m);
}
bool ischar(string s)
{
	if(s == "a" or s == "b")
		return true;
	return false;
}
bool one(vector<int>v)
{
	for(int i=0;i<v.size();i++)
		if(v[i] != 1)
			return false;
	return true;
}
int index_of_prev(vector<int>v,int ele)
{
	return lb(v.b() , v.e() , ele) - v.b() -1;
}
int f(int n)
{
	if(n == 1)
		return 1;
	if(iseven(n))
		return f(n/2) + 1;
	else
		return f(3*n+1) + 1;
}
int n, m;
bool good(int i, int j)
{
	if(i < 0 || i >= n || j < 0 || j >= m) return false;
	return true;
}
char upper(char c)
{
	c =toupper(c);
	return c;
}
int main()
{
	bestio;
	tc
	{
		int n,k;cin>>n>>k;
		string s;cin>>s;ll ans=0;
		map<char , int>u , l;
		auto it=u.b() , itt=l.b();
		fl(0,alphabet.size())
			itt=l.eh(itt , alphabet[i] , 0);
		fl(0,alp.size())
			it=u.eh(it , alp[i] , 0);
		fl(0,n)
		{
			if(isupper(s[i]))
				u[s[i]]++;
			else
				l[s[i]]++;
		}
		fl(0,alphabet.size())
		{
			int x = l[alphabet[i]];
			int y = u[upper(alphabet[i])];
			if(x and y)
			{
				int z = min(x , y);
				ans+=z;
				l[alphabet[i]]-=z;
				u[upper(alphabet[i])]-=z;
			}
		}
		for(int i=0;i<alphabet.size();)
		{
			int x = l[alphabet[i]];
			int y = u[upper(alphabet[i])];
			if(x <= 1 and y <= 1)
				i++;
			else
			{
				if(x > 1)
				{
					if(isodd(x))
						x--;
					if(k == x/2)
					{
						ans+=k;
						k=0;
						x=0;
					}
					else if(k > x/2)
					{
						k-=x/2;
						x=0;
						ans+=x/2;
					}
					else
					{
						ans+=k;
						k=0;
						x-=k*2;
					}
				}
				else if(y > 1)
				{
					if(isodd(y))
						y--;
					if(k == y/2)
					{
						ans+=k;
						k=0;
						y=0;
					}
					else if(k > y/2)
					{
						k-=y/2;
						y=0;
						ans+=y/2;
					}
					else
					{
						ans+=k;
						k=0;
						y-=k*2;
					}
				}
				i++;
			}
		}
	}
}