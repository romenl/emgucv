//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2018 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_TRACKING_C_H
#define EMGU_TRACKING_C_H

#include "opencv2/core/core_c.h"
#include "opencv2/tracking/tracking.hpp"

//CVAPI(cv::Tracker*) cveTrackerCreate(cv::String* trackerType);
CVAPI(bool) cveTrackerInit(cv::Tracker* tracker, cv::Mat* image, CvRect* boundingBox);
CVAPI(bool) cveTrackerUpdate(cv::Tracker* tracker, cv::Mat* image, CvRect* boundingBox);
//CVAPI(void) cveTrackerRelease(cv::Tracker** tracker);

CVAPI(cv::TrackerBoosting*) cveTrackerBoostingCreate(int numClassifiers, float samplerOverlap, float samplerSearchFactor, int iterationInit, int featureSetNumFeatures, cv::Tracker** tracker);
CVAPI(void) cveTrackerBoostingRelease(cv::TrackerBoosting** tracker);

CVAPI(cv::TrackerMedianFlow*) cveTrackerMedianFlowCreate(int pointsInGrid, CvSize* winSize, int maxLevel, CvTermCriteria* termCriteria, CvSize* winSizeNCC, double maxMedianLengthOfDisplacementDifference, cv::Tracker** tracker);
CVAPI(void) cveTrackerMedianFlowRelease(cv::TrackerMedianFlow** tracker);

CVAPI(cv::TrackerMIL*) cveTrackerMILCreate(
	float samplerInitInRadius,
	int samplerInitMaxNegNum,
	float samplerSearchWinSize,
	float samplerTrackInRadius,
	int samplerTrackMaxPosNum,
	int samplerTrackMaxNegNum,
	int featureSetNumFeatures,
	cv::Tracker** tracker);
CVAPI(void) cveTrackerMILRelease(cv::TrackerMIL** tracker);

CVAPI(cv::TrackerTLD*) cveTrackerTLDCreate(cv::Tracker** tracker);
CVAPI(void) cveTrackerTLDRelease(cv::TrackerTLD** tracker);

CVAPI(cv::TrackerKCF*) cveTrackerKCFCreate(
	float detect_thresh,
	float sigma,
	float lambda,
	float interp_factor,
	float output_sigma_factor,
	float pca_learning_rate,
	bool resize,
	bool split_coeff,
	bool wrap_kernel,
	bool compress_feature,
	int max_patch_size,
	int compressed_size,
	int desc_pca,
	int desc_npca,
	cv::Tracker** tracker);
CVAPI(void) cveTrackerKCFRelease(cv::TrackerKCF** tracker);

CVAPI(cv::TrackerGOTURN*) cveTrackerGOTURNCreate(cv::Tracker** tracker);
CVAPI(void) cveTrackerGOTURNRelease(cv::TrackerGOTURN** tracker);

CVAPI(cv::TrackerMOSSE*) cveTrackerMOSSECreate(cv::Tracker** tracker);
CVAPI(void) cveTrackerMOSSERelease(cv::TrackerMOSSE** tracker);

CVAPI(cv::MultiTracker*) cveMultiTrackerCreate();
CVAPI(bool) cveMultiTrackerAdd(cv::MultiTracker* multiTracker, cv::Tracker* tracker, cv::_InputArray* image, CvRect* boundingBox);
CVAPI(bool) cveMultiTrackerUpdate(cv::MultiTracker* tracker, cv::Mat* image, std::vector<CvRect>* boundingBox);
CVAPI(void) cveMultiTrackerRelease(cv::MultiTracker** tracker);


CVAPI(cv::TrackerCSRT*) cveTrackerCSRTCreate(
	bool use_hog,
	bool use_color_names,
	bool use_gray,
	bool use_rgb,
	bool use_channel_weights,
	bool use_segmentation,
	cv::String* window_function, 
	float kaiser_alpha,
	float cheb_attenuation,
	float template_size,
	float gsl_sigma,
	float hog_orientations,
	float hog_clip,
	float padding,
	float filter_lr,
	float weights_lr,
	int num_hog_channels_used,
	int admm_iterations,
	int histogram_bins,
	float histogram_lr,
	int background_ratio,
	int number_of_scales,
	float scale_sigma_factor,
	float scale_model_max_area,
	float scale_lr,
	float scale_step,
	cv::Tracker** tracker);
CVAPI(void) cveTrackerCSRTRelease(cv::TrackerCSRT** tracker);

#endif