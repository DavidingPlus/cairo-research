message ("-- [Cairo Research] Building on Win32 ...")

message ("-- [Cairo Research] Using C Compiler: ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_VERSION})")
message ("-- [Cairo Research] Using C++ Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_VERSION})")

option (SUPRESS_W3_WARNINGS "Configure warning level to /W2" ON)
if (SUPRESS_W3_WARNINGS)
    add_compile_options ("/W2")
endif ()

add_compile_options ("/Z7")

find_program (CCACHE_EXECUTABLE ccache)
if (CCACHE_EXECUTABLE)
    message ("-- Ccache executable found at: ${CCACHE_EXECUTABLE}")
    file (COPY "${CCACHE_EXECUTABLE}" DESTINATION "${PROJECT_BINARY_DIR}")
    file (RENAME "${PROJECT_BINARY_DIR}/ccache.exe" "${PROJECT_BINARY_DIR}/cl.exe")
    set (CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")
    set (CMAKE_VS_GLOBALS
        "CLToolExe=cl.exe"
        "CLToolPath=${PROJECT_BINARY_DIR}"
        "TrackFileAccess=false"
        "UseMultiToolTask=true"
        "DebugInformationFormat=OldStyle"
    )

else ()
    message ("-- CCache not found.")

endif ()

set (CMAKE_WIN32_EXECUTABLE true)
add_executable (Win32SurfaceTest
    src/win32/win32-surface.cpp
)
target_link_libraries (Win32SurfaceTest ${CONAN_LIBS})

set (CMAKE_WIN32_EXECUTABLE true)
add_executable (ImageSurfaceTest
    src/win32/image-surface.cpp
)
target_link_libraries (ImageSurfaceTest ${CONAN_LIBS})
