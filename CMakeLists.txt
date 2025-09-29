cmake_minimum_required(VERSION 3.25)
cmake_policy(SET CMP0048 NEW)

project(
  xxTools
  VERSION 1.0
  LANGUAGES C CXX
  DESCRIPTION "A collection of useful debug tools based on Win32++")

if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY
      "MultiThreaded$<$<CONFIG:Debug>:Debug>"
      CACHE STRING "Reset option" FORCE)
endif()

set(XXT_3RD_DIR ${CMAKE_SOURCE_DIR}/3rd)

include(cmake/xxt.cmake)

file(GLOB_RECURSE SOURCE_FILES src/*.*)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include_directories(src)
include_directories(3rd/win32xx961/include)
target_link_libraries(${PROJECT_NAME} user32 kernel32 gdi32 comctl32 comdlg32)
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
