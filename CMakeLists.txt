cmake_minimum_required(VERSION 3.18.0)

######## CMocka Defs
include(FetchContent)
FetchContent_Declare(
        cmocka
        GIT_REPOSITORY https://git.cryptomilk.org/projects/cmocka.git
        GIT_TAG        cmocka-1.1.7
        GIT_SHALLOW    1
)

set(WITH_STATIC_LIB ON CACHE BOOL "CMocka: Build with a static library" FORCE)
set(WITH_CMOCKERY_SUPPORT OFF CACHE BOOL "CMocka: Install a cmockery header" FORCE)
set(WITH_EXAMPLES OFF CACHE BOOL "CMocka: Build examples" FORCE)
set(UNIT_TESTING OFF CACHE BOOL "CMocka: Build with unit testing" FORCE)
set(PICKY_DEVELOPER OFF CACHE BOOL "CMocka: Build with picky developer flags" FORCE)
set(CMOCKA_PLATFORM_INCLUDE CACHE PATH "Path to include directory for cmocka_platform.h" FORCE)

FetchContent_MakeAvailable(cmocka)

include_directories(include_cmocka)


######## Tests
enable_testing()

# TEST: Traffic Junction
add_cmocka_test(test_traffic_junction
                SOURCES test/test_traffic_junction.c src/application/traffic_junction.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES cmocka)

set_target_properties(test_traffic_junction PROPERTIES
        LINK_FLAGS ""
        COMPILE_DEFINITIONS "DEBUG")

target_sources(test_traffic_junction PRIVATE
               test/mocks/mock_led.c)

add_cmocka_test_environment(test_traffic_junction)
target_include_directories(test_traffic_junction
                           PUBLIC ${cmocka-header_SOURCE_DIR}
                            mocks
                            src/application
                            src/drivers)

######## Application
project(traffic-junction VERSION 0.1.0)
include_directories(src/application)
include_directories(src/drivers)

add_executable(traffic_junction
               main.c
               src/application/traffic_junction.c
               src/drivers/led.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)