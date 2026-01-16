cmake_minimum_required(VERSION 3.16)
project(cubetimer LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(cubetimer
  main.c
  scramble_gen.c
)

target_include_directories(cubetimer PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)


