include(GenerateExportHeader)

set(vtflib_SRCS
	Error.cpp
	FileReader.cpp
	FileWriter.cpp
	Float16.cpp
	MemoryReader.cpp
	MemoryWriter.cpp
	Proc.cpp
	ProcReader.cpp
	ProcWriter.cpp
	VMTFile.cpp
	VMTGroupNode.cpp
	VMTIntegerNode.cpp
	VMTNode.cpp
	VMTSingleNode.cpp
	VMTStringNode.cpp
	VMTValueNode.cpp
	VTFFile.cpp
	VTFLib.cpp
	VTFMathlib.cpp
	VTFWrapper.cpp
	txc_compress_dxtn.c
	txc_fetch_dxtn.c
	)

set(vtflib_HDRS
	Error.h
	FileReader.h
	FileWriter.h
	Float16.h
	MemoryReader.h
	MemoryWriter.h
	Proc.h
	ProcReader.h
	ProcWriter.h
	Reader.h
	Readers.h
	resource.h
	stdafx.h
	VMTFile.h
	VMTGroupNode.h
	VMTIntegerNode.h
	VMTNode.h
	VMTNodes.h
	VMTSingleNode.h
	VMTStringNode.h
	VMTValueNode.h
	VTFDXTn.h
	VTFFile.h
	VTFFormat.h
	VTFLib.h
	VTFMathlib.h
	VTFWrapper.h
	Writer.h
	Writers.h
	"${CMAKE_CURRENT_BINARY_DIR}/config.h")

configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)
configure_file(Resource.rc.in "${CMAKE_CURRENT_BINARY_DIR}/Resource.rc" @ONLY)
configure_file(resource.h "${CMAKE_CURRENT_BINARY_DIR}/resource.h" COPYONLY)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	add_subdirectory(windows)
else()
	add_subdirectory(unix)
endif()

add_library(${VTFLIB_NAME}
		${vtflib_SRCS}
		${vtflib_OS_SRCS}
		${vtflib_HDRS}
		"${CMAKE_CURRENT_BINARY_DIR}/Resource.rc")

set_target_properties(${VTFLIB_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
if(USE_LIBTXC_DXTN)
	target_link_libraries(${VTFLIB_NAME} ${LIBTXC_DXTN_LIBRARY})
endif()

install(TARGETS ${VTFLIB_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${vtflib_HDRS} DESTINATION "include/${VTFLIB_NAME}")
