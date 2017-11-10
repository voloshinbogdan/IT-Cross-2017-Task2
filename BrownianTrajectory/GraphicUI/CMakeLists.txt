cmake_minimum_required(VERSION 2.8.11)

project(GraphicUI)

find_package(Qt5Widgets)

add_executable(GraphicUI main.cpp main-window.cpp main-window.h)

target_link_libraries(GraphicUI Qt5::Widgets)
target_link_libraries(GraphicUI BrownianTrajectoryLib)
