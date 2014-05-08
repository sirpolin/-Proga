#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <time.h>
#include <stdlib.h>

using namespace std;

template <class T>
void array_copy(T*& arr, const T* data, int size) {
    arr = new T [size];
    for (int i = 0; i < size; ++i)
        arr[i] = data[i];
}
template <class T>
void vector_copy(vector <T> & v, const T* data, int size) {
    v.reserve(size);
    for (int i = 0; i < size; ++i)
        v.push_back(data[i]);
}
template <class T>
void list_copy(list <T> & l, const T* data, int size) {
    for (int i = 0; i < size; ++i)
        l.push_back(data[i]);
}
template <class T, class TT>
void stack_copy(stack <T, TT> & l, const T* data, int size) {
    for (int i = 0; i < size; ++i)
        l.push(data[i]);
}
const int big_size = 10000000;

int main() {
    int * data = new int [big_size];
    for (int i = 0; i < big_size; ++i) {
        data[i] = rand();
    }
    int * arr = nullptr;
    vector <int> v;
    list <int> l;
    stack <int> stack1;
    stack <int, list <int> > stack2;
    clock_t t;

    t = clock();
    array_copy(arr, data, big_size);
    t = clock() - t;
    cout << "array: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;

    t = clock();
    vector_copy(v, data, big_size);
    t = clock() - t;
    cout << "vector: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;

    t = clock();
    list_copy(l, data, big_size);
    t = clock() - t;
    cout << "list: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;

    t = clock();
    stack_copy(stack1, data, big_size);
    t = clock() - t;
    cout << "stack: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;

    t = clock();
    stack_copy(stack2, data, big_size);
    t = clock() - t;
    cout << "stack_list: " << t << " clocks and " << (double) t / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
