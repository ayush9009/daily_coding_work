#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(int dist, int arr[], int n, int cows)
{
    int co_ord = arr[0], cnt = 1; // yani first cow plce hogyi
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - co_ord >= dist)
        {
            cnt++;
            co_ord = arr[i]; // yani agli cow place ho chuki
        }
        if (cnt == cows)
            return true; // yani saricows place hogyi
    }
    return false; // means u r not able to placed cows
}
int largestMinimumDistance(int arr[], int n, int cows)
{
    int res;
    int low = 1, high = arr[n - 1] - arr[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (canPlaceCows(mid, arr, n, cows))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cows;
        cin >> cows;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << largestMinimumDistance(arr, n, cows);
    }
    return 0
}
