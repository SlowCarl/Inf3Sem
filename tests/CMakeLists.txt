add_subdirectory(Catch2)

add_executable(tests test_main.cpp test_LRUCache.cpp)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR} Catch2/single_include)

target_link_libraries(tests Catch2::Catch2)

include(CTest)

add_test(NAME MyTests COMMAND tests)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)