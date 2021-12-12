#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "file.h"


class counting {

	std::vector<std::filesystem::path> _vector_of_paths;
	std::vector<std::filesystem::path> _vector_of_files_paths;
	int _number_of_files = 0;
	int _number_of_directories = 0;
	int _number_of_lines = 0;
	int _number_of_full_lines = 0;
	int _number_of_empty_lines = 0;
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
		}
	}

	void create_file_paths_vector() {

		for (auto element : _vector_of_paths) {

			if (element.extension() != "") {
				_vector_of_files_paths.push_back(element);
			}
		}
	}

	int count_lines(std::vector <std::string> file_text) {

		int number_of_lines = 0;

		for (auto line : file_text) {
			number_of_lines++;
			if (line.empty()) {
				_number_of_empty_lines++;
			}
			else {
				_number_of_full_lines++;
			}
		}
		return number_of_lines;
	}

	int count_words(std::vector <std::string> file_text) {

		int number_of_words = 0;

		for (auto line : file_text) {
			for (auto charcter : line) {
				if (charcter == ' ') {
					number_of_words++;
				}
			}
			number_of_words++;
		}
		return number_of_words + 1;
	}

	int count_letters(std::vector <std::string> file_text) {

		int number_of_letters = 0;

		for (auto line : file_text) {
			for (auto charcter : line) {
				if (isalpha(charcter)) {
					number_of_letters++;
				}
			}
		}
		return number_of_letters;
	}

	void count_all_letters() {

		for (auto element : _vector_of_files_paths) {

			file myfile;
			myfile.open_file(element.string());
			_number_of_letters += count_letters(myfile.get_file_text());
		}
	}

	void count_all_words() {

		for (auto element : _vector_of_files_paths) {

			file myfile;
			myfile.open_file(element.string());
			_number_of_words += count_words(myfile.get_file_text());
		}
	}

	void count_all_lines() {

		for (auto element : _vector_of_files_paths) {

			file myfile;
			myfile.open_file(element.string());
			_number_of_lines += count_lines(myfile.get_file_text());
		}
	}


	void get_number_of_files() { 
		std::cout << "Number of files: " << _number_of_files << std::endl;
	}
	void get_number_of_directories() {
		std::cout << "Number of directories: " << _number_of_directories << std::endl;
	}
	void get_number_of_lines() {
		std::cout << "Number of lines: " << _number_of_lines << std::endl;
	}
	void get_number_of_full_lines(){
		std::cout << "Number of full lines: " << _number_of_full_lines << std::endl;
	}
	void get_number_of_empty_lines() {
		std::cout << "Number of empty lines: " << _number_of_empty_lines << std::endl;
	}
	void get_number_of_words() {
		std::cout << "Number of words: " << _number_of_words << std::endl;
	}
	void get_number_of_letters() {
		std::cout << "Number of letters: " << _number_of_letters << std::endl;
	}
};