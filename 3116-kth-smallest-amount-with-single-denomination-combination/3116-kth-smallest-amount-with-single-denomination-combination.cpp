class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        ranges::sort(coins);
        vector<int> A;

        for (auto& c : coins) {
            bool flag = 0;
            for (ll x : A)
                if (c % x == 0) {
                    flag |= 1;
                    break;
                }
            if (!flag)
                A.push_back(c);
        }

        int n = A.size();

        auto check = [&](ll mid) {
            ll tot = 0;
            for (int i = 1; i <= n; i++) {
                int q = (1 << i) - 1;
                int lim = 1 << n;
                ll sgn = ((i & 1) << 1) - 1;

                while (q < lim) {
                    ll val = 1;
                    for (int j = 0; j < n; j++)
                        if ((q >> j) & 1)
                            val = lcm(val, A[j]);

                    tot += (mid / val) * sgn;

                    int c = q & -q;
                    int r = q + c;
                    q = (((r ^ q) >> 2) / c) | r;
                }
            }
            return tot >= k;
        };

        ll low = k, high = 1ll * A[0] * k;
        auto rng = views::iota(low, high + 1);

        return *ranges::lower_bound(rng, true, {},
                                    [&](ll mid) { return check(mid); });
    }
};