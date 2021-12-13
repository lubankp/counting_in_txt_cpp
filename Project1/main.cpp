#include "directory.h"
#include "counting.h"


int main() {
    
    
    directory dir;
   
    dir.set_directory_name();
    std::vector<std::filesystem::path> vector_of_paths = dir.list_directory();
    //dir.print_directory_list(vector_of_paths);

    counting counting_class(vector_of_paths);
    counting_class.count_files();
    counting_class.get_number_of_files();
    counting_class.get_number_of_directories();
    counting_class.create_file_paths_vector();
    counting_class.count_all_lines();
    counting_class.get_number_of_lines();
    counting_class.get_number_of_empty_lines();
    counting_class.get_number_of_full_lines();
    counting_class.count_all_words();
    counting_class.get_number_of_words();
    counting_class.count_all_letters();
    counting_class.get_number_of_letters();

   


}
