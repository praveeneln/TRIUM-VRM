#ifndef NTFI_H_INCLUDED
#define NTFI_H_INCLUDED

#include <NCore.h>
#include <NImage.h>
#include <NGeometry.h>
#include <NBiometrics.h>
#include <NtfiParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NtfiAttributes, NObject)

NResult N_API NtfiAttributesGetSharpness(HNtfiAttributes hNtfiAttributes, NDouble * pValue);
NResult N_API NtfiAttributesGetBackgroundUniformity(HNtfiAttributes hNtfiAttributes, NDouble * pValue);
NResult N_API NtfiAttributesGetGrayscaleDensity(HNtfiAttributes hNtfiAttributes, NDouble * pValue);

N_DECLARE_OBJECT_TYPE(Ntfi, NObject)

NResult N_API NtfiCreate(HNtfi * phNtfi);

N_DEPRECATED("function is deprecated, use NtfiCreateTokenFaceImageEx instead")
NResult N_API NtfiCreateTokenFaceImage(HNtfi hNtfi, HNImage hImage, struct NPoint_ firstEye, struct NPoint_ secondEye, HNImage * phTokenFaceImage);
NResult N_API NtfiCreateTokenFaceImageEx(HNtfi hNtfi, HNImage hImage, const struct NPoint_ * pFirstEye, const struct NPoint_ * pSecondEye, HNImage * phTokenFaceImage);
NResult N_API NtfiTestTokenFaceImage(HNtfi hNtfi, HNImage hTokenFaceImage, HNtfiAttributes * phNtfiAttributes, NDouble * pScore);

#ifdef N_CPP
}
#endif

#endif // !NTFI_H_INCLUDED
