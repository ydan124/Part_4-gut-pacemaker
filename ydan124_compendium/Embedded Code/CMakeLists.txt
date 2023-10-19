cmake_minimum_required(VERSION 3.25)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c artifact_detect.c artifact_detect.h moving_average_1s_window.c moving_average_1s_window.h NEO_transform.c NEO_transform.h artifact_remove.c artifact_remove.h ppval.c ppval.h lowpass_function.h lowpass_function.c highpass_function.c highpass_function.h py_c_run.c py_c_run.h )
add_library(mylib SHARED
        main.c
        artifact_detect.c
        moving_average_1s_window.c
        NEO_transform.c
        artifact_remove.c
        ppval.c
        lowpass_function.c
        highpass_function.c
        py_c_run.c
        )
