add_library(forge-core
        src/Forge.cpp
)

target_include_directories(forge-core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)