#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

class counting {

	std::vector<std::filesystem::path> _vector_of_paths;
	int _number_of_files = 0;
	int _number_of_directories = 0;
	int _number_of_rows = 0;
	int _number_of_full_rows = 0;
	int _number_of_empty_rows = 0;
	int _number_of_words = 0;
	int _number_of_letters = 0;

public:

	counting(std::vector<std::filesystem::path> vector_of_paths) : _vector_of_paths(vector_of_paths) {};

	void count_files() {
	
		for (auto element : _vector_of_paths) {
		
			if (element.extension() != "") {
				_number_of_files++;
			}
			else {
				_number_of_directories++;
			}

			std::cout << element.extension() << std::endl;
		}
		
	}

	void get_number_of_files() { 
		std::cout << "Number of files: " << _number_of_files << std::endl;
	}
	void get_number_of_directories() {
		std::cout << "Number of directories: " << _number_of_directories << std::endl;
	}
	void get_number_of_rows() {
		std::cout << "Number of rows: " << _number_of_rows << std::endl;
	}
	void get_number_of_full_rows(){
		std::cout << "Number of full rows: " << _number_of_full_rows << std::endl;
	}
	void get_number_of_empty_rows() {
		std::cout << "Number of empty rows: " << _number_of_empty_rows << std::endl;
	}
	void get_number_of_words() {
		std::cout << "Number of words: " << _number_of_words << std::endl;
	}
	void get_number_of_letters() {
		std::cout << "Number of letters: " << _number_of_letters << std::endl;
	}
};