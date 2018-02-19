add_library(podiods TPodioDS.cxx)
target_link_libraries(podiods ${ROOT_LIBRARIES})
target_include_directories(podiods PUBLIC ${ROOT_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/inc )

function (copy_header headername)
	configure_file("${headername}" "${CMAKE_BINARY_DIR}/include/${headername}" COPYONLY)
endfunction()
