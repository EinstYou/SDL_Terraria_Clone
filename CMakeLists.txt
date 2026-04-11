cmake_minimum_required(VERSION 4.2.1)

project(MyProject)


add_subdirectory(SDL)
add_subdirectory(SDL_image)



add_executable(MyProject 
src/main.c
src/Physics.c
src/Game.c
src/Input.c
src/Texture.c
src/Player.c
)

target_include_directories(MyProject PUBLIC headers)
target_link_libraries(MyProject PUBLIC SDL3::SDL3)
target_link_libraries(MyProject PUBLIC SDL3_image::SDL3_image)