cmake_minimum_required(VERSION 2.8)

project(BrownianTrajectoryLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(BrownianTrajectoryLib BrownianTrajectoryLib.cpp BrownianTrajectoryLib.h)

get_property(LIB_TYPE TARGET BrownianTrajectoryLib PROPERTY TYPE)

if(LIB_TYPE STREQUAL SHARED_LIBRARY)
	install(
		TARGETS BrownianTrajectoryLib
		COMPONENT user
		RUNTIME
			DESTINATION bin
		LIBRARY
			DESTINATION lib)
endif()

install(
	TARGETS BrownianTrajectoryLib
	COMPONENT developer
	RUNTIME
		DESTINATION bin
	LIBRARY
		DESTINATION lib
	ARCHIVE
		DESTINATION lib)

install(
	DIRECTORY .
	DESTINATION include
	COMPONENT developer
	FILES_MATCHING
		PATTERN "*.h")

target_include_directories(BrownianTrajectoryLib INTERFACE)
