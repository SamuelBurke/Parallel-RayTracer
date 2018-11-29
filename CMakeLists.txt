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
 src/Application.h
 src/Program.h
 src/RayTracer.h
 src/Geometry.h
 src/Camera.h
 src/Object.h
 src/Sphere.h
 src/Input.h
 src/Window.h

 src/main.cpp
 src/Application.cpp
 src/RayTracer.cpp
 src/Geometry.cpp
 src/Camera.cpp
 src/Object.cpp
 src/Sphere.cpp
 src/Input.cpp
 src/Window.cpp
)

target_link_libraries(RayTracer_Parallel SDL2)

if(MSVC)
 add_custom_command(TARGET RayTracer_Parallel POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
    "$<TARGET_FILE_DIR:RayTracer_Parallel>"
)
endif()