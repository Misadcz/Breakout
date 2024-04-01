cmake_minimum_required(VERSION 3.4)


project(breakout)

find_package(SDL2)
find_package(SDL2TTF)
find_package(SDL2IMAGE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

#set(breakout main.c)

add_executable(breakout main.c breakout.c ttf.c brick.c)

target_include_directories(breakout PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

target_link_libraries(breakout ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})
