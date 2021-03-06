﻿using cv::Point;
 using cv::Mat;
 
 /**
 * 功能：模板匹配函数
 * 输入：
 *   1）image 待匹配的图像
 *   2）templ 用于匹配的模板
 *   3）method 匹配方法，可选值有：
 *      TM_CCOEFF, TM_CCOEFF_NORMED, TM_CCORR, 
 *      TM_CCORR_NORMED, TM_SQDIFF, TM_SQDIFF_NORMED
 * 输出：
 *   matchLocation 最佳匹配点的坐标
 */
Point tempMatch(Mat &image, Mat &templ, int method)
{
	cv::Mat matchResult; //存放匹配结果
	cv::matchTemplate(image, templ, matchResult, method);

	//获取最佳匹配点
	double minValue; double maxValue; 
	cv::Point minLocation; cv::Point maxLocation;
	cv::minMaxLoc(matchResult, &minValue, &maxValue, &minLocation, &maxLocation, Mat());
	
	//返回最佳匹配点
	Point matchLocation;
	if (method == TM_SQDIFF || method == TM_SQDIFF_NORMED)
		matchLocation = minLocation;
	else
		matchLocation = maxLocation;
	return matchLocation;
}
