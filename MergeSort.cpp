#include <iostream>
using namespace std;

void Merge_LTH(int arr[], int reg[], int start, int END)
{
    if (start >= END) return;
    int len = END - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = END;
    Merge_LTH(arr, reg, start1, end1);
    Merge_LTH(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2){
        if (arr[start1] < arr[start2]) {
            reg[k] = arr[start1];
            k++; start1++;
        }
        else {
            reg[k] = arr[start2];
            k++; start2++;
        }
    }
    while (start1 <= end1) {
        reg[k] = arr[start1];
        k++; start1++;
    }
    while (start2 <= end2) {
        reg[k] = arr[start2];
        k++; start2++;
    }
    for (k = start; k <= END; k++) {
        arr[k] = reg[k];
    }
}

void MergeSort_LTH(int data[], int length)
{
    int reg[length];
    Merge_LTH(data, reg, 0, length - 1);
}

void test()
{
    int arr[] = {2, 13, 4, 6, 5, 10, 8, 1, 9, 6};
    MergeSort_LTH(arr, 10);
    for (int i=0; i<10; ++i) cout << arr[i] << ' ';
}
int main()
{
    test();
    return 0;
}
