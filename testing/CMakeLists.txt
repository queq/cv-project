cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} [.])
# set(OPENCV_DIR ${OPENCV_DIR} [/home/kaksoispiste/Code/opencv-3.1.0])
project("Project")

# SET(CMAKE_CXX_FLAGS "-std=c++0x -fpermissive -Wno-deprecated -Wno-sign-compare")
# SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall")
# SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
# SET(CMAKE_CXX_LINK_FLAGS_DEBUG "-pg")

find_package(OpenCV 3 REQUIRED)
find_package(libfreenect REQUIRED)
find_package(PCL 1.3 REQUIRED)

include_directories("/usr/include/libusb-1.0/")
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# add_executable(main pcl_visualizer_demo.cpp)
add_executable(main openni_viewer_simple.cpp)
# add_executable(main openni_viewer_benchmark.cpp)
# add_executable(main profile_cpu.cpp)

target_link_libraries(main ${OpenCV_LIBS}
                           ${CMAKE_THREAD_LIBS_INIT}
                           ${FREENECT_LIBRARIES}
                           ${PCL_LIBRARIES})
