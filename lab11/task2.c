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

size_t write_arrayelements_tobinaryfile( const double* array, size_t count, const char* filename ) {
    FILE* file = fopen( filename, "wb" );
    if ( file == NULL ) {
        return 0;
    }
    size_t written = fwrite ( array, sizeof( double ), count, file );
    fclose( file );
    return written;
}

size_t read_arrayelements_from_binaryfile( double* array, size_t max_size, const char* filename ) {
    FILE* file = fopen( filename, "rb" );
    if ( file == NULL ) {
        return 0;
    }

    size_t count = 0;
    while ( count < max_size && !feof( file ) ) {
        size_t read = fread( &array[count], sizeof( double ), 1, file );
        if ( read != 1 ) {
            break;
        }
        if ( count == 0 ) {
            printf( "%g", array[count] );
        } else {
            printf( ", %g", array[count] );
        }
        count++;
    }
    fclose( file );
    return count;
}

int select_greater_than( const double* array, size_t count, double threshold, const char* input_file, const char* output_file ) {
    FILE* infile = fopen( input_file, "rb" );
    if ( infile == NULL ) {
        return 0;
    }
    FILE *outfile = fopen( output_file, "wb" );
    if ( outfile == NULL ) {
        fclose( infile );
        return 0;
    }

    size_t selected_count = 0;
    for ( size_t i = 0; i < count; i++ ) {
        if ( array[i] > threshold ) {
            if ( fwrite(&array[i], sizeof( double ), 1, outfile ) != 1 ) {
                fclose( infile );
                fclose( outfile );
                return 0;
            }
            selected_count++;
        }
    }
    fclose( infile );
    fclose( outfile );
    return selected_count;
}

int main() {
    const size_t max_size = 100;
    double array[max_size];
    size_t count = input_arrayelements( array, max_size );
    if ( count == 0 ) {
        printf( "error reading array\n" );
        return 1;
    }
    double a;
    printf( "enter a number: " );
    scanf( "%lf", &a );

    write_arrayelements( array, count );
    write_arrayelements_tobinaryfile( array, count, "input_task2.bin" );
    select_greater_than( array, count, a, "input_task2.bin", "output_task2.bin" );
    read_arrayelements_from_binaryfile( array, count, "output_task2.bin" );
}