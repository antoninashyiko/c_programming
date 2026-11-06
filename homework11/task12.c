#include <stdio.h>
#include <stdbool.h>

typedef struct Toy {
    char name[50];
    double price;
    int min_age;
    int max_age;
} Toy;

void print_toy( const Toy* toy ) {
    printf( "toy name: %s\n", toy->name );
    printf( "toy price: %.2f\n", toy->price );
    printf( "toy age range: %d to %d\n", toy->min_age, toy->max_age );
    printf( "------\n" );
}
bool input_toy (Toy* toy) {
    if ( toy == NULL ) {
        return false;
    }
    printf( "input toy name: " );
    if ( scanf("%s", &toy->name ) != 1 ) {
        return false;
    }
    printf( "input toy price: " );
    if ( scanf("%lf", &toy->price ) != 1 ) {
        return false;
    }
    printf( "input toy min age: " );
    if ( scanf("%d", &toy->min_age ) != 1 ) {
        return false;
    }
    printf( "input toy max age: " );
    if ( scanf("%d", &toy->max_age ) != 1 ) {
        return false;
    }
    printf( "---------\n" );
    return true;
}
bool write_toy_file( const char* filename ) {
    FILE* file = fopen( filename, "wb" );
    if ( file == NULL ) {
        return false;
    }

    int n;
    printf( "enter number of toys: ");
    if ( scanf( "%d", &n ) != 1 || n <= 0 ) {
        fclose( file );
        return false;
    }

    for ( int i = 0; i < n; i++ ) {
        Toy toy;
        if ( input_toy( &toy ) ) {
            fwrite( &toy, sizeof(Toy), 1, file );
        } else {
            i--;
        }
    }
    fclose( file );
    return true;
}

bool max_price (  const char* filename, const char* outfilename, Toy* max_price_toy ) {
    FILE* file = fopen( filename, "rb" );
    if ( file == NULL ) {
        return false;
    }
    FILE *outfile = fopen( outfilename, "wb" );
    if ( outfile == NULL ) {
        fclose( file );
    }

    Toy toy;
    double max_price = -1.0;
    while ( fread(&toy, sizeof(toy), 1, file ) == 1 ) {
        if ( toy.price > max_price ) {
            max_price = toy.price;
            *max_price_toy = toy;
        }
    }
    fwrite( max_price_toy, sizeof(Toy), 1, outfile );
    print_toy(max_price_toy);

    fclose( outfile );
    fclose( file );
    return true;
}
void print_toy_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return;
    }
    Toy toy;
    while (fread(&toy, sizeof(toy), 1, file) == 1) {
        print_toy(&toy);
    }
    fclose(file);
}

int main () {
    const char* filename = "toys.bin";
    if ( !write_toy_file( filename ) ) {
        return 1;
    }
    printf( "your file:\n");
    print_toy_file( filename );
    printf( "\n");

    Toy max_price_toy;
    printf( "toy with max price is: \n");
    if (!max_price( "toys.bin", "output_toy.bin", &max_price_toy )) {
        printf("Could not find any toys or open the file.\n");
    }

    return 0;
}