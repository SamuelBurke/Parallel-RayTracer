cmake_minimum_required(VERSION 2.6)
project(RAYTRACER)

include_directories(
 contrib
)

if (MSVC)
 include_directories(
  contrib/msvc-windows-x86/SDL2/include
)

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
)
endif()

if (MSVC)
 add_definitions(-DSDL_MAIN_HANDLED)
endif()


add_executable(RayTracer_Parallel
 src/main.cpp
)

target_link_libraries(RayTracer_Parallel SDL2)

if(MSVC)
 add_custom_command(TARGET RayTracer_Parallel POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
    "$<TARGET_FILE_DIR:RayTracer_Parallel>"
)
endif()