project(Cong LANGUAGES C)

add_executable(Cong
               src/main.h
               src/main.c
               src/pad.h
               src/pad.c
               src/ball.h
               src/ball.c
               )

target_include_directories(Cong PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(Cong PRIVATE ${raylib_LIBRARIES})
target_link_libraries(Cong PRIVATE m) # math
