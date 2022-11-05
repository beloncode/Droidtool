cmake_minimum_required(VERSION 3.23)
project(Droidtool)

# Using by default, C++ 20 version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ASM_STANDARD_REQUIRED True)
add_executable(droidtool)
target_sources(droidtool PRIVATE Main_Thread.cpp Event/Event_Manager.cpp Event/Event_Ctrl.h)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# Installing droidtool inside Runtime directory and all others components
install(TARGETS droidtool CONFIGURATIONS Debug RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/Runtime)

