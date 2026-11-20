add_executable(lab18_task1 task1.cpp
        ../lab15/Ratio.cpp)
add_executable(lab18_task2 task2.cpp)

target_include_directories(lab18_task1 PRIVATE ../lab15)