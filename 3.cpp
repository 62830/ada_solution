#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vvi vector<vector<int>>
//for debugs
#define print(...) cout<<#__VA_ARGS__<<": "<<__VA_ARGS__<<endl;

template<typename T>
void print_arr(T arr){
	for(auto &i:arr)cout<<i<<' ';
	cout<<endl;
}

int main(){
	string a,b;
	cin>>a;
	cin>>b;

	vvi dp(b.size()+1,vi(a.size()+1,0));

	FOR(i,0,b.size()+1){
		FOR(j,0,a.size()+1){
			if(i==0){
				dp[i][j] = j;
				continue;
			}
			if(j==0){
				dp[i][j] = i;
				continue;
			}
			dp[i][j] = min(dp[i-1][j-1]+!(b[i-1]==a[j-1]),dp[i][j-1]+1);
			dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
		}
	}
	cout<<dp.back().back()<<endl;
	return 0;
}
