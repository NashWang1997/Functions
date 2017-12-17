#include <iostream>
using namespace std;

int binarySearch (int data[], int length, int x)
{
    int low = 0, high = length + 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x == data[mid]) return mid;
        if (x < data[mid]) high = mid - 1; else low = mid + 1;
    }
    return -1;
}

void test ()
{
    int data[] = {1, 3, 4, 6, 7, 10, 16, 25, 30, 100};
    cout << binarySearch(data, 10, 100) << endl;
    cout << binarySearch(data, 10, 2) << endl;
}

int main()
{
    test();
    return 0;
}
