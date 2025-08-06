
#include <bits/stdc++.h>
using namespace std;

#define MERGE 1
#define QUICK 2
#define RQUICK 3
#define HEAP 4
#define BUBBLE 5
#define SELECTION 6

#ifndef ALGO
#define ALGO MERGE
#endif

void generateRandomVector(vector<int> &arr, int n) {
    unsigned int seed = time(NULL);
    srand(seed);
    for (int i = 0; i < n; ++i)
        arr.push_back(rand() % 100000);

   
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size())
        arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    int pivotIdx = low + rand() % (high - low + 1);
    swap(arr[pivotIdx], arr[high]);
    return partition(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int mi = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[mi]) mi = j;
        swap(arr[i], arr[mi]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./main <number_of_elements>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    vector<int> arr;
    generateRandomVector(arr, n);
    // for loop use to display the random data to sort 
    // for(int i=0 ;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    #if ALGO == MERGE
        mergeSort(arr, 0, n - 1);
    #elif ALGO == QUICK
        quickSort(arr, 0, n - 1);
    #elif ALGO == RQUICK
        randomizedQuickSort(arr, 0, n - 1);
    #elif ALGO == HEAP
        heapSort(arr);
    #elif ALGO == BUBBLE
        bubbleSort(arr);
    #elif ALGO == SELECTION
        selectionSort(arr);
    #endif
    // to display the sorted data after sorting 
    // cout<<endl<<"BY DEFAULT USED MERGE SORT ALGO "<<endl;
    // for(int i=0 ;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}
