/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pstates_table.h $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_pstates_table.h
/// @brief Definition of generated pstate tables written to HOMER PPMR
///
// *HWP HW Owner        : Rahul Batra <rbatra@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP FW Owner        : Martha Broyles <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE:HS

#ifndef __P9_PSTATES_TABLE_H__
#define __P9_PSTATES_TABLE_H__

#include <p9_pstates_common.h>
#include <p9_pstates_pgpe.h>
#include <p9_pstates_cmeqm.h>

/// Generated Pstate Table
///
/// This structure defines the Pstate Tables generated by PGPE Hcode upon
/// initialization.  This content depicts the values that will be computed
/// on the fly during Pstate protocol execution based on the Pstate Parameter
/// Block content.

#define MAX_PSTATE_TABLE_ENTRIES  128
#define GEN_PSTATES_TBL_MAGIC    0x50535441424c3030 //PSTABL00 (last two ASCII characters indicate version number)

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C" {
#endif

/// Pstate Table
///
/// This structure defines the Pstate Table content
/// -- 16B structure

typedef struct
{
    /// Pstate number
    Pstate      pstate;

    /// Assocated Frequency (in MHz)
    uint16_t    frequency_mhz;

    /// External VRM setpoint (in mV).  this directly translates to AVSBus value
    uint16_t    external_vdd_mv;

    /// Effective VDD voltage at the module pins.  This accounts for the system
    /// parameter effects.
    uint16_t    effective_vdd_mv;

    /// Minimum Effective Regulation Voltage (in mV) that supports iVRMs being
    /// enabled for this Pstate.  This is effective_vdd_mv + the iVRM dead zone
    /// (in mV) at this effective_vdd_mv point.
    uint16_t    effective_regulation_vdd_mv;

    /// Internal VDD voltage at the output of the PFET header
    uint16_t    internal_vdd_mv;

    /// Internal VDD Voltage Id.  Voltage is 512mV + internal_vid*4mV
    uint8_t    internal_vid;

    /// Voltage Droop Monitor (VDM) setting (in mV)
    uint8_t    vdm_mv;

    /// Voltage Droop Monitor (VDM) Voltage ID. Voltage is 512mV + vdm_vid*4mV
    uint8_t    vdm_vid;

    /// Voltage Droop Monitor (VDM) Thresholds
    /// Really 4 nibbles holding the encoded threshold value per VDM.
    /// @todo Blow this up for which VDM each of the nibbles controls and the
    /// encoding.
    uint16_t    vdm_thresholds;

} PstateTable;


typedef struct
{

    /// Magic Number
    uint64_t magic;   // ASCII: "PSTATABL"

    // PGPE content
    GlobalPstateParmBlock globalppb;

    /// The fastest frequency - after biases have been applied
    uint32_t pstate0_frequency_khz;

    /// Highest Pstate Number => slowest Pstate generated
    uint32_t highest_pstate;

    /// Generated table with system paramters included but without biases
    PstateTable raw_pstates[MAX_PSTATE_TABLE_ENTRIES];

    /// Generated table with system paramters and biases
    /// Note: if all bias attributes are 0, this content will be the same
    /// as the raw_pstates content.
    PstateTable biased_pstates[MAX_PSTATE_TABLE_ENTRIES];

    ///VPD Operating points generated after applying biases
    VpdOperatingPoint operating_points_biased[VPD_PV_POINTS];

    ///VPD Operating points generated after applying system parameters
    VpdOperatingPoint operating_points_sysp[VPD_PV_POINTS];

    ///VPD Operating points generated after applying system parameters and biases
    VpdOperatingPoint operating_points_biased_sysp[VPD_PV_POINTS];
} GeneratedPstateInfo;



#ifdef __cplusplus
} // end extern C
#endif
#endif    /* __ASSEMBLER__ */
#endif    /* __P9_PSTATES_TABLE_H__ */
