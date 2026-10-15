add_executable(forge-tests
    resource_tests.cpp
)

target_link_libraries(forge-tests
    PRIVATE
    forge-core
)

add_test(NAME successful-consumption
        COMMAND forge-tests successful-consumption)

add_test(NAME insufficient-resource
        COMMAND forge-tests insufficient-resource)

add_test(NAME invalid-consumption
        COMMAND forge-tests invalid-consumption)

add_test(NAME add-resource
        COMMAND forge-tests add-resource)

add_test(NAME set-value
        COMMAND forge-tests set-value)

add_test(NAME overflow-test
        COMMAND forge-tests overflow-test)

add_test(NAME overflow-boundary
        COMMAND forge-tests overflow-boundary)
