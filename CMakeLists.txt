cmake_minimum_required(VERSION 3.22)
project(ProjectileIndicator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Official Android native-mod SDK used by LeviLaunchroid.
FetchContent_Declare(
    preloader_android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG 0.2.3
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(preloader_android)

add_library(projectile_indicator SHARED
    src/ProjectileIndicator.cpp
)

target_link_libraries(projectile_indicator PRIVATE preloader)
target_compile_options(projectile_indicator PRIVATE -Wall -Wextra -Wpedantic)

set_target_properties(projectile_indicator PROPERTIES
    OUTPUT_NAME "projectile_indicator"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
)
