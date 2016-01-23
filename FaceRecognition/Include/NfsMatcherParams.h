#ifndef NFS_MATCHER_PARAMS_H_INCLUDED
#define NFS_MATCHER_PARAMS_H_INCLUDED

#include <NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NFSM_PART_NONE 0
#define NFSM_PART_NFM  1

#define NFSMP_MATCHING_THRESHOLD 100

#define NFSMP_MIN_MATCHED_FINGER_COUNT           201
#define NFSMP_MIN_MATCHED_FINGER_COUNT_THRESHOLD 202

#ifdef N_CPP
}
#endif

#endif // !NFS_MATCHER_PARAMS_H_INCLUDED
