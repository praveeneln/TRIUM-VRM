#ifndef NE_SEGMENTER_PARAMS_HPP_INCLUDED
#define NE_SEGMENTER_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics { namespace Tools
{
#include <NESegmenterParams.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Tools
{
#undef NESP_HORIZONTAL_MARGIN
#undef NESP_VERTICAL_MARGIN
#undef NESP_UPPER_EYELID_MASK_VALUE
#undef NESP_SCLERA_MASK_VALUE
#undef NESP_LOWER_EYELID_MASK_VALUE

#undef NESP_QUALITY_THRESHOLD
#undef NESP_GRAY_LEVEL_SPREAD_THRESHOLD
#undef NESP_IRIS_SIZE_THRESHOLD
#undef NESP_PUPIL_IRIS_RATIO_THRESHOLD
#undef NESP_USABLE_IRIS_AREA_THRESHOLD
#undef NESP_IRIS_SCLERA_CONTRAST_THRESHOLD
#undef NESP_IRIS_PUPIL_CONTRAST_THRESHOLD
#undef NESP_IRIS_SCLERA_BOUNDARY_SHAPE_THRESHOLD
#undef NESP_IRIS_PUPIL_BOUNDARY_SHAPE_THRESHOLD
#undef NESP_MARGIN_THRESHOLD
#undef NESP_SHARPNESS_THRESHOLD
#undef NESP_SIGNAL_TO_NOISE_RATIO_THRESHOLD
#undef NESP_INTERLACE_THRESHOLD

const NUShort NESP_HORIZONTAL_MARGIN       = 10001;
const NUShort NESP_VERTICAL_MARGIN         = 10002;
const NUShort NESP_UPPER_EYELID_MASK_VALUE = 10011;
const NUShort NESP_SCLERA_MASK_VALUE       = 10012;
const NUShort NESP_LOWER_EYELID_MASK_VALUE = 10013;

const NUShort NESP_QUALITY_THRESHOLD                    = 20001;
const NUShort NESP_GRAY_LEVEL_SPREAD_THRESHOLD          = 20002;
const NUShort NESP_IRIS_SIZE_THRESHOLD                  = 20003;
const NUShort NESP_PUPIL_IRIS_RATIO_THRESHOLD           = 20004;
const NUShort NESP_USABLE_IRIS_AREA_THRESHOLD           = 20005;
const NUShort NESP_IRIS_SCLERA_CONTRAST_THRESHOLD       = 20006;
const NUShort NESP_IRIS_PUPIL_CONTRAST_THRESHOLD        = 20007;
const NUShort NESP_IRIS_SCLERA_BOUNDARY_SHAPE_THRESHOLD = 20008;
const NUShort NESP_IRIS_PUPIL_BOUNDARY_SHAPE_THRESHOLD  = 20009;
const NUShort NESP_MARGIN_THRESHOLD                     = 20010;
const NUShort NESP_SHARPNESS_THRESHOLD                  = 20011;
const NUShort NESP_SIGNAL_TO_NOISE_RATIO_THRESHOLD      = 20013;
const NUShort NESP_INTERLACE_THRESHOLD                  = 20017;
}}}

#endif // !NE_SEGMENTER_PARAMS_HPP_INCLUDED
