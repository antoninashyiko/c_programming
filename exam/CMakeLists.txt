add_executable(main
        main.cpp
        src/stats.cpp
        include/stats.h
)
target_include_directories(main PRIVATE include)