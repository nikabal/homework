#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i >= 1) {
            if (i % 2) {
                if (a[i] < a[i - 1]) {
                    swap(a[i - 1], a[i]);
                }
            }
            else {
                if (a[i] > a[i - 1]) {
                    swap(a[i - 1], a[i]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}