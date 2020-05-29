#include <bits/stdc++.h>

using namespace std;

struct node {
    int sum;
    node *left, *right;

    node(int low, int high)
    {
        sum = (high - low + 1);
        left = NULL;
        right = NULL;
    }

    void extend(int l, int r)
    {
        if (left == NULL) {
            int mid = (l + r) >> 1;
            left = new node(l, mid);
            right = new node(mid + 1, r);
        }
    }
};

node* Root;

void updateSegTree(int index, int delta, node* root, int l, int r)
{
    if (index < l || index > r)
        return;

    if (l == r) {
        root->sum += delta;
        return;
    }

    root->extend(l, r);
    updateSegTree(index, delta, root->left, l, (l+r) / 2);
    updateSegTree(index, delta, root->right, (l+r) / 2 + 1, r);
    root->sum = (root->left)->sum + (root->right)->sum;
}

int query(int k, node* root, int l, int r)
{
    if (l == r)
        return l;

    root->extend(l, r);
    if ((root->left)->sum >= k)
        return query(k, root->left, l, (l+r)/2);
    return query(k - ((root->left)->sum), root->right, (l+r)/2+1, r);
}

int main()
{
    int n, m, num;
    char op;

    scanf("%d%d", &n, &m);

    Root = new node(1, n);

    for (int i = 1; i <= m; i++) {
        scanf(" %c %d", &op, &num);
        int q = query(num, Root, 1, n);
        if (op == 'L')
            printf("%d\n", q);
        else
            updateSegTree(q, -1, Root, 1, n);
    }
    return 0;
}