// ConsoleApplication1.cpp:¡£
//

//#include "stdafx.h"
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include "stdafx.h"
#include "direct.h"
#include<windows.h>
//#include "model.h"
//#include "shapeRegression.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include "NPDDetector.h"
#include "imtransform.h"
#include <time.h>
//#define SHOW_TAG
//#define SAVE_INFOR

using namespace std;

int main( int argc, char** argv )
{
	
	ifstream in("Your image list file");
	string parent_dir_save = "the directory to save the cropped images";
	string parent_dir = "the directory that contains your raw images";
	string shapeName;
	string image_name;
	string fold_name;
	string tmpString;
	double tmp;
	string::size_type sz;
	DWORD time_begin, time_end;
	while (in>>image_name)
	{
//		in>>fold_name;

		cv::Mat img = cv::imread(parent_dir+image_name,CV_LOAD_IMAGE_COLOR);
	
		// Get the coordinates of eye center and up_lip_center of the face image.
		double eye_center_x = $eye_center_x$;//eye center
		double eye_center_y = $eye_center_y$;//eye center
		double up_lip_center_x = $up_lip_center_x$;//lip center (up)
		double up_lip_center_y = $up_lip_center_y$;//lip center (up)
		//========================image transform (begin)====================================
		time_begin = GetTickCount();
		cv::Mat img_transform = sim_transform_image_3channels(img,
					eye_center_x, eye_center_y, 
					up_lip_center_x, up_lip_center_y);
		time_end = GetTickCount();
		cout<<"crop,rotate: "<<time_end-time_begin<<" ms"<<endl;
		#ifdef SHOW_TAG
			cv::namedWindow("crop", CV_WINDOW_AUTOSIZE);
			imshow("crop", img_transform);
			cv::waitKey();
		#endif
		imwrite(parent_dir_save+image_name,img_transform);
		//========================image transform (end)====================================

	}
	in.close();

	return 0;
}

