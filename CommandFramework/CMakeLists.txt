project(command-framework)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
FILE(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
FILE(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(command-framework SHARED ${SOURCES} ${HEADERS})


