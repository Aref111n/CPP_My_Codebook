ll par[MX] ;
ll up[MX][35] ;
ll depth[MX] ;

void build_up() {
    par[0] = 0 ;
    loop(i, n) {
        up[i][0] = par[i] ;
        if(i)
            depth[i] = depth[par[i]]+1 ;
        loop1(j, 31) {
            up[i][j] = up[up[i][j-1]][j-1] ;
        }
    }
}

ll kth_ancestor(ll node, ll k) {
    if(depth[node]<k)
        return -1 ;

    rloop(i, 32) {
        if(k >= (1ll << i)) {
            node = up[node][i] ;
            k -= (1ll << i) ;
        }
    }

    return node ;
}

ll lca(ll a, ll b) {
    if(depth[a] < depth[b])
        swap(a, b) ;

    ll k = depth[a] - depth[b] ;

    a = kth_ancestor(a, k) ;

    if(a==b)
        return a;

    rloop(i, 32) {
        if(up[a][i]!=up[b][i]) {
            a = up[a][i] ;
            b = up[b][i] ;
        }
    }

    return up[a][0] ;
}
