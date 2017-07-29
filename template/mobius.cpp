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