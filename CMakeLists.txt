cmake_minimum_required(VERSION 2.8)

PROJECT(davinci_tool_track LANGUAGES CXX)

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")

# Find OpenCV

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(VTK 6.0 REQUIRED)
# find_package(Qt5Widgets REQUIRED)

find_package(Qt5 COMPONENTS Core Gui Widgets PrintSupport)

find_package(catkin REQUIRED)



set(Eigen3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
  set(Eigen3_DEP Eigen3)

add_definitions(${EIGEN_DEFINITIONS})

# Instruct CMake to run moc automatically when needed.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)

add_definitions( -std=c++11 -fPIC)

#include(${VTK_USE_FILE})

include_directories(
  include
  ${Eigen3_INCLUDE_DIRS}
  ${QT_USE_FILE}
  ${OpenCV_INCLUDE_DIRS}
  ${VTK_INCLUDE_DIRS}
)

catkin_package()


SET( CXX_FILES
	src/camera.cpp
	src/GraphicalUserInterface.cpp
	src/main.cpp
	src/mouse_interactor_style.cpp
	src/reader_camera.cpp
	src/reader_robot.cpp
	src/simulator.cpp
	src/stereo_base.cpp
	src/BasicStructs.cpp
	src/QGODetector.cpp
	src/QuantisedGradOrientation.cpp
	src/ShapeContextPro.cpp
	src/ExtendedKalmanFilter.cpp
	src/CameraProcessor.cpp
	src/psm_tool.cpp
)
SET( QT_WRAP
	include/camera.h
	include/GraphicalUserInterface.h
	include/mouse_interactor_style.h
	include/reader_camera.h
	include/reader_robot.h
	include/simulator.h
	include/stereo_base.h
	include/BasicStructs.h
	include/QGODetector.h
	include/QuantisedGradOrientation.h
	include/ShapeContextPro.h
	include/ExtendedKalmanFilter.h
	include/CameraProcessor.h
	include/psm_tool.h
)

qt5_wrap_ui(UI_HEADERS ${UI_FILES} )
qt5_wrap_cpp(qt_wrap_h ${QT_WRAP})
add_library(configwin ${tst_form_hdr})
qt5_use_modules(configwin Widgets)
# CMAKE_AUTOMOC in ON so the MocHdrs will be automatically wrapped.
add_executable(daVinciToolTrack ${CXX_FILES} ${UI_HEADERS} ${qt_wrap_h})

qt5_use_modules(daVinciToolTrack Core Gui Widgets)

target_link_libraries(daVinciToolTrack ${VTK_LIBRARIES} ${OpenCV_LIBS})

