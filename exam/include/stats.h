//
// Created by Chocolate Chip on 24.11.2026.
//

#ifndef LAB_PROJECTS_2026_2027_STATS_H
#define LAB_PROJECTS_2026_2027_STATS_H
#include <string>

typedef struct Record {
    std::string name;
    double score;
} Record;

typedef struct Stats {
    double average;
    double median;
} Stats;

extern Stats analyze( const Record* record, size_t n);

#endif //LAB_PROJECTS_2026_2027_STATS_H
