#pragma once
#include <fstream>
#include <string>
#include <vector>

class file {

private:

	std::vector <std::string> _file_text;
	

public:

	void open_file(std::string path) {

		std::ifstream readFile;
		readFile.open(path);
		std::string line;
		if (readFile.is_open()) {
			while (std::getline(readFile, line)) {

				_file_text.push_back(line);
			}
		}
		readFile.close();
	}

	std::vector <std::string> get_file_text() { return  _file_text; }

};