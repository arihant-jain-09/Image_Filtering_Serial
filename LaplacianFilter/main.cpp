#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include "laplacianFilter.cpp"
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

   cv::cvtColor(srcImage, srcImage, CV_BGR2GRAY);
   cv::Mat dstImage (srcImage.size(), srcImage.type());
   laplacianFilter_CPU(srcImage, dstImage);
  
   dstImage.convertTo(dstImage, CV_32F, 1.0 / 255, 0);
   dstImage*=255;
   imwrite(output_file_cpu, dstImage);
      
   return 0;
}





