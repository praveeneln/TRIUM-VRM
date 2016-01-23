#ifndef CAMERA_PARAMS_H_INCLUDED
#define CAMERA_PARAMS_H_INCLUDED

#include <NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif

#define CAMERAP_MIRROR_HORIZONTAL  10200
#define CAMERAP_MIRROR_VERTICAL    10201

#define CAMERAP_AUTOMATIC_SETTINGS 10301

#define CAMERAP_GAIN               10410
#define CAMERAP_GAIN_MIN           10411
#define CAMERAP_GAIN_MAX           10412

#define CAMERAP_EXPOSURE           10420
#define CAMERAP_EXPOSURE_MIN       10421
#define CAMERAP_EXPOSURE_MAX       10422

#define CAMERAP_IP_USERNAME        10501
#define CAMERAP_IP_PASSWORD        10502
#define CAMERAP_IP_CHANNEL_ID      10503
#define CAMERAP_IP_CHANNEL_NAME    10504

#define CAMERAP_VIDEO_FILE_NAME    10601
#define CAMERAP_VIDEO_DROP_FRAMES  10602

#ifdef N_CPP
}
#endif

#endif // !CAMERA_PARAMS_H_INCLUDED
