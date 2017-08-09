typedef long long ll;
ll mu[100005];
void mobius(ll border)
{
	mu[1]=1;
	for(ll i=1;i<=border;i++){
		for(ll j=i+i;j<=border;j+=i){
			mu[j]-=mu[i];
		}
	}
}

int mo[Mn];int sum[Mn];
void mobius() {
	mo[1]=1;
	for(int i=2;i<=Mn;i++) {
		if(!no[i]) {
			prime[++tot]=i;
			mo[i]=-1;
		}
		for(int j=1;prime[j]*i<=Mn;j++) {
			no[prime[j]*i]=1;
			if(i%prime[j]==0) {
				mo[prime[j]*i]=0;
				break;
			}
			mo[prime[j]*i]=-mo[i];
		}
	}
}