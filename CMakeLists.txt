cmake_minimum_required(VERSION 3.0.0)
project(markeerparser VERSION 0.1.0)
set(  INCLUDE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}//include_folder)
set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(MP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include_folder/Markersparser.h)
set(MM_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include_folder/MarkerManager.h)
include_directories(
  ${INCLUDE_PATH}
)
include_directories(
  ${SRC_PATH}
)

include(CTest)
enable_testing()
set(HEADER_FILES ${MP_PATH} ${MM_PATH})

#add_library(mylib ${CMAKE_CURRENT_SOURCE_DIR}/src/MarkerManager.cpp ${HEADER_FILES})
#add_library(mylib2  MarkersParser.cpp  ${HEADER_FILES})
file( GLOB TARGET_LIBS
 src/MarkerManager.cpp
 MarkersParser.cpp
 )
add_executable(markeerparser main.cpp ${TARGET_LIBS})
# target_include_directories must be added AFTER add_executable
#target_include_directories(markeerparser PRIVATE ${INCLUDE_PATH})
#target_include_directories(markeerparser PUBLIC mylib)
#target_include_directories(markeerparser PUBLIC mylib)
#target_link_libraries(markeerparser ${HEADER_FILES})
#target_link_directories(markeerparser PUBLIC mylib)
#target_link_directories(markeerparser PUBLIC mylib2)



set(CPACK_PROJECT_NAME ${MARKERS_ZEFT})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
