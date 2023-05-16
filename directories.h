#pragma once

#include <iostream>
#include <vector>

namespace directories {

	enum types_ {FOLDER = 0, ENTRY = 1};

	class directory_content_obj {
	public:
		directory_content_obj() {};
		directory_content_obj(std::string path, std::string name, types_ type) : path_(path), name_(name), type_(type) {}

		std::string path_;
		std::string name_;
		types_ type_;
	};

	class directory {
	public:
		directory() {};
		directory(std::string path) : path_(path) {};

		std::vector<directory_content_obj *> &get_content();

		void print_content() {
			for (const auto& obj: content_) 
				std::cout << obj->name_ << " : " << obj->type_ << std::endl;
		}

		std::string path_;
		std::vector<directory_content_obj *> content_;
	};
}
