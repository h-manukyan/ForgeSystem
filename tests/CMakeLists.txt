add_executable(forge-tests
    resource_tests.cpp
)

target_link_libraries(forge-tests
    PRIVATE
    forge-core
)

add_test(NAME forge-resource-tests COMMAND forge-tests)
