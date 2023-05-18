#cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja

find_package(Boost COMPONENTS system filesystem REQUIRED)

find_package(Flac REQUIRED)

find_package(jsoncpp REQUIRED)


add_library(directory_scaner STATIC src/user_files.cpp)
target_include_directories(directory_scaner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(directory_scaner PUBLIC audio_data)

