################################################################################
# Copyright (c) Almério José Venâncio Pains Soares                             #
#                                                                              #
# Distributed under the terms of the Apache 2 License.                         #
#                                                                              #
# The full license is in the file LICENSE, distributed with this software.     #
################################################################################

cmake_minimum_required(VERSION 3.1)

project(cmps)

set(CMPS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Version
# =======

file(STRINGS "${CMPS_INCLUDE_DIR}/cmps/config/cmps_config.h" cmps_version_defines
    REGEX "define CMPS_VERSION_(MAJOR|MINOR|PATCH)")

foreach(ver ${mps_version_defines})
    if(ver MATCHES "define CMPS_VERSION_(MAJOR|MINOR|PATCH) +([^ ]+)$")
        set(CMPS_VERSION_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
    endif()
endforeach()

set(${PROJECT_NAME}_VERSION
    ${CMPS_VERSION_MAJOR}.${CMPS_VERSION_MINOR}.${CMPS_VERSION_PATCH})
message(STATUS "cmps v${${PROJECT_NAME}_VERSION}")

# Build
# =====

find_package(BLAS)
find_package(LAPACK)

set(CMPS_HEADERS
    ${CMPS_INCLUDE_DIR}/mps/mps.h
    ${CMPS_INCLUDE_DIR}/mps/config/mps_align.h
    ${CMPS_INCLUDE_DIR}/mps/config/mps_config.h
    ${CMPS_INCLUDE_DIR}/mps/config/mps_include.h
    ${CMPS_INCLUDE_DIR}/mps/config/mps_instruction_set.h
)

add_library(mps INTERFACE)

target_include_directories(mps INTERFACE
    $<BUILD_INTERFACE:  ${CMPS_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>)

target_compile_features(cmps INTERFACE c_std_11)


# Installation
# ============

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGET mps
        EXPORT ${PROJECT_NAME}-targets)

# Makes the project importable from build directory

export(EXPORT ${PROJECT_NAME}-targets
       FILE   "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

install(DIRECTORY   ${CMPS_INCLUDE_DIR}/mps
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#GNUInstallDirs "DATADIR" wrong here; CMake search path wants "share"
set(CMPS_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for mpsConfig.cmake")

configure_package_config_file(${PROJECT_NAME}Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMPS_CMAKECONFIG_INSTALL_DIR})

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${${PROJECT_NAME}_VERSION}
    COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${CMPS_CMAKECONFIG_INSTALL_DIR})

install(EXPORT ${PROJECT_NAME}-targets
        FILE   ${PROJECT_NAME}Targets.cmake
        DESTINATION ${CMPS_CMAKECONFIG_INSTALL_DIR})

configure_file(${PROJECT_NAME}.pc.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
    @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig/")
