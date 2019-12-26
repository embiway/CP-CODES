#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    ll n = s.size();
	char str[n];
	
	for(ll i=n-1;i>=0;i--)
	{
		str[n-i-1] = s[i];
	}
    ll maxlen = 1;
    ll dp[n+1][n+1];
    for(ll i=0;i<=n;i++)
    	for(ll j=0;j<=n;j++)
    		dp[i][j]=0;

    //lcs
    
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(s[i-1] == str[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	
	cout << n-dp[n][n]<<endl;
  }
  return 0;
}