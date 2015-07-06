cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#####
SET(GCC_COVERAGE_LINK_FLAGS    "-lm")
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
INCLUDE_DIRECTORIES(/usr/include/libxml2/)
#INCLUDE_DIRECTORIES(/usr/local/include/)
#LINK_DIRECTORIES(/usr/local/lib/)
#####

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})
rosbuild_add_library(Particle src/Particle.cpp)
rosbuild_add_library(Particles src/Particles.cpp)
rosbuild_add_library(System src/System.cpp)
rosbuild_add_library(Sensor src/Sensor.cpp)
rosbuild_add_library(Distribution src/Distribution.cpp)
rosbuild_add_library(Simulator src/Simulator.cpp)
rosbuild_add_library(Example_system src/example_system.cpp)
rosbuild_add_library(Example_sensor src/example_sensor.cpp)
rosbuild_add_library(Example_distribution src/example_distribution.cpp)
target_link_libraries(Simulator Particle Particles System Sensor Distribution)
rosbuild_add_executable(m src/main.cpp)
target_link_libraries(m Particles mlpack Simulator Example_system Example_sensor)
rosbuild_add_executable(d src/driver.cpp)
target_link_libraries(d Particles mlpack Simulator Example_system Example_sensor Example_distribution)
