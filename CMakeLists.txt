cmake_minimum_required(VERSION 3.11[FATAL_ERROR])

project(LRUCache)

add_executable(LRUmain cache.hpp LRU.cc)

add_subdirectory(tests)