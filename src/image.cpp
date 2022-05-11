#include <image.h>

void load_and_save(const char* in_path_src, const char* in_path_tar){

    cv::Mat img = imread(in_path_src, cv::IMREAD_UNCHANGED);
    std::cout << "Input path : " << in_path_src << std::endl;
    std::cout << "Output path : " << in_path_tar << std::endl;
    cv::imwrite(in_path_tar, img);
    
    return ;
}