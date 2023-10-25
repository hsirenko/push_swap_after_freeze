cmake_minimum_required(VERSION 3.26)
project(ps C)

set(CMAKE_C_STANDARD 99)

# Add a target to build libft.a in the libft directory
libft:
$(MAKE) -C libft

# Your existing target to build the main project
ps: libft
$(CC) $(CFLAGS) -o $@ push_swap.c -Ilibft -Llibft -lft


add_executable(ps
        push_swap.h
        push_swap.c
        )

# Include directories for header files

target_include_directories(ps PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/printf
        ${CMAKE_CURRENT_SOURCE_DIR}/libft)


# Links project with the existing libft.a library
add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a)

# Links project with the existing libft.a library
add_library(printf STATIC IMPORTED)
set_target_properties(printf PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/printf/libftprintf.a)

target_link_libraries(ps PRIVATE
        libft
        printf)


