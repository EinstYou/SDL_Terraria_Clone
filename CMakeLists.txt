cmake_minimum_required(VERSION 4.2.1)

project(Terraria)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)



add_executable(Terraria
src/main.cpp
src/Physics.cpp
src/Game.cpp
src/Input.cpp
src/Texture.cpp
src/Player.cpp
src/World.cpp
src/Camera.cpp
)

target_include_directories(Terraria PUBLIC headers)
target_link_libraries(Terraria PUBLIC SDL3::SDL3)
target_link_libraries(Terraria PUBLIC SDL3_image::SDL3_image)