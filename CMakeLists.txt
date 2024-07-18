cmake_minimum_required (VERSION 3.12)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project ("Cairo Research")

include (${PROJECT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup (NO_OUTPUT_DIRS)

if (CMAKE_HOST_WIN32)
    include (config-win32.cmake)

elseif (CMAKE_HOST_UNIX)
    include (config-unix.cmake)

else ()
    message (FATAL_ERROR "[Cairo Research] Unknown platform.")

endif ()
