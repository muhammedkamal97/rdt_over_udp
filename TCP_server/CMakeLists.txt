cmake_minimum_required(VERSION 3.12)
project(TCP_server)

set(CMAKE_CXX_STANDARD 14)

add_executable(TCP_server main.cpp Server.cpp Server.h packet_types.h reliable_portocols/Reliable_abstract.cpp reliable_portocols/Reliable_abstract.h reliable_portocols/Stop_wait.cpp reliable_portocols/Stop_wait.h reliable_portocols/Selective_repeat.cpp reliable_portocols/Selective_repeat.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(TCP_server Threads::Threads)
