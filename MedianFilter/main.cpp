#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include "medianFilter.cpp"
using namespace std;

int main( int argc, char** argv ) {

   string image_name = "sample";
   string input_file =  image_name+".jpg";
   string output_file_cpu = image_name+"_cpu.jpg";

   cv::Mat srcImage = cv::imread(input_file ,CV_LOAD_IMAGE_UNCHANGED);
   if(srcImage.empty())
   {
      std::cout<<"Image Not Found: "<< input_file << std::endl;
      return -1;
   }
   cout <<"\ninput image size: "<<srcImage.cols<<" "<<srcImage.rows<<" "<<srcImage.channels()<<"\n";
     
   cv::Mat dstImage (srcImage.size(), srcImage.type());

   medianFilter_CPU(srcImage, dstImage);
   imwrite(output_file_cpu, dstImage);
       
   return 0;
}





