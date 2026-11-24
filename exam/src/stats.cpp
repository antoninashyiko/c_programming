#include "stats.h"
#include <algorithm>
#include <stdexcept>

Stats analyze( const Record* record, size_t n) {
    if ( record == nullptr || n < 1 || n > 50) {
        throw std::invalid_argument( "error: incorrect number of records or record error" );
    }

    double sum = 0;
    double median = 0;

    double scores[50];

    for ( size_t i = 0; i < n; i++ ) {
        sum += record[i].score;
        scores[i] = record[i].score;
    }

    double average = sum / static_cast<double>(n);

    std::sort( scores, scores + n );
    if ( n%2 == 1 ) {
        median = scores[n/2];
    }
    else if ( n%2 == 0 ) {
        median = (scores[n/2-1] + scores[n/2])/2.0;
    }

    Stats stats;
    stats.median = median;
    stats.average = average;
    return stats;
}