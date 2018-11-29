cmake_minimum_required(VERSION 3.12)
project(LUMD C)

set(CMAKE_C_STANDARD 99)

# LUMD
set(LUMD_SRC_DIR src)
set(LUMD_INC_DIR include)
file(GLOB_RECURSE LUMD_SRCS "${LUMD_SRC_DIR}/*.c")
file(GLOB_RECURSE LUMD_HDRS "${LUMD_INC_DIR}/*.h")
add_executable(LUDM
	${LUMD_SRCS}
	${LUMD_HDRS}
	)
target_include_directories(LUDM PUBLIC
	${LUMD_INC_DIR}
	)