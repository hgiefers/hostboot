/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdSPDXRecordVersion.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///  @file getMBvpdSPDXRecordVersion.H
///  @brief MBVPD Accessor for providing the ATTR_VPD_VD_KEYWORD attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef _HWP_GETMBVPDSPDXVERSION_
#define _HWP_GETMBVPDSPDXVERSION_

#include <fapi2.H>
#define VD_KEYWORD_DEFAULT_VALUE 0x0000

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*getMBvpdSPDXRecordVersion_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&, uint32_t&);

extern "C"
{
///
/// @brief Get the ATTR_VPD_VD_KEYWORD FAPI attribute
/// @note Return the SPDX version from MBvpd record SPDX keyword VD.
///
/// The ATTR_VPD_VD_KEYWORD attribute is associated with a DIMM. The platfrom must
/// get the associated MemBuff chip to be passed to this hwp accessor.
///
/// @param[in]  i_mbTarget - Reference to membuf Target
/// @param[out] o_val      - Filled in with vpd version
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdSPDXRecordVersion(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        uint32_t& o_val);
}

#endif
