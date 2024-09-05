add_executable (Eidolon 
  "Eidolon.cpp" 
  "Eidolon.h"
  "Imagery.cpp"
  "Imagery.h"
)

include_directories(${OpenCV_INCLUDE_DIRS})

target_include_directories(Eidolon PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(Eidolon PRIVATE ${OpenCV_LIBS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Eidolon PROPERTY CXX_STANDARD 20)
endif()

