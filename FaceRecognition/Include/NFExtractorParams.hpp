#ifndef NF_EXTRACTOR_PARAMS_HPP_INCLUDED
#define NF_EXTRACTOR_PARAMS_HPP_INCLUDED

#include <NParameters.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NFExtractorParams.h>
}}

namespace Neurotec { namespace Biometrics
{
#undef NFEP_TEMPLATE_SIZE
#undef NFEP_EXTRACT_QUALITIES
#undef NFEP_EXTRACT_CURVATURES
#undef NFEP_EXTRACT_GS
#undef NFEP_MIN_MINUTIA_COUNT
#undef NFEP_EXTRACTED_RIDGE_COUNTS
#undef NFEP_RETURNED_IMAGE
#undef NFEP_USE_QUALITY
#undef NFEP_QUALITY_THRESHOLD
#undef NFEP_GENERALIZATION_THRESHOLD
#undef NFEP_GENERALIZATION_MAXIMAL_ROTATION
#undef NFEP_GENERALIZATION_MIN_MINUTIA_COUNT
#undef NFEP_MODE

#undef NFE_MODE_GENERAL
#undef NFE_MODE_DIGITALPERSONA_UAREU
#undef NFE_MODE_BIOMETRIKA_FX2000
#undef NFE_MODE_BIOMETRIKA_FX3000
#undef NFE_MODE_KEYTRONIC_SECUREDESKTOP
#undef NFE_MODE_IDENTIX_TOUCHVIEW
#undef NFE_MODE_IDENTIX_DFR2090
#undef NFE_MODE_PRECISEBIOMETRICS_100CS
#undef NFE_MODE_UPEK_TOUCHCHIP
#undef NFE_MODE_IDENTICATORTECHNOLOGY_DF90
#undef NFE_MODE_AUTHENTEC_AFS2
#undef NFE_MODE_AUTHENTEC_AES4000
#undef NFE_MODE_AUTHENTEC_AES2501B
#undef NFE_MODE_ATMEL_FINGERCHIP
#undef NFE_MODE_BMF_BLP100
#undef NFE_MODE_SECUGEN_HAMSTER
#undef NFE_MODE_ETHENTICA
#undef NFE_MODE_CROSSMATCH_VERIFIER300
#undef NFE_MODE_NITGEN_FINGKEY_HAMSTER
#undef NFE_MODE_TESTECH_BIOI
#undef NFE_MODE_DIGENT_IZZIX
#undef NFE_MODE_STARTEK_FM200
#undef NFE_MODE_FUJITSU_MBF200
#undef NFE_MODE_FUTRONIC_FS80
#undef NFE_MODE_LIGHTUNING_LTTC500
#undef NFE_MODE_TACOMA_CMOS

const NUShort NFEP_TEMPLATE_SIZE = 100;
const NUShort NFEP_EXTRACT_QUALITIES = 111;
const NUShort NFEP_EXTRACT_CURVATURES = 112;
const NUShort NFEP_EXTRACT_GS = 113;
const NUShort NFEP_MIN_MINUTIA_COUNT = 119;
const NUShort NFEP_EXTRACTED_RIDGE_COUNTS = 120;
const NUShort NFEP_RETURNED_IMAGE = 190;
const NUShort NFEP_USE_QUALITY = 900;
const NUShort NFEP_QUALITY_THRESHOLD = 910;
const NUShort NFEP_GENERALIZATION_THRESHOLD = 300;
const NUShort NFEP_GENERALIZATION_MAXIMAL_ROTATION = 301;
const NUShort NFEP_GENERALIZATION_MIN_MINUTIA_COUNT = 319;
const NUShort NFEP_MODE = 1000;

const NInt NFE_MODE_GENERAL = 0;
const NInt NFE_MODE_DIGITALPERSONA_UAREU = 100;
const NInt NFE_MODE_BIOMETRIKA_FX2000 = 200;
const NInt NFE_MODE_BIOMETRIKA_FX3000 = 201;
const NInt NFE_MODE_KEYTRONIC_SECUREDESKTOP = 300;
const NInt NFE_MODE_IDENTIX_TOUCHVIEW = 400;
const NInt NFE_MODE_IDENTIX_DFR2090 = 401;
const NInt NFE_MODE_PRECISEBIOMETRICS_100CS = 500;
const NInt NFE_MODE_UPEK_TOUCHCHIP = 600;
const NInt NFE_MODE_IDENTICATORTECHNOLOGY_DF90 = 700;
const NInt NFE_MODE_AUTHENTEC_AFS2 = 800;
const NInt NFE_MODE_AUTHENTEC_AES4000 = 810;
const NInt NFE_MODE_AUTHENTEC_AES2501B = 811;
const NInt NFE_MODE_ATMEL_FINGERCHIP = 900;
const NInt NFE_MODE_BMF_BLP100 = 1000;
const NInt NFE_MODE_SECUGEN_HAMSTER = 1100;
const NInt NFE_MODE_ETHENTICA = 1200;
const NInt NFE_MODE_CROSSMATCH_VERIFIER300 = 1300;
const NInt NFE_MODE_NITGEN_FINGKEY_HAMSTER = 1400;
const NInt NFE_MODE_TESTECH_BIOI = 1500;
const NInt NFE_MODE_DIGENT_IZZIX = 1600;
const NInt NFE_MODE_STARTEK_FM200 = 1700;
const NInt NFE_MODE_FUJITSU_MBF200 = 1800;
const NInt NFE_MODE_FUTRONIC_FS80 = 1900;
const NInt NFE_MODE_LIGHTUNING_LTTC500 = 2000;
const NInt NFE_MODE_TACOMA_CMOS = 2100;
}}

#endif // !NF_EXTRACTOR_PARAMS_HPP_INCLUDED
