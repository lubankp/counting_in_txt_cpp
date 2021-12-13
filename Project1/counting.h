#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "file.h"
#include "thread_pool.hpp"

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

	void count_all_letters() {

			thread_pool pool1(10);
			int number_of_letters = 0;
			std::vector<std::filesystem::path> vector_of_files_paths = get_vector_of_files_paths();

			auto lambda1 = [&vector_of_files_paths, &number_of_letters](auto& a, auto& b)
			{
				for (auto i = a; i < b; i++) {

					file myfile;
					myfile.open_file(vector_of_files_paths[i].string());
					std::vector <std::string> file_text = myfile.get_file_text();

					for (auto line : file_text) {
						for (auto charcter : line) {
							if (isalpha(charcter)) {
								number_of_letters++;
							}
						}
					}

				}
			};
			pool1.parallelize_loop(0, _vector_of_files_paths.size(), lambda1, 1);
			_number_of_letters = number_of_letters;
			
	}

	void count_all_words() {

		thread_pool pool2(10);
		int number_of_words = 0;
		std::vector<std::filesystem::path> vector_of_files_paths = get_vector_of_files_paths();

		auto lambda2 = [&vector_of_files_paths, &number_of_words](auto& a, auto& b){
			for (auto i = a; i < b; i++) {

				file myfile;
				myfile.open_file(vector_of_files_paths[i].string());
				std::vector <std::string> file_text = myfile.get_file_text();

					for (auto line : file_text) {
						for (auto charcter : line) {
							if (charcter == ' ') {
								number_of_words++;
							}
						}
						number_of_words++;
					}

			}
		};
		pool2.parallelize_loop(0, _vector_of_files_paths.size(), lambda2, 1);
		_number_of_words = number_of_words;
	}

	void count_all_lines() {

		thread_pool pool2(10);
		int number_of_lines = 0;
		int number_of_empty_lines = 0;
		int number_of_full_lines = 0;
		std::vector<std::filesystem::path> vector_of_files_paths = get_vector_of_files_paths();

		auto lambda3 = [&vector_of_files_paths, &number_of_lines, &number_of_empty_lines, &number_of_full_lines](auto& a, auto& b) {
			for (auto i = a; i < b; i++) {

				file myfile;
				myfile.open_file(vector_of_files_paths[i].string());
				std::vector <std::string> file_text = myfile.get_file_text();

				for (auto line : file_text) {
					number_of_lines++;
					if (line.empty()) {
						number_of_empty_lines++;
					}
					else {
						number_of_full_lines++;
					}
				}

			}
		};
		pool2.parallelize_loop(0, _vector_of_files_paths.size(), lambda3, 1);
		_number_of_lines = number_of_lines;
		_number_of_empty_lines = number_of_empty_lines;
		_number_of_full_lines = number_of_full_lines;
	}

	std::vector<std::filesystem::path> get_vector_of_files_paths() {
		return _vector_of_files_paths;
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