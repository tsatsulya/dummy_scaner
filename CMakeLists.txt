cmake_minimum_required(VERSION 3.5)

project(dir) 
add_executable(view main.cpp user_files.cpp audio_data_decoder/audio_data_reader.cpp)


#cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja

find_package(Boost COMPONENTS system filesystem REQUIRED)
target_link_libraries(view PRIVATE Boost::headers Boost::system Boost::filesystem)

find_package(Flac REQUIRED)
target_link_libraries(view PRIVATE FLAC::FLAC++)

find_package(jsoncpp REQUIRED)
target_link_libraries(view PUBLIC jsoncpp_lib)

target_include_directories(view PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
