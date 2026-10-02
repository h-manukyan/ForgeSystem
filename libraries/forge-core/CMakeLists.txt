add_library(forge_core src/version.cpp)
add_library(forge::core ALIAS forge_core)

target_include_directories(forge_core PUBLIC include)
target_compile_features(forge_core PUBLIC cxx_std_23)
target_compile_options(forge_core PRIVATE -Wall -Wextra -Wpedantic)

add_executable(forge_core_tests tests/version_test.cpp)
target_link_libraries(forge_core_tests PRIVATE forge::core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(forge_core_tests)
