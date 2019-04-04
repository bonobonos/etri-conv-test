#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int your_conv( cv::Mat src,
               cv::Mat dst,
               cv::Mat kernel,
               int stride,
               int padding
               )
{
    int src_height = src.rows;
    int src_width = src.cols;

    int kernel_height = kernel.rows;
    int kernel_width = kernel.cols;


   dst = (cv::Mat_<float>(src_height-stride+1,src_width,3));



  //  int dst_height=dst.rows;
//    int dst_width=dst.cols;

    // src.ptr<unsigned char>(i)[ calculate INDEX ]

    // MAKE YOUR OWN CONVOLUTION PROCESS

for(int a = 0; a< 3; a++){
 for(int k = 0; k< src_width; k++){ 
   for(int r = 0; r< src_height; r=r+stride){
     for (int j = 0; j< kernel_width; j++){
       for (int i = 0; i<kernel_height; i++){
     
     dst.at<cv::Vec3b>(r,k)[a]+=kernel.at<cv::Vec3b>(i,j)[a]*src.at<cv::Vec3b>(i,j)[a];

       }
        }
         }
          }
           }

    // if success
    return 0;

    // if fail - in the case of wrong parameters...
    // return -1
}

int main ( int argc, char** argv )
{
    if (argc < 1) {
        std::cout << "no filename given." << std::endl;
        std::cout << "usage: " << argv[0] << " image" << std::endl;
        return -1;
    }

    cv::Mat src, kernel, dst;

    // Load an image
    src = cv::imread( argv[1] );
    if( !src.data )  { return -1; }

    // Make filter
    kernel = (cv::Mat_<float>(3,3,3) << -1, -1, -1, -1, 8, -1, -1, -1, -1,
                                         0,  0,  0,  0, 0,  0,  0,  0,  0, 
                                         0,  0,  0,  0, 0,  0,  0,  0,  0);


    // Run 2D filter
    //cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    // ---------------------------
    your_conv(src,dst,kernel,1,0);
    // ---------------------------

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
