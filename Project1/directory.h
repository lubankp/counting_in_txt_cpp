
#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

class directory {

private:

	std::string _directory_name;
	
public:

	void set_directory_name() {
	
		std::cout << "Enter name of directory, which you want to list: ";
		std::cin >> _directory_name;
	}

	std::vector<std::filesystem::path>  list_directory() {

		auto dir = std::filesystem::recursive_directory_iterator(_directory_name);
		std::vector<std::filesystem::path> vector_of_paths;

		for (auto& dir_entry : dir) {
			vector_of_paths.push_back(dir_entry.path());
		}
		return vector_of_paths;
	}

	void print_directory_list(std::vector<std::filesystem::path> vector_of_paths) {
	
		std::cout << "Directory content list: " << std::endl << std::endl;

		for (auto element : vector_of_paths) {
			std::cout << element.string() << std::endl;
		}	
	}

};