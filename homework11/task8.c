#include <stdio.h>
#include <stdlib.h>

size_t input_arrayelements( int* array, size_t max_size ) {
    size_t count;
    printf( "enter the number of elements in the array (max %zu) \n", max_size );
    if ( scanf("%zu", &count) != 1 || count > max_size ) {
        return 0;
    }
    for ( size_t i = 0; i < count; i++ ) {
        printf( "enter element %zu: ", i + 1 );
        if ( scanf("%d", &array[i]) != 1 ) {
            return 0;
        }
    }
    return count;
}

void write_arrayelements( const int* array, size_t count ) {
    for ( size_t i = 0; i < count; i++ ) {
        printf( "elememt %zu: %d\n", i+1, array[i] );
    }
}

size_t write_arrayelements_tofile( const int* array, size_t count, const char* filename ) {
    FILE* file = fopen( filename, "wb" );
    if ( file == NULL ) {
        return 0;
    }
    size_t written = fwrite ( array, sizeof( int ), count, file );
    fclose( file );
    return written;
}

size_t read_arrayelements_fromfile( int* array, size_t max_size, const char* filename ) {
    FILE* file = fopen( filename, "rb" );
    if ( file == NULL ) {
        return 0;
    }

    size_t count = 0;
    while ( count < max_size ) {
        size_t read = fread( &array[count], sizeof( int ), 1, file );
        if ( read != 1 ) {
            break;
        }
        if ( count == 0 ) {
            printf( "%d", array[count] );
        } else {
            printf( ", %d", array[count] );
        }
        count++;
    }
    printf("\n");
    fclose( file );
    return count;
}

size_t max_from_nelement_tofile( const int* array, size_t count, int n, const char* infile, const char* outfile ) {
    FILE* input = fopen( infile, "rb" );
    if ( input == NULL ) {
        return 0;
    }
    FILE* output = fopen( outfile, "wb" );
    if ( output == NULL ) {
        return 0;
    }

    size_t groups = 0;

    for ( int i=0; i<count; i+=n ) {
        int current_max = array[i];
        for ( size_t j = 1; j < n && (i + j) < count; j++ ) {
            if ( array[i + j] > current_max ) {
                current_max = array[i + j];
            }
        }
        if ( fwrite( &current_max, sizeof( int ), 1, output ) != 1 ) {
            fclose( output );
            return groups;
        }
        groups++;
    }
    fclose( input );
    fclose( output );
    return groups;
}

int main() {
    int max_size=100;
    int array[max_size];
    size_t count = input_arrayelements( array, max_size );
    if ( count == 0 ) {
        printf( "error reading array\n" );
        return 1;
    }

    int n;
    printf("enter the size of group: " );
    scanf("%d", &n);

    write_arrayelements( array, count );
    write_arrayelements_tofile( array, count, "input_task8.txt" );

    printf("\nelements with max values from groups in file G: \n");
    max_from_nelement_tofile(array, count, n, "input_task8.txt", "output_task8.bin" );
    read_arrayelements_fromfile( array, count, "output_task8.bin" );

    return 0;
}