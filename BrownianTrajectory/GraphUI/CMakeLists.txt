cmake_minimum_required(VERSION 2.8.11)

project(BrownianTrajectory)

find_package(Qt5Widgets)

add_executable(BrownianTrajectory main.cpp)

target_link_libraries(BrownianTrajectory Qt5::Widgets)
