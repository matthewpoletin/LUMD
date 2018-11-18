cmake_minimum_required(VERSION 3.12)
project(LUDM C)

set(CMAKE_C_STANDARD 99)

set(SRCS
	src/main.c
	src/matrix.c
	src/matrix.h
	)
add_executable(LUDM
	${SRCS}
	)