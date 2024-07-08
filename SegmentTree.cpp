#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Function to perform range sum query
long long query(long long node, long long st, long long en, long long l, long long r, long long tree[]) {
    if (st > r || en < l)
        return 0;
    if (st >= l && en <= r) {
        return tree[node];
    }
    long long mid = (st + en) / 2;
    return query(2 * node, st, mid, l, r, tree) + query(2 * node + 1, mid + 1, en, l, r, tree);
}

void update(long long node, long long st, long long en, long long ind, long long val, long long tree[], long long v[]) {
    if (st == en) {
        v[ind] = val;
        tree[node] = val;
        return;
    }

    long long mid = (st + en) / 2;
    if (ind <= mid)
        update(node * 2, st, mid, ind, val, tree, v);
    else
        update(node * 2 + 1, mid + 1, en, ind, val, tree, v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    long long n, q, w;
    cin >> n >> q;
    long long v[n + 1] = {0};
    long long tree[4 * (n + 1)] = {0}; 

    // Building the Segment Tree
    for (long long i = 0; i < n; i++) {
        cin >> w;
        update(1, 0, n - 1, i, w, tree, v);
    }

    // Processing the queries
    while (q--) {
        long long k, l, r;
        cin >> k >> l >> r;
        switch (k) {
            case 1:
                // Update the value at index l-1 to r
                update(1, 0, n - 1, l - 1, r, tree, v);
                break;
            case 2:
                // Output the sum of values in the range [l-1, r-1]
                cout << query(1, 0, n - 1, l - 1, r - 1, tree) << endl;
                break;
        }
    }
    return 0;
}
