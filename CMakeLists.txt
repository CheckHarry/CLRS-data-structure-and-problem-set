

cmake_minimum_required(VERSION 3.1)
project("CLRS Data structure and problem set")


if(MSVC)
  set(variables 
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
	CMAKE_CXX_FLAGS_RELWITHDEBINFO
	CMAKE_CXX_FLAGS_MINSIZEREL
  )
  foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
  endforeach()
endif()

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()
SET(CMAKE_CXX_FLAGS  "-std=c++2a")

add_subdirectory(./googletest)
add_subdirectory(./Allocator)
include_directories(./Allocator)

add_executable(main main.cpp heap.h)

enable_testing()

add_executable(heap_test heap_test.cpp)
target_link_libraries(heap_test gtest gtest_main)

add_executable(red_black_tree_test red_black_tree_test.cpp)
target_link_libraries(red_black_tree_test gtest gtest_main)

add_executable(vector_test vector_test.cpp)
target_link_libraries(vector_test gtest gtest_main)

add_executable(Allocator_test Allocator_test.cpp)
target_link_libraries(Allocator_test ClassicAllocator)
target_link_libraries(Allocator_test LinearAllocator)
#target_link_libraries(Allocator_test gtest gtest_main)
#target_link_libraries(heap_test heap_lib)

