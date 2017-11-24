cmake_minimum_required(VERSION 2.8.11)

project(GraphicUI)

find_package(Qt5Widgets)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(UIC_WRAPPERS data_pane.ui about.ui)

add_executable(
	GraphicUI
	main.cpp
	main-window.cpp
	main-window.h
	${UIC_WRAPPERS})

find_path(
	BROWNIANTRAJECTORY_H_DIR BrownianTrajectoryLib.h
	PATHS ../BrownianTrajectoryLib)
if(NOT BROWNIANTRAJECTORY_H_DIR)
	message(
		SEND_ERROR
		"Could not find BrownianTrajectoryLib.h")
endif()
set_property(
	TARGET BrownianTrajectoryLib
	PROPERTY INTERFACE_INCLUDE_DIRECTORIES
	${BROWNIANTRAJECTORY_H_DIR})
set_property(
	TARGET BrownianTrajectoryLib
	PROPERTY IMPORTED_LOCATION
	${BROWNIANTRAJECTORY_LIB})

target_link_libraries(GraphicUI Qt5::Widgets)
target_link_libraries(GraphicUI BrownianTrajectoryLib)
