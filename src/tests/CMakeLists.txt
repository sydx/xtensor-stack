cmake_minimum_required(VERSION 3.14.0)

project(tests)

add_executable(tests tests.cpp)
target_link_libraries(tests
	PUBLIC ${CMAKE_SOURCE_DIR}/libreflapack_wu.lib
	PUBLIC ${CMAKE_SOURCE_DIR}/libreflapack_nu.lib
	PUBLIC ${CMAKE_SOURCE_DIR}/libblas_REF_nu.lib
	PUBLIC ${CMAKE_SOURCE_DIR}/libblas_REF_wu.lib
	PUBLIC ${CMAKE_SOURCE_DIR}/cblas_nu.lib
	PUBLIC ${CMAKE_SOURCE_DIR}/cblas_wu.lib
	PUBLIC gfortran
	PUBLIC stdc++)
