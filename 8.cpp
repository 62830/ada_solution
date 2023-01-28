#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;++i)
int m=100;

void f(int a,int b){
	if(a>=b)
		return;
	
	FOR(i,a,b+1){
		cout<<"POP"<<endl;
		--m;
	}
	cout<<"PLACE "<<a<<endl;
	--m;
	for(int i=b;i>a;--i){
		cout<<"PLACE "<<i<<endl;
		--m;
	}
	cout<<"PHOTO"<<endl;
	--m;
	if(b-a==1)
		return;
	
	f(a+1,(a+b+1)/2);
	FOR(i,a+1,b+1){cout<<"POP"<<endl;--m;}
	FOR(i,a+1,(a+b+1)/2+1){cout<<"PLACE "<<i<<endl;--m;}
	for(int i=b;i>(a+b+1)/2;--i){
		cout<<"PLACE "<<i<<endl;
		--m;
	}
	cout<<"PHOTO"<<endl;
	--m;
	f((a+b+1)/2+1,b); 
	return; 
} 
int main(){ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	cout<<m<<endl;
	FOR(i,0,n){
		cout<<"PLACE "<<n-i<<endl;
		--m;
	}
	cout<<"PHOTO"<<endl;
	--m;
	if(n>1){

	f(1,n/2);
	FOR(i,1,n+1){
		cout<<"POP"<<endl;
		--m;
	}
	FOR(i,1,n/2+1){
		cout<<"PLACE "<<i<<endl;
		--m;
	}
	for(int i=n;i>n/2;--i){
		cout<<"PLACE "<<i<<endl;
		--m;
	}
	cout<<"PHOTO"<<endl;
	--m;
	f(n/2+1,n);
	
	}

	FOR(i,0,n){
		if(m<=0)break;
		cout<<"POP"<<endl;
		--m;
	}


	while(m>0){
		cout<<"PLACE "<<1<<endl;
		--m;
		if(m<=0)break;
		cout<<"POP"<<endl;
		--m;
	}

	return 0;
}

