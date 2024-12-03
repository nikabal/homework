#include <algorithm>
#include <iostream>
using namespace std;

bool ok(int mid, int *a, int x);

int main() {
    int a[6] = {1, 2, 3, 4, 7, 8};
    int r = sizeof(a) / sizeof(a[0]) - 1;  // Размер массива
    int l = 0;
    int ans = -1;  // Инициализируем ans значением по умолчанию
    int x = 6;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid, a, x)) {
            ans = mid;  // Сохраняем индекс, где условие выполнено
            l = mid + 1;  // Ищем в правой части
        } else {
            r = mid - 1;  // Ищем в левой части
        }
    }

    // Печатаем ответ
    if (ans != -1) {
        cout << "pos: " << ans << endl;
        cout << "value: " << a[ans] << endl;
    } else {
        cout << "Value not found." << endl;
    }

    return 0;
}

bool ok(int mid, int *a, int x) {
    return a[mid] <= x;  // Возвращаем true, если значение на индексе mid <= x
}
