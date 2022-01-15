cmake_minimum_required(VERSION 3.8)
set(PROJECT_NAME "lib_uuid_node")
set(LIBRARY_NAME "lib_uuid_node")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(${PROJECT_NAME})

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation rio_control_node uuid_msgs)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${LIBRARY_NAME}
  CATKIN_DEPENDS roscpp rio_control_node uuid_msgs
)

include_directories(
  include
 ${catkin_INCLUDE_DIRS}
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE executable_sources CONFIGURE_DEPENDS
     "${PROJECT_SOURCE_DIR}/src/*.cpp"
)


add_library(${LIBRARY_NAME} ${executable_sources})
target_include_directories(${LIBRARY_NAME} PUBLIC "include")
target_link_libraries(${LIBRARY_NAME} ${catkin_LIBRARIES} Threads::Threads)
add_dependencies(${LIBRARY_NAME} ${${LIBRARY_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Mark executables and/or libraries for installation
install(TARGETS ${LIBRARY_NAME}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)
# install(TARGETS standalone_converter
#    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
install(DIRECTORY include/${LIBRARY_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   #FILES_MATCHING PATTERN "*.h"
   #FILES_MATCHING PATTERN "*.hpp"
   PATTERN ".svn" EXCLUDE
)
