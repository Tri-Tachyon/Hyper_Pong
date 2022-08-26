set(CMAKE_CXX_STANDARD 20)

find_package(raylib)

#temporary:

include_directories(/usr/local/include)

include_directories(/usr/local/lib)

add_subdirectory(lib_hyper_pong)

add_executable(hyper_pong hyper_pong/main.cpp lib_hyper_pong/config.hpp)

target_link_libraries(hyper_pong raylib lib_hyper_pong)