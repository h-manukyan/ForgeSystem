cmake_minimum_required(VERSION 3.20)

project(ForgeSystem
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libraries/forge-core)

add_executable(forge
        apps/main.cpp
)

target_link_libraries(forge
        PRIVATE
        forge-core
)