#include <bits/stdc++.h>
using namespace std;

long long maxCoins(vector<long long> a, vector<long long> b)
{
    long long N = a.size(), M = b.size();
    vector<long long> flag(2, 0);
    long long i = 0, j = 0;
    while (i < N && j < M)
    {
        if (a[i] < b[j])
            flag[0] += a[i++];
        else if (a[i] > b[j])
            flag[1] += b[j++];
        else
        {
            long long v = a[i], count_a = 0, count_b = 0;
            while (i < N && a[i] == v)
                count_a++, i++;
            while (j < M && b[j] == v)
                count_b++, j++;
            long long r0 = max(flag[0] + count_a * v, flag[1] + (count_a + count_b - 1) * v);
            long long r1 = max(flag[1] + count_b * v, flag[0] + (count_a + count_b - 1) * v);
            if (count_a > 1 && count_b > 1)
            {
                r0 = max(r0, flag[0] + (count_a + count_b - 2) * v);
                r1 = max(r1, flag[1] + (count_a + count_b - 2) * v);
            }
            flag[0] = r0;
            flag[1] = r1;
        }
    }
    while (i < N)
        flag[0] += a[i++];
    while (j < M)
        flag[1] += b[j++];
    return max(flag[0], flag[1]);
}

long long solve(vector<long long> &A, vector<long long> &B)
{
    long long n = A.size();
    long long m = B.size();
    long long ans = 0;
    long long i = 0, j = 0;
    bool flag = false;
    if (is_sorted(A.begin(), A.end()) && is_sorted(B.begin(), B.end()))
    {
        flag = true;
    }
    else
    {
        reverse(B.begin(), B.end());
        reverse(A.begin(), A.end());
    }

    return maxCoins(A, B);
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long m;
    cin >> m;
    vector<long long> b(m);
    for (long long i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    long long ans = 0;
    ans = solve(a, b);
    cout << ans << endl;

    return 0;
}