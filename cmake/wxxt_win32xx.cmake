# https://master.dl.sourceforge.net/project/win32-framework/Win32%2B%2B/Version%209.6.1/Win32xx961.zip?viasf=1
set(package_version 9.6.1)
string(REPLACE "." "" package_version_no_dots ${package_version})
set(package_name Win32xx${package_version_no_dots})
set(package_url_base https://master.dl.sourceforge.net/project/win32-framework/Win32%2B%2B)
set(package_url ${package_url_base}/Version%20${package_version}/${package_name}.zip?viasf=1)

# Download and unpack Win32++ if not already done
if(NOT EXISTS ${WXXT_3RD_DIR}/${package_name}.zip)
  message(STATUS "Downloading ${package_name}...")
  file(
    DOWNLOAD ${package_url} ${WXXT_3RD_DIR}/${package_name}.zip
    SHOW_PROGRESS
    STATUS download_status)
  if(NOT download_status EQUAL 0)
    message(FATAL_ERROR "Error downloading ${package_name}: ${download_status}")
  endif()
endif()

# Unpack the zip file
if(NOT EXISTS ${WXXT_3RD_DIR}/${package_name})
  file(MAKE_DIRECTORY ${WXXT_3RD_DIR}/${package_name})
  message(STATUS "Unpacking ${package_name}...")
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E tar xfz ${WXXT_3RD_DIR}/${package_name}.zip
    WORKING_DIRECTORY ${WXXT_3RD_DIR}/${package_name}
    RESULT_VARIABLE result)
  if(NOT result EQUAL 0)
    message(FATAL_ERROR "Error unpacking ${package_name}")
  endif()
endif()

include_directories(${WXXT_3RD_DIR}/${package_name}/include)
