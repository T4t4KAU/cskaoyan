#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // 和左孩子比较
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // 和右孩子比较
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        // 对堆进行调整
        heapify(arr, n, i);
    }

    // 逐个将堆顶元素移到末尾
    for (int i = n - 1; i > 0; i--) {
        // 交换堆顶元素和最后一个元素
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void test_sort() {
    vector<int> A = {5, 9, 4, 3, 6, 3, 2};

    heap_sort(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
}

int main() {
    test_sort();

    return 0;
}
