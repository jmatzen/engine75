cmake_minimum_required (VERSION 3.13)
project (engine75)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include(FindVulkan)
find_package(Vulkan REQUIRED)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_definitions(-DGL_GLEXT_PROTOTYPES)
add_definitions(-DGLM_ENABLE_EXPERIMENTAL)
add_definitions(-DGLM_FORCE_RADIANS)
add_definitions(-DSDL_MAIN_HANDLED)
add_definitions(-DGLM_FORCE_DEPTH_ZERO_TO_ONE)


if (MSVC)
  add_definitions(/D_SCL_SECURE_NO_WARNINGS /DUSE_GLEW)
  add_definitions(/D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
  add_definitions(/D_WIN32_WINNT=0x0601)
  add_definitions(/DGLM_FORCE_XYZW_ONLY)

  add_definitions(/DNOMINMAX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP  /std:c++latest /Zc:__cplusplus")
elseif(APPLE OR CLANG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
endif()


include_directories(src) 
add_subdirectory(src)

#add_subdirectory(src/core)
#add_subdirectory(src/sdl)
#add_subdirectory(src/scene)
#add_subdirectory(src/geo)
#add_subdirectory(src/serialization)
#add_subdirectory(src/opengl)
#add_subdirectory(src/render)
#add_subdirectory(src/graphics)
