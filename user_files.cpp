#include "user_files.h"
#include <iostream>
#include <boost/range/iterator_range.hpp>
#include <string>
#include "audio_data_decoder/audio_data_reader.h"

static const int HEADER_SIZE = 10;


std::string check_audio_extension(std::string file_path) {

	FILE* file = fopen(file_path.c_str(), "r");
	if (!file) return "be";

	std::string buffer(4, '\0');

	fread(&buffer[0], 1, HEADER_SIZE, file);
	fclose(file);

	if (buffer == "fLaC") return "FLAC";
	if (buffer.substr(0, 3) == "ID3") return "MP3";
	if (buffer == "OggS") return "OGG";

	return "be";
}


void read_directory(const boost::filesystem::path &path_to_root_directory, std::vector<audio_data*> &tracks) {

	boost::filesystem::path root_path = path_to_root_directory;
	boost::filesystem::directory_iterator it{root_path};
	
	if (boost::filesystem::is_directory(root_path)) {

		for (auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(root_path), {})) {

			if (boost::filesystem::is_regular_file(entry)) {

				std::string extension = check_audio_extension(entry.path().string());
				bool is_audio = (extension == "MP3") || (extension == "FLAC"); // || (extension == "OggS");
				if (extension == "MP3")
					tracks.push_back(new mp3_data(entry.path().c_str()));
				if (extension == "FLAC")
					tracks.push_back(new flac_data(entry.path().c_str()));

				// if (is_audio) write_file_info();	

				// std::cout << entry.path().string() << ((is_audio) ? " - audio" : " - not audio or can't open") << std::endl;
			}
			else if (boost::filesystem::is_directory(entry)) 
				read_directory(entry.path());
		}
	}
	std::cout << '\n' << tracks.size();

	for (auto& track : tracks)
		track->print_file_info();
	
	return;
}
