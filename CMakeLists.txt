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
        VirtualMachine/src/parsing/parse_bot_id.c)

add_library(libft STATIC IMPORTED)
set_property(TARGET libft PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(Corewar libft)