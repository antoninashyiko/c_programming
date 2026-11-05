#include <stdio.h>
#include <stdlib.h>

size_t input_arrayelements( double* array, size_t max_size ) {
    size_t count;
    printf( "enter the number of elements in the array (max %zu) \n", max_size );
    if ( scanf("%zu", &count) != 1 || count > max_size ) {
        return 0;
    }
    for ( size_t i = 0; i < count; i++ ) {
        printf( "enter element %zu: ", i + 1 );
        if ( scanf("%lf", &array[i]) != 1 ) {
            return 0;
        }
    }
    return count;
}

void write_arrayelements( const double* array, size_t count ) {
    for ( size_t i = 0; i < count; i++ ) {
        printf( "elememt %zu: %lf\n", i+1, array[i] );
    }
}

size_t write_arrayelements_tofile( const double* array, size_t count, const char* filename ) {
    FILE* file = fopen( filename, "wt" );
    if ( file == NULL ) {
        return 0;
    }
    for ( size_t i = 0; i < count; i++ ) {
        size_t written = fprintf ( file, "%lf ", array[i] );
        if ( written < 0 ) {
            fclose( file );
            return i;
        }
    }
    fclose( file );
    return count;
}

size_t read_arrayelements_fromfile( double* array, size_t max_size, const char* filename ) {
    FILE* file = fopen( filename, "rt" );
    if ( file == NULL ) {
        return 0;
    }

    size_t count = 0;
    while ( count < max_size && fscanf( file, "%lf", &array[count] ) == 1 ) {
        printf( "%lf, ", array[count] );
        count++;
    }
    fclose( file );
    return count;
}


int main() {
    const size_t max_size = 100;
    double array[max_size];
    size_t count = input_arrayelements( array, max_size );
    if ( count == 0 ) {
        printf( "error reading array\n" );
        return 1;
    }

    write_arrayelements( array, count );
    write_arrayelements_tofile( array, count, "output_task1.txt" );
    read_arrayelements_fromfile( array, max_size, "output_task1.txt" );
}