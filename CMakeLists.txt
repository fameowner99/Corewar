cmake_minimum_required(VERSION 3.9)
project(Corewar)

set(CMAKE_CXX_STANDARD 11)

add_executable(Corewar

        VirtualMachine/src/main.c
        VirtualMachine/src/parsing/parsing.c
        VirtualMachine/src/parsing/manage_arguments.c
        VirtualMachine/src/manage_bot_list.c
        VirtualMachine/src/manage_pc_list.c
        VirtualMachine/src/parsing/parse_bot.c
        VirtualMachine/src/parsing/parse_bot_id.c
        VirtualMachine/src/parsing/get_bot_info.c
        VirtualMachine/src/display_map.c)

find_package(Curses REQUIRED)

target_link_libraries(Corewar ${CURSES_LIBRARIES})
include_directories(${CURSES_INCLUDE_DIR})
add_library(libft STATIC IMPORTED)
set_property(TARGET libft PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(Corewar libft)