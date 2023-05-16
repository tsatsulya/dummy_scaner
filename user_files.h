#pragma once

#include <boost/filesystem.hpp>
#include "audio_data_decoder/audio_data.h"
#include "directories.h"

enum reading_mod : char {RECURSIVE = 0, LINEAL};

static directories::directory *directory_content = new directories::directory();
directories::directory *read_directory(const boost::filesystem::path &path_to_root_directory = "/", reading_mod mod = LINEAL, directories::directory *dir = directory_content);
