cmake_minimum_required(VERSION 3.16.0)
project(traffic-lights VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
  cmocka
  GIT_REPOSITORY https://git.cryptomilk.org/projects/cmocka.git
  GIT_TAG        cmocka-1.1.5
  GIT_SHALLOW    1
)

set(WITH_STATIC_LIB ON CACHE BOOL "CMocka: Build with a static library" FORCE)
set(WITH_CMOCKERY_SUPPORT OFF CACHE BOOL "CMocka: Install a cmockery header" FORCE)
set(WITH_EXAMPLES OFF CACHE BOOL "CMocka: Build examples" FORCE)
set(UNIT_TESTING OFF CACHE BOOL "CMocka: Build with unit testing" FORCE)
set(PICKY_DEVELOPER OFF CACHE BOOL "CMocka: Build with picky developer flags" FORCE)
set(CMOCKA_PLATFORM_INCLUDE CACHE PATH "Path to include directory for cmocka_platform.h" FORCE)
# set(HAVE_SIGNAL_H "0")
FetchContent_MakeAvailable(cmocka)

include_directories(include)
include_directories(include_cmocka)

enable_testing()

add_executable(traffic_lights_test src/traffic_junction.c test/general.c)
target_link_libraries(traffic_lights_test PUBLIC cmocka)
add_test(NAME traffic_lights_test COMMAND traffic_lights_test)


add_executable(traffic_lights src/traffic_junction.c main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
