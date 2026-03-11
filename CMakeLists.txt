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
file(GLOB_RECURSE ALL_SOURCES "Engine/src/*.cpp" "Game/src/*.cpp")

# Tworzenie pliku wykonywalnego (.exe) z odnalezionych plików
add_executable(${PROJECT_NAME} ${ALL_SOURCES})

# Podłączenie biblioteki graficznej
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System)

# Automatyczne kopiowanie plików DLL
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "C:/SFML/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()