cmake_minimum_required(VERSION 3.29)
project(discord-loveu VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

include(./vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_compile_definitions(DISCORD_TOKEN="Insert.Your.Discord.Token.Here")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr nlohmann_json::nlohmann_json spdlog::spdlog)