#include "user_files.h"
// #include "mp3_data_reader/read_mp3_tags.h"
// #include "flac_data_reader/FLAC_track_info.h"

#include <iostream>


int main() {

	// mp3_info info = read_mp3_info("/home/varvara/projects/mp3_data_reader/Tim Buckley - Once I Was.mp3");
	// FLAC_info info1 = read_flac_info("/home/varvara/Music/01 - Mellow Sonic - Loneliness.flac");
	// print_mp3_info(info);
	// print_flac_info(info1);
	boost::filesystem::path root_path{"/home/varvara/Music"};

	read_directory(root_path, LINEAL);
	return 0;
}