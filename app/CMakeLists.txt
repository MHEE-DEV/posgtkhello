cmake_minimum_required(VERSION 3.15)
project(posgtkhello CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)

include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})
add_definitions(${GTK2_CFLAGS_OTHER})

add_executable(posgtkhello main.cpp)
target_include_directories(posgtkhello PRIVATE include)

target_link_libraries(posgtkhello ${GTK2_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS posgtkhello RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})