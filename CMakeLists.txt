cmake_minimum_required(VERSION 3.25)

set(tmp "A collection of useful debug tools based on Win32++")
project(
  wxxTools
  VERSION 1.0
  LANGUAGES C CXX
  DESCRIPTION ${tmp})
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------------------------------------
# Global variables
set(WXXT_3RD_DIR ${CMAKE_SOURCE_DIR}/3rd)
set(WXXT_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

# --------------------------------------------------------------------------------------------------
# Sub modules
include(cmake/wxxt.cmake)

# --------------------------------------------------------------------------------------------------
# Main target
file(GLOB_RECURSE SOURCE_FILES src/*.*)
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} wxxTools.rc)
include_directories(src)
include_directories(3rd/win32xx961/include)
target_link_libraries(${PROJECT_NAME} user32 kernel32 gdi32 comctl32 comdlg32)
