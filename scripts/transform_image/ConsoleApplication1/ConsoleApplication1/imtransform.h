#include <stdio.h>
#include <fstream>
#include <vector>
#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace std;

#define MAX_LANDMARKS_NUM 27
//#define STD_WIDTH 47
//#define STD_HEIGHT 55
#define STD_WIDTH 224
#define STD_HEIGHT 224
//#define MIN(a,b) (((a)<(b))?(a):(b))
//#define MAX(a,b) (((a)>(b))?(a):(b))
struct TPointF {
	float x;
	float y;
};

typedef struct {
	int id;
	float x;
	float y;
} TLandmark1;

typedef struct {
	int count;
	int view;		// 0: (-90, -30), 1: (-30, 0), 2: (0, 30), 3: (30, 90)
	TLandmark1 pts[MAX_LANDMARKS_NUM];
} TLandmarks1;

cv::Mat uchar2Mat(uchar *buffer,int width,int height);

void Mat2uchar(cv::Mat img,uchar* dst,int width,int height);

void sim_params_from_points(const TPointF dstKeyPoints[],  
	const TPointF srcKeyPoints[], int count,float* a, float* b, float* tx, float* ty);

void sim_transform_landmark(const TLandmark1* landmark, TPointF* dst, 
	int count, float a, float b, float tx, float ty);

void sim_transform_image(const unsigned char* gray, int width, int height, int pitch,
	unsigned char* dst, int width1, int height1,float a, float b, float tx, float ty);

cv::Mat sim_transform_image_1channel(cv::Mat img, int left_eye_x, 
					int left_eye_y, int right_eye_x, int right_eye_y);

cv::Mat sim_transform_image_3channels(cv::Mat img, int left_eye_x, 
					int left_eye_y, int right_eye_x, int right_eye_y);
