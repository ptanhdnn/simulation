#-------------------------------------------------------------
#Set up the project

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Simulation)

#-------------------------------------------------------------
#Find Geant4 package, activating all available UI and Vis drivers by default

find_package(Geant4 REQUIRED ui_all vis_all)

#Or 
#option (WITH_GEANT4_UIVIS "build example with Geant4 UI and Vis drivers" ON)
#if (WITH_GEANT4_UIVIS)
#	find_package(Geant4 REQUIRED ui_all vis_all)
#else()
#	find_package(Geant4 REQUIRED)
#endif()

#-------------------------------------------------------------
#set up g4 include directories and compile definitions
#setup include directory for this project

include(${Geant4_USE_FILE})
#include_directories(${PROJECT_SOURCE_DIR}/include)

#-------------------------------------------------------------
#locate sources and headers for this project

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

file(GLOB MACRO_FILES "*.mac")

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

#-------------------------------------------------------------
#Add executable and link it to the g4 libraries

add_executable(simulation simulation.cc ${sources} ${headers})
target_link_libraries(simulation ${Geant4_LIBRARIES})

#add_custom_target(Simulation DEPENDS simulation)
