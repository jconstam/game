cmake_minimum_required( VERSION 2.6 )

set( PROJECT_BASE Game )

project( ${PROJECT_BASE} )

set( CMAKE_VERBOSE_MAKEFILE OFF )

set( CMAKE_CXX_FLAGS "-std=c++11" )
	
set( SOURCES ${SOURCES} src/main/main.cpp )
set( SOURCES ${SOURCES} src/consoleEngine/consoleEngine.cpp )

include_directories( src/main )
include_directories( src/consoleEngine )

add_executable( ${PROJECT_BASE} ${SOURCES} )
target_link_libraries( ${PROJECT_BASE} zmq czmq protobuf pthread )
