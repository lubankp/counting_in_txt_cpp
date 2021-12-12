#include "directory.h"
#include "counting.h"

int main() {

    directory dir;
   
    dir.set_directory_name();
    std::vector<std::filesystem::path> vector_of_paths = dir.list_directory();
    dir.print_directory_list(vector_of_paths);

    counting counting_class(vector_of_paths);
    counting_class.count_files();
    counting_class.get_number_of_files();
    counting_class.get_number_of_directories();

}