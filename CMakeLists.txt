cmake_minimum_required(VERSION 3.10)

project(PlantE)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler flags
add_compile_options(-Wall -g)

# Recursively find all .cpp files
file(GLOB_RECURSE SOURCES "src/*.cpp")

cmake_policy(SET CMP0167 NEW)
find_package(Boost REQUIRED COMPONENTS uuid)

add_executable(PlantE ${SOURCES})

# Set the output directory to build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_include_directories(PlantE PRIVATE src)

target_link_libraries(PlantE PRIVATE Boost::uuid)

add_custom_target(run
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PlantE
    DEPENDS PlantE
)

add_custom_target(run-debug
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --config Debug
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PlantE
    DEPENDS PlantE
)
