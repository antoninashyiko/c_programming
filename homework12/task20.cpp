#include <iostream>
#include <fstream>

using namespace std;
double mass_power ( const double* array ) {
    return array[2]*(array[0]+array[1]);
}

int main ( ) {
    unsigned n;
    cout << "enter number of points: ";
    cin >> n;
    int** l = new int*[n];
    for (unsigned i = 0; i < n; i++) {
        l[i] = new int[3];
    }
    for (unsigned i = 0; i < n; i++) {
        cout << "l[" << i << "] (enter x, y, m): ";
        cin >> l[i][0] >> l[i][1] >> l[i][2];
    }

    const char* file  = "task20.txt";

    fstream f;
    f.open (file, ios::out);
    if ( !f.is_open () ) {
        cout << "Error opening file!" << endl;
        for (unsigned i = 0; i < n; i++) delete[] l[i];
        delete [] l;
        f.close();
        return -1;
    }
    for ( unsigned i = 0; i < n; i++ ) {
        f << l[i][0] << " " << l[i][1]<< " " << l[i][2] << "\n";
    }
    f.close();

    f.open (file, ios::in);
    if ( !f.is_open() ) {
        cerr << "Error reading opening file!" << endl;
        for (unsigned i = 0; i < n; i++) delete[] l[i];
        delete[] l;
        f.close();
        return -1;
    }
    double max = -1e9;
    int index = -1;
    for ( unsigned i = 0; i < n; i++ ) {
        double x, y, m;
        if (!(f >> x >> y >> m)) {
            for (unsigned i = 0; i < n; i++) delete[] l[i];
            delete[] l;
            cerr << "error reading file!" << endl;
            return -2;
        }
        double list[3] = {x, y, m};
        double power = mass_power ( list );
        if (power > max) {
            max = power;
            index = i;
        }
    }
    if ( index != -1 ) {
        cout << "point with max level of power: " << l[index][0] << " " << l[index][1] << " " << l[index][2] << endl;
        cout << "result: " << max << endl;
    }
}