# CMakeList.txt : CMake project for Eidolon, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Eidolon "Eidolon.cpp" "Eidolon.h")

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(Eidolon ${OpenCV_LIBS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Eidolon PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
