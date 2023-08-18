cmake_minimum_required(VERSION 3.20)

project("Roman_Numerals" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CheckIPOSupported)
check_ipo_supported(RESULT LTOsupported OUTPUT error)

if(LTOsupported)
    message(STATUS "IPO / LTO supported.")
    if (CMAKE_BUILD_TYPE MATCHES RELEASE)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE) # LTO ON
        # set_property(TARGET example PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    endif()
else()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif()

set(
    SRC_FILES
    main.cpp
    RomanNumerals.hpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Roman Numerals")