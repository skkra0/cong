project(Cong LANGUAGES C)

add_executable(Cong
               src/main.h
               src/main.c
               
               )

# Set the compiler and linker to include Raylib
target_include_directories(Cong PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(Cong PRIVATE ${raylib_LIBRARIES})