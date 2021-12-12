#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

class directory {

private:

	std::string _directory_name;
	std::vector<const std::string> _vector_of_paths;
	int _files;
	int _directories;
	int _rows;
	int _full_rows;
	int _empty_rows;
	int _works;
	int _letters;

public:

	void set_name() {
	
		std::cout << "Enter name of directory, which you want to list: ";
		std::cin >> _directory_name;
	}

	void list_directory() {

		auto dir = std::filesystem::recursive_directory_iterator(_directory_name);

		for (const auto& dir_entry : dir) {
			_vector_of_paths.push_back(dir_entry.path().string());
		}
	}

	void print_directory_list() {
	
		std::cout << " Directory content list: " << std::endl;

		for (auto element : _vector_of_paths) {
			std::cout << element;
		}	
	}

};