cmake_minimum_required(VERSION 3.16)
project(SpaceInvadersRE VERSION 1.0.0 LANGUAGES CXX)

# Configuração do padrão C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

# --- INTEGRAÇÃO DO RAYLIB VIA FETCHCONTENT ---
include(FetchContent)

set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(BUILD_GAMES OFF CACHE INTERNAL "")

message(STATUS "Baixando e configurando Raylib...")
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0
)
FetchContent_MakeAvailable(raylib)

# --- CONFIGURAÇÃO DO EXECUTÁVEL ---
# Pega todos os arquivos .cpp da pasta src
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(space_invaders_dc ${SRC_FILES})

# Inclui os cabeçalhos
target_include_directories(space_invaders_dc PRIVATE include)

# Link da biblioteca Raylib
target_link_libraries(space_invaders_dc PRIVATE raylib)