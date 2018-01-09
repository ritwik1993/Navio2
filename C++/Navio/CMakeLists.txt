file (GLOB SOURCES
"Common/*.cpp"
"Common/*.h"
"Navio2/*.cpp"
"Navio2/.h")

include_directories(".")

add_library(navio SHARED ${SOURCES})

install(TARGETS navio DESTINATION ${CMAKE_BINARY_DIR}/install/libs)
