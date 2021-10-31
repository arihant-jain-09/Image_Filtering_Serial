#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include "tvFilter.cpp"
using namespace std;

int main( int argc, char** argv ) {

   string image_name = "sample";
   string input_file =  image_name+".jpg";
   string output_file_cpu = image_name+"_cpu.jpg";
  
   cv::Mat srcImage = cv::imread(input_file ,cv::IMREAD_UNCHANGED);
   if(srcImage.empty())
   {
      std::cout<<"Image Not Found: "<< input_file << std::endl;
      return -1;
   }
   cout <<"\ninput image size: "<<srcImage.cols<<" "<<srcImage.rows<<" "<<srcImage.channels()<<"\n";

   cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2GRAY);
   cv::Mat dstImage_cpu (srcImage.size(), srcImage.type());
    
   tvFilter_CPU(srcImage, dstImage_cpu);
  
   dstImage_cpu.convertTo(dstImage_cpu, CV_32F, 1.0 / 255, 0);
   dstImage_cpu*=255;

   imwrite(output_file_cpu, dstImage_cpu);
      
   return 0;
}





