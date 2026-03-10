# Minimalna wersja CMake
cmake_minimum_required(VERSION 3.15)

# Nazwa projektu
project(RetroShooter VERSION 1.0)

# Standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gdzie leży SFML
set(CMAKE_PREFIX_PATH "C:/SFML")
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

# Pliki nagłówkowe (.hpp)
include_directories(Engine/include Game/include)

# Pliki źródłowe (.cpp)
file(GLOB ENGINE_SOURCES "Engine/src/*.cpp")
file(GLOB GAME_SOURCES "Game/src/*.cpp")

# Budowa pliku wykonawczego (.exe)
add_executable(${PROJECT_NAME} ${ENGINE_SOURCES} ${GAME_SOURCES})

# Podłączenie biblioteki graficznej
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System)