#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
vector< vector <int> > input_matrix( int n, int m ) {

    vector< vector <int> > matrix;

    for ( int i = 0; i < n; i++ ) {

        vector< int > lst;
        string line;
        getline(cin, line);
        stringstream ss( line );
        int tmp;
        while ( ss >> tmp ) {
            lst.push_back( tmp );
        }
        if ( lst.size() != m ) {
            cerr << "error parsing " << line << endl;
        }
        matrix.push_back(lst);
    }
    return matrix;
}

int max_space( vector< vector <int> > matrix ) {
    int rows = matrix.size();
    int cols = 0;
    if (rows > 0) {
        cols = matrix[0].size();
    }
    vector< vector<int> > matrix_of_visited(rows, vector<int>(cols, 0));
    int max = 0;
    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < cols; j++ ) {
            if ( matrix_of_visited[i][j] == 0 ) {

                matrix_of_visited[i][j] = 1;
                stack< pair<int, int> > st;
                st.push( make_pair( i, j ) );
                int k = 0;
                int target_val = matrix[i][j];
                while ( !st.empty() ) {
                    pair<int, int> current = st.top();
                    st.pop();
                    k++;
                    int x = current.first;
                    int y = current.second;
                    pair<int, int> top = make_pair(x - 1, y);
                    pair<int, int> bottom = make_pair(x + 1, y);
                    pair<int, int> left = make_pair(x, y - 1);
                    pair<int, int> right = make_pair(x, y + 1);

                    pair<int, int> neighbours[4] = {top, bottom, left, right};
                    for ( int d = 0; d < 4; d++ ) {
                        int one = neighbours[d].first;
                        int two = neighbours[d].second;
                        if ( one >= 0 && one < rows && two >= 0 && two < cols ) {
                            if ( matrix_of_visited[one][two] == 0 && matrix[one][two] == target_val ) {
                                matrix_of_visited[one][two] = 1;
                                st.push( neighbours[d] );
                            }
                        }
                    }
                }
                if ( k > max ) {
                    max = k;
                }

            }
        }
    }
    return max;
}

int main() {
    int n, m;
    cout << "enter nxm: ";
    cin >> n >> m;
    string str;
    getline(cin, str);

    vector< vector<int> > matrix = input_matrix(n, m);
    cout << max_space(matrix) << endl;

    return 0;
}