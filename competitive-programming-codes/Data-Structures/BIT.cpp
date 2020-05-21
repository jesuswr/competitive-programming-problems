ll BIT[MAXN];
void updBIT(int p, ll val){
    p++;
    for(; p < MAXN; p += p&-p) BIT[p] += val;
}
ll sumBIT(int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) ret += BIT[p];
    return ret;
}


// This is equivalent to calculating lower_bound on prefix sums array
// LOGN = log(N)

int bit[N]; // BIT array

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	
	for(int i=LOGN; i>=0; i--)
	{
		if(pos + (1 << i) < N and sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}