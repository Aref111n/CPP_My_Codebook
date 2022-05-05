//BIT
ll bit[MX];
ll n ;
///set a[idx]+=val;
void update(ll idx,ll  val)
{
    while(idx <= n){
        bit[idx] += val;
        idx += (idx&-idx);
    }
}
///returns the prefix sum from 0 to idx
ll qry(ll idx)
{
    ll ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx&-idx);
    }
    return ret;
}
