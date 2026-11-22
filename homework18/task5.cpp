#include <iostream>

using namespace std;

template < typename T >
class Array {
    size_t size;
    T *data;
public:
    Array(size_t n) {
        size = n;
        data = new T[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = T();
        }
    }

    ~Array() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    T& at(size_t index) {
        return data[index];
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    static void sort_by_hash( T* arr, size_t n ) {
        if (arr == nullptr || n <= 1) {
            return;
        }
        T min_val = arr[0];
        T  max_val = arr[0];
        for (size_t i = 1; i < n; i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        size_t num_of_cells = n; // create cells, where elements will be put
        T** cells = new T*[num_of_cells];
        size_t* cell_sizes = new size_t[num_of_cells];

        for (size_t b = 0; b < num_of_cells; b++) {
            cells[b] = new T[n];
            cell_sizes[b] = 0;
        }

        for (size_t i = 0; i < n; i++) {
            size_t idx = 0;
            if (max_val != min_val && num_of_cells > 1) {
                double ratio = (double)(arr[i] - min_val) / (double)(max_val - min_val);
                idx = (size_t)(ratio * (double)(num_of_cells - 1));
                if (idx >= num_of_cells) {
                    idx = num_of_cells - 1;
                }
            }
            size_t cnt = cell_sizes[idx];
            cells[idx][cnt] = arr[i];
            cell_sizes[idx]++;
            for (size_t b = 0; b < num_of_cells; b++) {
                for (size_t a = 0; a < cell_sizes[b]; a++) {
                    for (size_t c = 0; c + 1 < cell_sizes[b] - a; c++) {
                        if (cells[b][c] > cells[b][c + 1]) {
                            T tmp = cells[b][c];
                            cells[b][c] = cells[b][c + 1];
                            cells[b][c + 1] = tmp;
                        }
                    }
                }
            }
        }

        size_t out_pos = 0; // put everything back for sorted cells
        for (size_t b = 0; b < num_of_cells; b++) {
            for (size_t j = 0; j < cell_sizes[b]; j++) {
                arr[out_pos] = cells[b][j];
                out_pos++;
            }
        }
        for (size_t b = 0; b < num_of_cells; b++) { // free memory
            delete[] cells[b];
        }
        delete[] cells;
        delete[] cell_sizes;
    }

    void sort_by_hash() {
        sort_by_hash(data, size);
    }
};

int main() {
    size_t n;
    cout << "enter n: ";
    cin >> n;

    Array<int> a(n);
    cout << "enter your array: \n ";
    for (size_t i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    cout << "your array: \n";
    a.print();

    a.sort_by_hash();

    cout << "sorted array by hash: \n";
    a.print();

    cout << endl;

}