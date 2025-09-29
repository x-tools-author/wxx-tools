# https://codeload.github.com/chriskohlhoff/asio/zip/refs/tags/asio-1-36-0
set(package_version 1-36-0)
set(package_name asio-asio-${package_version})
set(package_url_base https://codeload.github.com/chriskohlhoff/asio/zip/refs/tags)
set(package_url ${package_url_base}/asio-${package_version})

# Download and unpack Asio if not already done
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
    WORKING_DIRECTORY ${WXXT_3RD_DIR}
    RESULT_VARIABLE result)
  if(NOT result EQUAL 0)
    message(FATAL_ERROR "Error unpacking ${package_name}")
  endif()
endif()

include_directories(${WXXT_3RD_DIR}/${package_name}/asio/include)
