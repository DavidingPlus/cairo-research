message ("-- [Cairo Research] Building on Unix ...")

set (CMAKE_C_COMPILER "gcc")
set (CMAKE_CXX_COMPILER "g++")

message ("-- [Cairo Research] Using C Compiler: ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_VERSION})")
message ("-- [Cairo Research] Using C++ Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_VERSION})")

add_executable (XlibSurfaceTest
    src/linux/xlib-surface.cpp
)
target_link_libraries (XlibSurfaceTest ${CONAN_LIBS})

add_executable (ImageSurfaceTest
    src/linux/image-surface.cpp
)
target_link_libraries (ImageSurfaceTest ${CONAN_LIBS})
