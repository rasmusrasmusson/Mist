# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Mist_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Mist_autogen.dir\\ParseCache.txt"
  "Mist_autogen"
  )
endif()
