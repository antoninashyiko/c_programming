#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_size 100

size_t input_arrayelements( int* array ) {
    int i=0;
    while ( i < max_size ) {
        printf( "enter element %zu (0 to stop): ", i + 1 );
        if ( scanf("%d", &array[i]) != 1 ) {
            return 0;
        }
        if ( array[i] == 0 ) {
            break;
        }
        i++;
    }
    return i;
}

void write_arrayelements( const int* array, size_t count ) {
    for ( size_t i = 0; i < count; i++ ) {
        printf( "elememt %zu: %d\n", i+1, array[i] );
    }
}

size_t write_arrayelements_tofile( const int* array, size_t count, const char* filename ) {
    FILE* file = fopen( filename, "wt" );
    if ( file == NULL ) {
        return 0;
    }
    for ( size_t i = 0; i < count; i++ ) {
        size_t written = fprintf ( file, "%d ", array[i] );
        if ( written < 0 ) {
            fclose( file );
            return i;
        }
    }
    fclose( file );
    return count;
}

size_t read_arrayelements_fromfile( int* array, size_t size, const char* filename ) {
    FILE* file = fopen( filename, "rt" );
    if ( file == NULL ) {
        return 0;
    }

    size_t count = 0;
    while ( count < size && fscanf( file, "%d", &array[count] ) == 1 ) {
        printf( "%d ", array[count] );
        count++;
    }
    fclose( file );
    return count;
}

bool check_three_divisors( int n ) {
    if ( n<=3 ) {
        return false;
    }
    int k = 0;
    for ( int i = 1; i <= n ; i++ ) {
        if ( n % i == 0 ) {
            k++;
        }
    }
    return k==3;
}

size_t select_num_with_three_divisors( int* array, size_t n, const char* input_file, const char* output_file ) {
    FILE* infile = fopen( input_file, "rt" );
    if ( infile == NULL ) {
        return 0;
    }
    FILE *outfile = fopen( output_file, "wt" );
    if ( outfile == NULL ) {
        fclose( infile );
        return 0;
    }

    size_t selected_count = 0;
    for ( size_t i = 0; i < n; i++ ) {
        if ( check_three_divisors( array[i] ) && fprintf( outfile, "%d ", array[i] ) < 0 ) {
            fclose( infile );
            fclose( outfile );
            selected_count++;
            return 0;
        }
    }
    fclose( infile );
    fclose( outfile );
    return selected_count;
}

int main() {
    int array[max_size];
    size_t count = input_arrayelements( array );
    if ( count == 0 ) {
        printf( "error reading array\n" );
        return 1;
    }

    write_arrayelements( array, count );
    write_arrayelements_tofile( array, count, "input_task3.txt" );

    printf( "elements with three divisors: ");
    select_num_with_three_divisors( array, count, "input_task3.txt", "output_task3.txt" );
    read_arrayelements_fromfile( array, count, "output_task3.txt" );

    return 0;
}