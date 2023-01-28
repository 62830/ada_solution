#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int a[5005],dp[5005];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,w;
	cin>>w>>n;
	FOR(i,0,w)cin>>a[i];
	sort(a,a+w);

	FOR(i,1,n+1){
		int k=i;
		dp[i] = dp[i-1]+1;
		FOR(j,0,w)
			if(i-a[j]>=0)
				dp[i] = min(dp[i],dp[i-a[j]]);
		
		for(int j=w-1;j>=0;--j)
			k %= a[j];
		cout<<k-dp[i]<<endl;
	}
	return 0;
}	
			
	
