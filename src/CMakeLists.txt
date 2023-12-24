cmake_minimum_required(VERSION 3.14.0)

# The following lines must come before project(...)
# See https://stackoverflow.com/questions/58900537/building-a-simple-c-project-on-windows-using-cmake-and-clang
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -target x86_64-w64-mingw32")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target x86_64-w64-mingw32")

project(xtensor-stack)

message("Working on xtensor-stack/src/CMakeLists.txt")
message("CMAKE_SOURCE_DIR:")
message(${CMAKE_SOURCE_DIR})
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(STRING(REGEX REPLACE "\\\\" "/" ${CMAKE_SOURCE_DIR}/xtl/include)) 
include_directories(STRING(REGEX REPLACE "\\\\" "/" ${CMAKE_SOURCE_DIR}/xtensor/include))
include_directories(STRING(REGEX REPLACE "\\\\" "/" ${CMAKE_SOURCE_DIR}/xtensor-blas/include))
include_directories(STRING(REGEX REPLACE "\\\\" "/" ${CMAKE_SOURCE_DIR}/cxxblas/include))

add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/libreflapack_nu.lib ${CMAKE_SOURCE_DIR}/libreflapack_wu.lib COMMAND make WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lapack)
add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/libblas_REF_nu.lib ${CMAKE_SOURCE_DIR}/libblas_REF_wu.lib COMMAND make WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/blas)
add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/cblas_nu.lib ${CMAKE_SOURCE_DIR}/cblas_wu.lib COMMAND make WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/cblas)

add_custom_target(libreflapack_nu.lib DEPENDS ${CMAKE_SOURCE_DIR}/libreflapack_nu.lib)
add_custom_target(libreflapack_wu.lib DEPENDS ${CMAKE_SOURCE_DIR}/libreflapack_wu.lib)
add_custom_target(libblas_REF_nu.lib DEPENDS ${CMAKE_SOURCE_DIR}/libblas_REF_nu.lib)
add_custom_target(libblas_REF_wu.lib DEPENDS ${CMAKE_SOURCE_DIR}/libblas_REF_wu.lib)
add_custom_target(cblas_nu.lib DEPENDS ${CMAKE_SOURCE_DIR}/cblas_nu.lib)
add_custom_target(cblas_wu.lib DEPENDS ${CMAKE_SOURCE_DIR}/cblas_wu.lib)

add_subdirectory(tests)

install (DIRECTORY xtl/include/xtl DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (DIRECTORY xtensor/include/xtensor DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (DIRECTORY xtensor-blas/include/xflens DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (DIRECTORY xtensor-blas/include/xtensor-blas DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (FILES libreflapack_nu.lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES libreflapack_wu.lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES libblas_REF_nu.lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES libblas_REF_wu.lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES cblas_nu.lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES cblas_wu.lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES build/tests/tests.exe DESTINATION ${CMAKE_INSTALL_BINDIR})

