# SegmentLabeler
cmake_minimum_required(VERSION 2.8)

# project name
project(SegmentLabeler)

# find dependencies 
find_package(OpenCV REQUIRED)

add_library(SegmentLabeler 
	SHARED
	SegmentLabeler.cpp
)
target_link_libraries(SegmentLabeler
	${OpenCV_LIBS}
)

add_executable(TestSegmentLabeler
	test_segmentlabeler.cpp
)
target_link_libraries(TestSegmentLabeler
	SegmentLabeler ${OpenCV_LIBS}
)

option(BUILD_PYTHON "Build SWIG/Python module" OFF)
if(BUILD_PYTHON)
    add_subdirectory(python)
endif(BUILD_PYTHON)


###############################################################################
## 								Install
# Binaries and libs
install(TARGETS SegmentLabeler
#	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
#	ARCHIVE DESTINATION lib
)
# Header files
#install(FILES lbp.hpp
#	DESTINATION include
#)
