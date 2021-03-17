file(GLOB files *.hpp *.cpp)
add_executable(client ${files})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(client CONAN_PKG::pdqlog CONAN_PKG::sdl2 )

#target_link_libraries(lib-engine lib-lua imgui)
