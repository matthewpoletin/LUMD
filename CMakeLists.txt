cmake_minimum_required(VERSION 3.12)
project(LUMD C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# OPENMP
find_package(OpenMP REQUIRED)

# LUMD
set(LUMD_SRC_DIR src)
set(LUMD_INC_DIR include)
file(GLOB_RECURSE LUMD_SRCS "${LUMD_SRC_DIR}/*.c")
add_executable(LUMD
	${LUMD_SRCS}
	)
target_include_directories(LUMD PUBLIC
	${LUMD_INC_DIR}
	)
target_link_libraries(LUMD PRIVATE
	OpenMP::OpenMP_C
	)

# GOOGLE TEST
add_subdirectory(third_party/googletest)
set(GTEST_INC_DIR third_party/googletest/googletest/include)
file(GLOB_RECURSE TEST_SRCS "test/*.cpp" "test/*.c")
set(LUMD_TEST_SRCS ${LUMD_SRCS})
list(FILTER LUMD_TEST_SRCS EXCLUDE REGEX "main.c")
add_executable(LUMD_tests
	${LUMD_TEST_SRCS}
	${TEST_SRCS}
	)
target_include_directories(LUMD_tests PUBLIC
	${LUMD_INC_DIR}
	${GTEST_INC_DIR}
	)
target_link_libraries(LUMD_tests PUBLIC
	gtest
	gtest_main
	)