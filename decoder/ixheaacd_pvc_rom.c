/******************************************************************************
 *                                                                            *
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *****************************************************************************
 * Originally developed and contributed by Ittiam Systems Pvt. Ltd, Bangalore
*/
#include <ixheaacd_type_def.h>
#include "ixheaacd_sbr_const.h"
#include "ixheaacd_pvc_dec.h"

const FLOAT32 ixheaacd_pvc_smoothing_wind_tab_ns4[4] = {
    2.9233807677393114e-001f, 2.8099141963307617e-001f,
    2.4582604080136389e-001f, 1.8084446279162875e-001f};
const FLOAT32 ixheaacd_pvc_smoothing_wind_tab_ns16[16] = {
    7.9120074720078801e-002f, 7.8929352455315405e-002f,
    7.8356252741836802e-002f, 7.7397889626247995e-002f,
    7.6049149540866515e-002f, 7.4302186813164264e-002f,
    7.2145604983589517e-002f, 6.9563171210312247e-002f,
    6.6531787206720316e-002f, 6.3018197524834882e-002f,
    5.8973400826190611e-002f, 5.4322528277253423e-002f,
    4.8944795582858927e-002f, 4.2628371779453236e-002f,
    3.4946569619925177e-002f, 2.4770667091351901e-002f};

const FLOAT32 ixheaacd_pvc_smoothing_wind_tab_ns3[3] = {
    3.7911649807579761e-001f, 3.5280765527510910e-001f,
    2.6807584664909323e-001f};
const FLOAT32 ixheaacd_pvc_smoothing_wind_tab_ns12[12] = {
    1.0440702692045410e-001f, 1.0395945931915132e-001f,
    1.0261281883061703e-001f, 1.0035462721037963e-001f,
    9.7161686576578310e-002f, 9.2995740369570576e-002f,
    8.7795494664707929e-002f, 8.1461666975864891e-002f,
    7.3826916738979523e-002f, 6.4587661325082549e-002f,
    5.3116303570036522e-002f, 3.7720597498577493e-002f};

const UWORD8 ixheaacd_pred_coeff_pvc_id_boundaries_1[PVC_ID_NUM_GROUPS - 1] = {
    17, 68};

const FLOAT32 ixheaacd_q_factor_table_mode_1[PVC_NB_LOW + 1] = {
    1.0 / 256.0, 1.0 / 256.0, 1.0 / 128.0, 1.0 / 2.0};

const WORD8 ixheaacd_pred_coeff_table_1_mode_1
    [PVC_ID_NUM_GROUPS][PVC_NB_LOW][PVC_NB_HIGH_MODE1] = {
        {{(WORD8)0x4F, (WORD8)0x5B, (WORD8)0x57, (WORD8)0x52, (WORD8)0x4D,
          (WORD8)0x65, (WORD8)0x45, (WORD8)0x57},
         {(WORD8)0xF3, (WORD8)0x0F, (WORD8)0x18, (WORD8)0x20, (WORD8)0x19,
          (WORD8)0x4F, (WORD8)0x3D, (WORD8)0x23},
         {(WORD8)0x78, (WORD8)0x57, (WORD8)0x55, (WORD8)0x50, (WORD8)0x50,
          (WORD8)0x20, (WORD8)0x36, (WORD8)0x37}},
        {{(WORD8)0x4C, (WORD8)0x5F, (WORD8)0x53, (WORD8)0x37, (WORD8)0x1E,
          (WORD8)0xFD, (WORD8)0x15, (WORD8)0x0A},
         {(WORD8)0x05, (WORD8)0x0E, (WORD8)0x28, (WORD8)0x41, (WORD8)0x48,
          (WORD8)0x6E, (WORD8)0x54, (WORD8)0x5B},
         {(WORD8)0x59, (WORD8)0x47, (WORD8)0x40, (WORD8)0x40, (WORD8)0x3D,
          (WORD8)0x33, (WORD8)0x3F, (WORD8)0x39}},
        {{(WORD8)0x47, (WORD8)0x5F, (WORD8)0x57, (WORD8)0x34, (WORD8)0x3C,
          (WORD8)0x2E, (WORD8)0x2E, (WORD8)0x31},
         {(WORD8)0xFA, (WORD8)0x13, (WORD8)0x23, (WORD8)0x4E, (WORD8)0x44,
          (WORD8)0x7C, (WORD8)0x34, (WORD8)0x38},
         {(WORD8)0x63, (WORD8)0x43, (WORD8)0x41, (WORD8)0x3D, (WORD8)0x35,
          (WORD8)0x19, (WORD8)0x3D, (WORD8)0x33}}};

const WORD8 ixheaacd_pred_coeff_table_2_mode_1[PVC_NB_HIGH][PVC_NB_HIGH_MODE1] =
    {{(WORD8)0xCB, (WORD8)0xD1, (WORD8)0xCC, (WORD8)0xD2, (WORD8)0xE2,
      (WORD8)0xEB, (WORD8)0xE7, (WORD8)0xE8},
     {(WORD8)0x80, (WORD8)0x80, (WORD8)0x80, (WORD8)0x80, (WORD8)0x80,
      (WORD8)0x80, (WORD8)0x80, (WORD8)0x80},
     {(WORD8)0x84, (WORD8)0x8C, (WORD8)0x88, (WORD8)0x83, (WORD8)0x90,
      (WORD8)0x93, (WORD8)0x86, (WORD8)0x80},
     {(WORD8)0xD7, (WORD8)0xD8, (WORD8)0xC0, (WORD8)0xC7, (WORD8)0xCF,
      (WORD8)0xE5, (WORD8)0xF1, (WORD8)0xF6},
     {(WORD8)0xA5, (WORD8)0xA6, (WORD8)0xAA, (WORD8)0xA8, (WORD8)0xB0,
      (WORD8)0xB1, (WORD8)0xB8, (WORD8)0xB8},
     {(WORD8)0xD7, (WORD8)0xCB, (WORD8)0xC1, (WORD8)0xC3, (WORD8)0xC5,
      (WORD8)0xC9, (WORD8)0xC9, (WORD8)0xCE},
     {(WORD8)0xCA, (WORD8)0xB5, (WORD8)0xB8, (WORD8)0xB3, (WORD8)0xAC,
      (WORD8)0xB6, (WORD8)0xBB, (WORD8)0xB8},
     {(WORD8)0xC1, (WORD8)0xC4, (WORD8)0xC3, (WORD8)0xC5, (WORD8)0xC6,
      (WORD8)0xCA, (WORD8)0xCA, (WORD8)0xCB},
     {(WORD8)0xE0, (WORD8)0xE1, (WORD8)0xD8, (WORD8)0xCD, (WORD8)0xCB,
      (WORD8)0xCB, (WORD8)0xCE, (WORD8)0xCC},
     {(WORD8)0xDB, (WORD8)0xE1, (WORD8)0xDF, (WORD8)0xDB, (WORD8)0xDC,
      (WORD8)0xD9, (WORD8)0xD9, (WORD8)0xD6},
     {(WORD8)0xE0, (WORD8)0xDE, (WORD8)0xDD, (WORD8)0xDD, (WORD8)0xE0,
      (WORD8)0xE3, (WORD8)0xE5, (WORD8)0xE6},
     {(WORD8)0xCA, (WORD8)0xD2, (WORD8)0xCD, (WORD8)0xCE, (WORD8)0xD5,
      (WORD8)0xDB, (WORD8)0xD9, (WORD8)0xDB},
     {(WORD8)0xD2, (WORD8)0xE0, (WORD8)0xDB, (WORD8)0xD5, (WORD8)0xDB,
      (WORD8)0xDE, (WORD8)0xE3, (WORD8)0xE1},
     {(WORD8)0xE5, (WORD8)0xDB, (WORD8)0xD0, (WORD8)0xD2, (WORD8)0xD8,
      (WORD8)0xDD, (WORD8)0xDB, (WORD8)0xDD},
     {(WORD8)0xC0, (WORD8)0xB5, (WORD8)0xBF, (WORD8)0xDD, (WORD8)0xE3,
      (WORD8)0xDC, (WORD8)0xDC, (WORD8)0xE4},
     {(WORD8)0xDB, (WORD8)0xCE, (WORD8)0xC6, (WORD8)0xCF, (WORD8)0xCF,
      (WORD8)0xD1, (WORD8)0xD3, (WORD8)0xD4},
     {(WORD8)0xC9, (WORD8)0xD7, (WORD8)0xDA, (WORD8)0xE2, (WORD8)0xE9,
      (WORD8)0xE7, (WORD8)0xDF, (WORD8)0xDC},
     {(WORD8)0x0A, (WORD8)0x07, (WORD8)0x0A, (WORD8)0x08, (WORD8)0x19,
      (WORD8)0x24, (WORD8)0x1F, (WORD8)0x22},
     {(WORD8)0x1E, (WORD8)0x1F, (WORD8)0x11, (WORD8)0x0E, (WORD8)0x22,
      (WORD8)0x2D, (WORD8)0x33, (WORD8)0x32},
     {(WORD8)0xF0, (WORD8)0xDA, (WORD8)0xDC, (WORD8)0x18, (WORD8)0x1F,
      (WORD8)0x19, (WORD8)0x0A, (WORD8)0x1E},
     {(WORD8)0x09, (WORD8)0xF8, (WORD8)0xE6, (WORD8)0x05, (WORD8)0x19,
      (WORD8)0x11, (WORD8)0x0E, (WORD8)0x0B},
     {(WORD8)0x09, (WORD8)0x10, (WORD8)0x0E, (WORD8)0xE6, (WORD8)0xF4,
      (WORD8)0x20, (WORD8)0x22, (WORD8)0xFA},
     {(WORD8)0xF2, (WORD8)0xE5, (WORD8)0xF8, (WORD8)0x0E, (WORD8)0x18,
      (WORD8)0x15, (WORD8)0x0D, (WORD8)0x10},
     {(WORD8)0x15, (WORD8)0x13, (WORD8)0x16, (WORD8)0x0A, (WORD8)0x0D,
      (WORD8)0x1F, (WORD8)0x1D, (WORD8)0x1B},
     {(WORD8)0xFA, (WORD8)0xFF, (WORD8)0xFE, (WORD8)0xFF, (WORD8)0x09,
      (WORD8)0x11, (WORD8)0x03, (WORD8)0x0B},
     {(WORD8)0xFE, (WORD8)0xFA, (WORD8)0xF2, (WORD8)0xF8, (WORD8)0x0C,
      (WORD8)0x1E, (WORD8)0x11, (WORD8)0x12},
     {(WORD8)0xFA, (WORD8)0xF8, (WORD8)0x0B, (WORD8)0x17, (WORD8)0x1D,
      (WORD8)0x17, (WORD8)0x0E, (WORD8)0x16},
     {(WORD8)0x00, (WORD8)0xF3, (WORD8)0xFD, (WORD8)0x0A, (WORD8)0x1C,
      (WORD8)0x17, (WORD8)0xFD, (WORD8)0x08},
     {(WORD8)0xEA, (WORD8)0xEA, (WORD8)0x03, (WORD8)0x12, (WORD8)0x1E,
      (WORD8)0x14, (WORD8)0x09, (WORD8)0x04},
     {(WORD8)0x02, (WORD8)0xFE, (WORD8)0x04, (WORD8)0xFB, (WORD8)0x0C,
      (WORD8)0x0E, (WORD8)0x07, (WORD8)0x02},
     {(WORD8)0xF6, (WORD8)0x02, (WORD8)0x07, (WORD8)0x0B, (WORD8)0x17,
      (WORD8)0x17, (WORD8)0x01, (WORD8)0xFF},
     {(WORD8)0xF5, (WORD8)0xFB, (WORD8)0xFE, (WORD8)0x04, (WORD8)0x12,
      (WORD8)0x14, (WORD8)0x0C, (WORD8)0x0D},
     {(WORD8)0x10, (WORD8)0x10, (WORD8)0x0E, (WORD8)0x04, (WORD8)0x07,
      (WORD8)0x11, (WORD8)0x0F, (WORD8)0x13},
     {(WORD8)0x0C, (WORD8)0x0F, (WORD8)0xFB, (WORD8)0xF2, (WORD8)0x0A,
      (WORD8)0x12, (WORD8)0x09, (WORD8)0x0D},
     {(WORD8)0x0D, (WORD8)0x1D, (WORD8)0xF1, (WORD8)0xF4, (WORD8)0x2A,
      (WORD8)0x06, (WORD8)0x3B, (WORD8)0x32},
     {(WORD8)0xFC, (WORD8)0x08, (WORD8)0x06, (WORD8)0x02, (WORD8)0x0E,
      (WORD8)0x17, (WORD8)0x08, (WORD8)0x0E},
     {(WORD8)0x07, (WORD8)0x02, (WORD8)0xEE, (WORD8)0xEE, (WORD8)0x2B,
      (WORD8)0xF6, (WORD8)0x23, (WORD8)0x13},
     {(WORD8)0x04, (WORD8)0x02, (WORD8)0x05, (WORD8)0x08, (WORD8)0x0B,
      (WORD8)0x0E, (WORD8)0xFB, (WORD8)0xFB},
     {(WORD8)0x00, (WORD8)0x04, (WORD8)0x10, (WORD8)0x18, (WORD8)0x22,
      (WORD8)0x25, (WORD8)0x1D, (WORD8)0x1F},
     {(WORD8)0xFB, (WORD8)0x0D, (WORD8)0x07, (WORD8)0x00, (WORD8)0x0C,
      (WORD8)0x0F, (WORD8)0xFC, (WORD8)0x02},
     {(WORD8)0x00, (WORD8)0x00, (WORD8)0x00, (WORD8)0x01, (WORD8)0x05,
      (WORD8)0x07, (WORD8)0x03, (WORD8)0x05},
     {(WORD8)0x04, (WORD8)0x05, (WORD8)0x08, (WORD8)0x13, (WORD8)0xFF,
      (WORD8)0xEB, (WORD8)0x0C, (WORD8)0x06},
     {(WORD8)0x05, (WORD8)0x13, (WORD8)0x0E, (WORD8)0x0B, (WORD8)0x12,
      (WORD8)0x15, (WORD8)0x09, (WORD8)0x0A},
     {(WORD8)0x09, (WORD8)0x03, (WORD8)0x09, (WORD8)0x05, (WORD8)0x12,
      (WORD8)0x16, (WORD8)0x11, (WORD8)0x12},
     {(WORD8)0x14, (WORD8)0x1A, (WORD8)0x06, (WORD8)0x01, (WORD8)0x10,
      (WORD8)0x11, (WORD8)0xFE, (WORD8)0x02},
     {(WORD8)0x01, (WORD8)0x0B, (WORD8)0x0B, (WORD8)0x0C, (WORD8)0x18,
      (WORD8)0x21, (WORD8)0x10, (WORD8)0x13},
     {(WORD8)0x12, (WORD8)0x0D, (WORD8)0x0A, (WORD8)0x10, (WORD8)0x1C,
      (WORD8)0x1D, (WORD8)0x0D, (WORD8)0x10},
     {(WORD8)0x03, (WORD8)0x09, (WORD8)0x14, (WORD8)0x15, (WORD8)0x1B,
      (WORD8)0x1A, (WORD8)0x01, (WORD8)0xFF},
     {(WORD8)0x08, (WORD8)0x12, (WORD8)0x13, (WORD8)0x0E, (WORD8)0x16,
      (WORD8)0x1D, (WORD8)0x14, (WORD8)0x1B},
     {(WORD8)0x07, (WORD8)0x15, (WORD8)0x1C, (WORD8)0x1B, (WORD8)0x20,
      (WORD8)0x21, (WORD8)0x11, (WORD8)0x0E},
     {(WORD8)0x12, (WORD8)0x18, (WORD8)0x19, (WORD8)0x17, (WORD8)0x20,
      (WORD8)0x25, (WORD8)0x1A, (WORD8)0x1E},
     {(WORD8)0x0C, (WORD8)0x1A, (WORD8)0x1D, (WORD8)0x22, (WORD8)0x2F,
      (WORD8)0x33, (WORD8)0x27, (WORD8)0x28},
     {(WORD8)0x0E, (WORD8)0x1A, (WORD8)0x17, (WORD8)0x10, (WORD8)0x0A,
      (WORD8)0x0E, (WORD8)0xFF, (WORD8)0x06},
     {(WORD8)0x1A, (WORD8)0x1C, (WORD8)0x18, (WORD8)0x14, (WORD8)0x1A,
      (WORD8)0x16, (WORD8)0x0A, (WORD8)0x0E},
     {(WORD8)0x1E, (WORD8)0x27, (WORD8)0x25, (WORD8)0x26, (WORD8)0x27,
      (WORD8)0x2A, (WORD8)0x21, (WORD8)0x21},
     {(WORD8)0xF1, (WORD8)0x0A, (WORD8)0x16, (WORD8)0x1C, (WORD8)0x28,
      (WORD8)0x25, (WORD8)0x15, (WORD8)0x19},
     {(WORD8)0x08, (WORD8)0x12, (WORD8)0x09, (WORD8)0x08, (WORD8)0x16,
      (WORD8)0x17, (WORD8)0xEF, (WORD8)0xF6},
     {(WORD8)0x0C, (WORD8)0x0B, (WORD8)0x00, (WORD8)0xFC, (WORD8)0x04,
      (WORD8)0x09, (WORD8)0xFC, (WORD8)0x03},
     {(WORD8)0xFB, (WORD8)0xF1, (WORD8)0xF8, (WORD8)0x26, (WORD8)0x24,
      (WORD8)0x18, (WORD8)0x1D, (WORD8)0x20},
     {(WORD8)0xF9, (WORD8)0x01, (WORD8)0x0C, (WORD8)0x0F, (WORD8)0x07,
      (WORD8)0x08, (WORD8)0x06, (WORD8)0x07},
     {(WORD8)0x07, (WORD8)0x06, (WORD8)0x08, (WORD8)0x04, (WORD8)0x07,
      (WORD8)0x0D, (WORD8)0x07, (WORD8)0x09},
     {(WORD8)0xFE, (WORD8)0x01, (WORD8)0x06, (WORD8)0x05, (WORD8)0x13,
      (WORD8)0x1B, (WORD8)0x14, (WORD8)0x19},
     {(WORD8)0x09, (WORD8)0x0C, (WORD8)0x0E, (WORD8)0x01, (WORD8)0x08,
      (WORD8)0x05, (WORD8)0xFB, (WORD8)0xFD},
     {(WORD8)0x07, (WORD8)0x06, (WORD8)0x03, (WORD8)0x0A, (WORD8)0x16,
      (WORD8)0x12, (WORD8)0x04, (WORD8)0x07},
     {(WORD8)0x04, (WORD8)0x01, (WORD8)0x00, (WORD8)0x04, (WORD8)0x1F,
      (WORD8)0x20, (WORD8)0x0E, (WORD8)0x0A},
     {(WORD8)0x03, (WORD8)0xFF, (WORD8)0xF6, (WORD8)0xFB, (WORD8)0x15,
      (WORD8)0x1A, (WORD8)0x00, (WORD8)0x03},
     {(WORD8)0xFC, (WORD8)0x18, (WORD8)0x0B, (WORD8)0x2D, (WORD8)0x35,
      (WORD8)0x23, (WORD8)0x12, (WORD8)0x09},
     {(WORD8)0x02, (WORD8)0xFE, (WORD8)0x01, (WORD8)0xFF, (WORD8)0x0C,
      (WORD8)0x11, (WORD8)0x0D, (WORD8)0x0F},
     {(WORD8)0xFA, (WORD8)0xE9, (WORD8)0xD9, (WORD8)0xFF, (WORD8)0x0D,
      (WORD8)0x05, (WORD8)0x0D, (WORD8)0x10},
     {(WORD8)0xF1, (WORD8)0xE0, (WORD8)0xF0, (WORD8)0x01, (WORD8)0x06,
      (WORD8)0x06, (WORD8)0x06, (WORD8)0x10},
     {(WORD8)0xE9, (WORD8)0xD4, (WORD8)0xD7, (WORD8)0x0F, (WORD8)0x14,
      (WORD8)0x0B, (WORD8)0x0D, (WORD8)0x16},
     {(WORD8)0x00, (WORD8)0xFF, (WORD8)0xEE, (WORD8)0xE5, (WORD8)0xFF,
      (WORD8)0x08, (WORD8)0x02, (WORD8)0xF9},
     {(WORD8)0xE0, (WORD8)0xDA, (WORD8)0xE5, (WORD8)0xFE, (WORD8)0x09,
      (WORD8)0x02, (WORD8)0xF9, (WORD8)0x04},
     {(WORD8)0xE0, (WORD8)0xE2, (WORD8)0xF4, (WORD8)0x09, (WORD8)0x13,
      (WORD8)0x0C, (WORD8)0x0D, (WORD8)0x09},
     {(WORD8)0xFC, (WORD8)0x02, (WORD8)0x04, (WORD8)0xFF, (WORD8)0x00,
      (WORD8)0xFF, (WORD8)0xF8, (WORD8)0xF7},
     {(WORD8)0xFE, (WORD8)0xFB, (WORD8)0xED, (WORD8)0xF2, (WORD8)0xFE,
      (WORD8)0xFE, (WORD8)0x08, (WORD8)0x0C},
     {(WORD8)0xF3, (WORD8)0xEF, (WORD8)0xD0, (WORD8)0xE3, (WORD8)0x05,
      (WORD8)0x11, (WORD8)0xFD, (WORD8)0xFF},
     {(WORD8)0xFA, (WORD8)0xEF, (WORD8)0xEA, (WORD8)0xFE, (WORD8)0x0D,
      (WORD8)0x0E, (WORD8)0xFE, (WORD8)0x02},
     {(WORD8)0xF7, (WORD8)0xFB, (WORD8)0xDB, (WORD8)0xDF, (WORD8)0x14,
      (WORD8)0xDD, (WORD8)0x07, (WORD8)0xFE},
     {(WORD8)0xFE, (WORD8)0x08, (WORD8)0x00, (WORD8)0xDB, (WORD8)0xE5,
      (WORD8)0x1A, (WORD8)0x13, (WORD8)0xED},
     {(WORD8)0xF9, (WORD8)0xFE, (WORD8)0xFF, (WORD8)0xF4, (WORD8)0xF3,
      (WORD8)0x00, (WORD8)0x05, (WORD8)0x02},
     {(WORD8)0xEF, (WORD8)0xDE, (WORD8)0xD8, (WORD8)0xEB, (WORD8)0xEA,
      (WORD8)0xF5, (WORD8)0x0E, (WORD8)0x19},
     {(WORD8)0xFB, (WORD8)0xFC, (WORD8)0xFA, (WORD8)0xEC, (WORD8)0xEB,
      (WORD8)0xED, (WORD8)0xEE, (WORD8)0xE8},
     {(WORD8)0xEE, (WORD8)0xFC, (WORD8)0xFD, (WORD8)0x00, (WORD8)0x04,
      (WORD8)0xFC, (WORD8)0xF0, (WORD8)0xF5},
     {(WORD8)0x00, (WORD8)0xFA, (WORD8)0xF4, (WORD8)0xF1, (WORD8)0xF5,
      (WORD8)0xFA, (WORD8)0xFB, (WORD8)0xF9},
     {(WORD8)0xEB, (WORD8)0xF0, (WORD8)0xDF, (WORD8)0xE3, (WORD8)0xEF,
      (WORD8)0x07, (WORD8)0x02, (WORD8)0x05},
     {(WORD8)0xF7, (WORD8)0xF0, (WORD8)0xE6, (WORD8)0xE7, (WORD8)0x06,
      (WORD8)0x15, (WORD8)0x06, (WORD8)0x0C},
     {(WORD8)0xF1, (WORD8)0xE4, (WORD8)0xD8, (WORD8)0xEA, (WORD8)0x06,
      (WORD8)0xF2, (WORD8)0x07, (WORD8)0x09},
     {(WORD8)0xFF, (WORD8)0xFE, (WORD8)0xFE, (WORD8)0xF9, (WORD8)0xFF,
      (WORD8)0xFF, (WORD8)0x02, (WORD8)0xF9},
     {(WORD8)0xDD, (WORD8)0xF4, (WORD8)0xF0, (WORD8)0xF1, (WORD8)0xFF,
      (WORD8)0xFF, (WORD8)0xEA, (WORD8)0xF1},
     {(WORD8)0xF0, (WORD8)0xF1, (WORD8)0xFD, (WORD8)0x03, (WORD8)0x03,
      (WORD8)0xFE, (WORD8)0x00, (WORD8)0x05},
     {(WORD8)0xF1, (WORD8)0xF6, (WORD8)0xE0, (WORD8)0xDF, (WORD8)0xF5,
      (WORD8)0x01, (WORD8)0xF4, (WORD8)0xF8},
     {(WORD8)0x02, (WORD8)0x03, (WORD8)0xE5, (WORD8)0xDC, (WORD8)0xE7,
      (WORD8)0xFD, (WORD8)0x02, (WORD8)0x08},
     {(WORD8)0xEC, (WORD8)0xF1, (WORD8)0xF5, (WORD8)0xEC, (WORD8)0xF2,
      (WORD8)0xF8, (WORD8)0xF6, (WORD8)0xEE},
     {(WORD8)0xF3, (WORD8)0xF4, (WORD8)0xF6, (WORD8)0xF4, (WORD8)0xF5,
      (WORD8)0xF1, (WORD8)0xE7, (WORD8)0xEA},
     {(WORD8)0xF7, (WORD8)0xF3, (WORD8)0xEC, (WORD8)0xEA, (WORD8)0xEF,
      (WORD8)0xF0, (WORD8)0xEE, (WORD8)0xF1},
     {(WORD8)0xEB, (WORD8)0xF6, (WORD8)0xFB, (WORD8)0xFA, (WORD8)0xEF,
      (WORD8)0xF3, (WORD8)0xF3, (WORD8)0xF7},
     {(WORD8)0x01, (WORD8)0x03, (WORD8)0xF1, (WORD8)0xF6, (WORD8)0x05,
      (WORD8)0xF8, (WORD8)0xE1, (WORD8)0xEB},
     {(WORD8)0xF5, (WORD8)0xF6, (WORD8)0xF6, (WORD8)0xF4, (WORD8)0xFB,
      (WORD8)0xFB, (WORD8)0xFF, (WORD8)0x00},
     {(WORD8)0xF8, (WORD8)0x01, (WORD8)0xFB, (WORD8)0xFA, (WORD8)0xFF,
      (WORD8)0x03, (WORD8)0xFE, (WORD8)0x04},
     {(WORD8)0x04, (WORD8)0xFB, (WORD8)0x03, (WORD8)0xFD, (WORD8)0xF5,
      (WORD8)0xF7, (WORD8)0xF6, (WORD8)0xFB},
     {(WORD8)0x06, (WORD8)0x09, (WORD8)0xFB, (WORD8)0xF4, (WORD8)0xF9,
      (WORD8)0xFA, (WORD8)0xFC, (WORD8)0xFF},
     {(WORD8)0xF5, (WORD8)0xF6, (WORD8)0xF1, (WORD8)0xEE, (WORD8)0xF5,
      (WORD8)0xF8, (WORD8)0xF5, (WORD8)0xF9},
     {(WORD8)0xF5, (WORD8)0xF9, (WORD8)0xFA, (WORD8)0xFC, (WORD8)0x07,
      (WORD8)0x09, (WORD8)0x01, (WORD8)0xFB},
     {(WORD8)0xD7, (WORD8)0xE9, (WORD8)0xE8, (WORD8)0xEC, (WORD8)0x00,
      (WORD8)0x0C, (WORD8)0xFE, (WORD8)0xF1},
     {(WORD8)0xEC, (WORD8)0x04, (WORD8)0xE9, (WORD8)0xDF, (WORD8)0x03,
      (WORD8)0xE8, (WORD8)0x00, (WORD8)0xFA},
     {(WORD8)0xE6, (WORD8)0xE2, (WORD8)0xFF, (WORD8)0x0A, (WORD8)0x13,
      (WORD8)0x01, (WORD8)0x00, (WORD8)0xF7},
     {(WORD8)0xF1, (WORD8)0xFA, (WORD8)0xF7, (WORD8)0xF5, (WORD8)0x01,
      (WORD8)0x06, (WORD8)0x05, (WORD8)0x0A},
     {(WORD8)0xF6, (WORD8)0xF6, (WORD8)0xFC, (WORD8)0xF6, (WORD8)0xE8,
      (WORD8)0x11, (WORD8)0xF2, (WORD8)0xFE},
     {(WORD8)0xFE, (WORD8)0x08, (WORD8)0x05, (WORD8)0x12, (WORD8)0xFD,
      (WORD8)0xD0, (WORD8)0x0E, (WORD8)0x07},
     {(WORD8)0xF1, (WORD8)0xFE, (WORD8)0xF7, (WORD8)0xF2, (WORD8)0xFB,
      (WORD8)0x02, (WORD8)0xFA, (WORD8)0xF8},
     {(WORD8)0xF4, (WORD8)0xEA, (WORD8)0xEC, (WORD8)0xF3, (WORD8)0xFE,
      (WORD8)0x01, (WORD8)0xF7, (WORD8)0xF6},
     {(WORD8)0xFF, (WORD8)0xFA, (WORD8)0xFB, (WORD8)0xF9, (WORD8)0xFF,
      (WORD8)0x01, (WORD8)0x04, (WORD8)0x03},
     {(WORD8)0x00, (WORD8)0xF9, (WORD8)0xF4, (WORD8)0xFC, (WORD8)0x05,
      (WORD8)0xFC, (WORD8)0xF7, (WORD8)0xFB},
     {(WORD8)0xF8, (WORD8)0xFF, (WORD8)0xEF, (WORD8)0xEC, (WORD8)0xFB,
      (WORD8)0x04, (WORD8)0xF8, (WORD8)0x03},
     {(WORD8)0xEB, (WORD8)0xF1, (WORD8)0xED, (WORD8)0xF4, (WORD8)0x02,
      (WORD8)0x0E, (WORD8)0x0B, (WORD8)0x04},
     {(WORD8)0xF7, (WORD8)0x01, (WORD8)0xF8, (WORD8)0xF4, (WORD8)0xF8,
      (WORD8)0xEF, (WORD8)0xF8, (WORD8)0x04},
     {(WORD8)0xEB, (WORD8)0xF0, (WORD8)0xF7, (WORD8)0xFC, (WORD8)0x10,
      (WORD8)0x0D, (WORD8)0xF8, (WORD8)0xF8},
     {(WORD8)0xE8, (WORD8)0xFE, (WORD8)0xEE, (WORD8)0xE8, (WORD8)0xED,
      (WORD8)0xF7, (WORD8)0xF5, (WORD8)0xF8},
     {(WORD8)0xED, (WORD8)0xEB, (WORD8)0xE9, (WORD8)0xEA, (WORD8)0xF2,
      (WORD8)0xF5, (WORD8)0xF4, (WORD8)0xF9},
     {(WORD8)0xEA, (WORD8)0xF2, (WORD8)0xEF, (WORD8)0xEE, (WORD8)0xF9,
      (WORD8)0xFE, (WORD8)0xFD, (WORD8)0x02},
     {(WORD8)0xFA, (WORD8)0xFD, (WORD8)0x02, (WORD8)0x0D, (WORD8)0xFA,
      (WORD8)0xE4, (WORD8)0x0F, (WORD8)0x01},
     {(WORD8)0xFF, (WORD8)0x08, (WORD8)0x05, (WORD8)0xF6, (WORD8)0xF7,
      (WORD8)0xFB, (WORD8)0xF1, (WORD8)0xF1},
     {(WORD8)0xF4, (WORD8)0xEC, (WORD8)0xEE, (WORD8)0xF6, (WORD8)0xEE,
      (WORD8)0xEE, (WORD8)0xF8, (WORD8)0x06},
     {(WORD8)0xE8, (WORD8)0xFA, (WORD8)0xF8, (WORD8)0xE8, (WORD8)0xF8,
      (WORD8)0xE9, (WORD8)0xEE, (WORD8)0xF9},
     {(WORD8)0xE5, (WORD8)0xE9, (WORD8)0xF0, (WORD8)0x00, (WORD8)0x00,
      (WORD8)0xEF, (WORD8)0xF3, (WORD8)0xF8},
     {(WORD8)0xF7, (WORD8)0xFB, (WORD8)0xFB, (WORD8)0xF7, (WORD8)0xF9,
      (WORD8)0xF9, (WORD8)0xF5, (WORD8)0xF0},
     {(WORD8)0xFD, (WORD8)0xFF, (WORD8)0xF2, (WORD8)0xEE, (WORD8)0xF2,
      (WORD8)0xF5, (WORD8)0xF1, (WORD8)0xF3}};

const UWORD8 ixheaacd_pred_coeff_pvc_id_boundaries_2[PVC_ID_NUM_GROUPS - 1] = {
    16, 52};

const FLOAT32 ixheaacd_q_factor_table_mode_2[PVC_NB_LOW + 1] = {
    1.0 / 128.0, 1.0 / 128.0, 1.0 / 64.0, 1.0 / 1.0};

const WORD8 ixheaacd_pred_coeff_table_1_mode_2
    [PVC_ID_NUM_GROUPS][PVC_NB_LOW][PVC_NB_HIGH_MODE2] = {
        {{(WORD8)0x11, (WORD8)0x27, (WORD8)0x0F, (WORD8)0xFD, (WORD8)0x04,
          (WORD8)0xFC},
         {(WORD8)0x00, (WORD8)0xBE, (WORD8)0xE3, (WORD8)0xF4, (WORD8)0xDB,
          (WORD8)0xF0},
         {(WORD8)0x09, (WORD8)0x1E, (WORD8)0x18, (WORD8)0x1A, (WORD8)0x21,
          (WORD8)0x1B}},
        {{(WORD8)0x16, (WORD8)0x28, (WORD8)0x2B, (WORD8)0x29, (WORD8)0x25,
          (WORD8)0x32},
         {(WORD8)0xF2, (WORD8)0xE9, (WORD8)0xE4, (WORD8)0xE5, (WORD8)0xE2,
          (WORD8)0xD4},
         {(WORD8)0x0E, (WORD8)0x0B, (WORD8)0x0C, (WORD8)0x0D, (WORD8)0x0D,
          (WORD8)0x0E}},
        {{(WORD8)0x2E, (WORD8)0x3C, (WORD8)0x20, (WORD8)0x16, (WORD8)0x1B,
          (WORD8)0x1A},
         {(WORD8)0xE4, (WORD8)0xC6, (WORD8)0xE5, (WORD8)0xF4, (WORD8)0xDC,
          (WORD8)0xDC},
         {(WORD8)0x0F, (WORD8)0x1B, (WORD8)0x18, (WORD8)0x14, (WORD8)0x1E,
          (WORD8)0x1A}}};

const WORD8 ixheaacd_pred_coeff_table_2_mode_2[PVC_NB_HIGH][PVC_NB_HIGH_MODE2] =
    {{(WORD8)0x26, (WORD8)0x25, (WORD8)0x11, (WORD8)0x0C, (WORD8)0xFA,
      (WORD8)0x15},
     {(WORD8)0x1B, (WORD8)0x18, (WORD8)0x11, (WORD8)0x0E, (WORD8)0x0E,
      (WORD8)0x0E},
     {(WORD8)0x12, (WORD8)0x10, (WORD8)0x10, (WORD8)0x10, (WORD8)0x11,
      (WORD8)0x10},
     {(WORD8)0x1E, (WORD8)0x24, (WORD8)0x19, (WORD8)0x15, (WORD8)0x14,
      (WORD8)0x12},
     {(WORD8)0x24, (WORD8)0x16, (WORD8)0x12, (WORD8)0x13, (WORD8)0x15,
      (WORD8)0x1C},
     {(WORD8)0xEA, (WORD8)0xED, (WORD8)0xEB, (WORD8)0xEA, (WORD8)0xEC,
      (WORD8)0xEB},
     {(WORD8)0xFC, (WORD8)0xFD, (WORD8)0xFD, (WORD8)0xFC, (WORD8)0xFE,
      (WORD8)0xFE},
     {(WORD8)0x0F, (WORD8)0x0C, (WORD8)0x0B, (WORD8)0x0A, (WORD8)0x0B,
      (WORD8)0x0B},
     {(WORD8)0x22, (WORD8)0x0B, (WORD8)0x16, (WORD8)0x18, (WORD8)0x13,
      (WORD8)0x19},
     {(WORD8)0x1C, (WORD8)0x14, (WORD8)0x1D, (WORD8)0x20, (WORD8)0x19,
      (WORD8)0x1A},
     {(WORD8)0x10, (WORD8)0x08, (WORD8)0x00, (WORD8)0xFF, (WORD8)0x02,
      (WORD8)0x05},
     {(WORD8)0x06, (WORD8)0x07, (WORD8)0x05, (WORD8)0x03, (WORD8)0x05,
      (WORD8)0x04},
     {(WORD8)0x2A, (WORD8)0x1F, (WORD8)0x12, (WORD8)0x12, (WORD8)0x11,
      (WORD8)0x18},
     {(WORD8)0x19, (WORD8)0x19, (WORD8)0x02, (WORD8)0x04, (WORD8)0x00,
      (WORD8)0x04},
     {(WORD8)0x18, (WORD8)0x17, (WORD8)0x17, (WORD8)0x15, (WORD8)0x16,
      (WORD8)0x15},
     {(WORD8)0x21, (WORD8)0x1E, (WORD8)0x1B, (WORD8)0x19, (WORD8)0x1C,
      (WORD8)0x1B},
     {(WORD8)0x3C, (WORD8)0x35, (WORD8)0x20, (WORD8)0x1D, (WORD8)0x30,
      (WORD8)0x34},
     {(WORD8)0x3A, (WORD8)0x1F, (WORD8)0x37, (WORD8)0x38, (WORD8)0x33,
      (WORD8)0x31},
     {(WORD8)0x37, (WORD8)0x34, (WORD8)0x25, (WORD8)0x27, (WORD8)0x35,
      (WORD8)0x34},
     {(WORD8)0x34, (WORD8)0x2E, (WORD8)0x32, (WORD8)0x31, (WORD8)0x34,
      (WORD8)0x31},
     {(WORD8)0x36, (WORD8)0x33, (WORD8)0x2F, (WORD8)0x2F, (WORD8)0x32,
      (WORD8)0x2F},
     {(WORD8)0x35, (WORD8)0x20, (WORD8)0x2F, (WORD8)0x32, (WORD8)0x2F,
      (WORD8)0x2C},
     {(WORD8)0x2E, (WORD8)0x2B, (WORD8)0x2F, (WORD8)0x34, (WORD8)0x36,
      (WORD8)0x30},
     {(WORD8)0x3F, (WORD8)0x39, (WORD8)0x30, (WORD8)0x28, (WORD8)0x29,
      (WORD8)0x29},
     {(WORD8)0x3C, (WORD8)0x30, (WORD8)0x32, (WORD8)0x37, (WORD8)0x39,
      (WORD8)0x36},
     {(WORD8)0x37, (WORD8)0x36, (WORD8)0x30, (WORD8)0x2B, (WORD8)0x26,
      (WORD8)0x24},
     {(WORD8)0x44, (WORD8)0x38, (WORD8)0x2F, (WORD8)0x2D, (WORD8)0x2D,
      (WORD8)0x2D},
     {(WORD8)0x38, (WORD8)0x2B, (WORD8)0x2C, (WORD8)0x2C, (WORD8)0x30,
      (WORD8)0x2D},
     {(WORD8)0x37, (WORD8)0x36, (WORD8)0x2F, (WORD8)0x23, (WORD8)0x2D,
      (WORD8)0x32},
     {(WORD8)0x3C, (WORD8)0x39, (WORD8)0x29, (WORD8)0x2E, (WORD8)0x38,
      (WORD8)0x37},
     {(WORD8)0x3B, (WORD8)0x3A, (WORD8)0x35, (WORD8)0x32, (WORD8)0x31,
      (WORD8)0x2D},
     {(WORD8)0x32, (WORD8)0x31, (WORD8)0x2F, (WORD8)0x2C, (WORD8)0x2D,
      (WORD8)0x28},
     {(WORD8)0x2C, (WORD8)0x31, (WORD8)0x32, (WORD8)0x30, (WORD8)0x32,
      (WORD8)0x2D},
     {(WORD8)0x35, (WORD8)0x34, (WORD8)0x34, (WORD8)0x34, (WORD8)0x35,
      (WORD8)0x33},
     {(WORD8)0x34, (WORD8)0x38, (WORD8)0x3B, (WORD8)0x3C, (WORD8)0x3E,
      (WORD8)0x3A},
     {(WORD8)0x3E, (WORD8)0x3C, (WORD8)0x3B, (WORD8)0x3A, (WORD8)0x3C,
      (WORD8)0x39},
     {(WORD8)0x3D, (WORD8)0x41, (WORD8)0x46, (WORD8)0x41, (WORD8)0x3D,
      (WORD8)0x38},
     {(WORD8)0x44, (WORD8)0x41, (WORD8)0x40, (WORD8)0x3E, (WORD8)0x3F,
      (WORD8)0x3A},
     {(WORD8)0x47, (WORD8)0x47, (WORD8)0x47, (WORD8)0x42, (WORD8)0x44,
      (WORD8)0x40},
     {(WORD8)0x4C, (WORD8)0x4A, (WORD8)0x4A, (WORD8)0x46, (WORD8)0x49,
      (WORD8)0x45},
     {(WORD8)0x53, (WORD8)0x52, (WORD8)0x52, (WORD8)0x4C, (WORD8)0x4E,
      (WORD8)0x49},
     {(WORD8)0x41, (WORD8)0x3D, (WORD8)0x39, (WORD8)0x2C, (WORD8)0x2E,
      (WORD8)0x2E},
     {(WORD8)0x2D, (WORD8)0x37, (WORD8)0x36, (WORD8)0x30, (WORD8)0x28,
      (WORD8)0x36},
     {(WORD8)0x3B, (WORD8)0x32, (WORD8)0x2E, (WORD8)0x2D, (WORD8)0x2D,
      (WORD8)0x29},
     {(WORD8)0x40, (WORD8)0x39, (WORD8)0x36, (WORD8)0x35, (WORD8)0x36,
      (WORD8)0x32},
     {(WORD8)0x30, (WORD8)0x2D, (WORD8)0x2D, (WORD8)0x2E, (WORD8)0x31,
      (WORD8)0x30},
     {(WORD8)0x38, (WORD8)0x3D, (WORD8)0x3B, (WORD8)0x37, (WORD8)0x35,
      (WORD8)0x34},
     {(WORD8)0x44, (WORD8)0x3D, (WORD8)0x3C, (WORD8)0x38, (WORD8)0x37,
      (WORD8)0x33},
     {(WORD8)0x3A, (WORD8)0x36, (WORD8)0x37, (WORD8)0x37, (WORD8)0x39,
      (WORD8)0x36},
     {(WORD8)0x32, (WORD8)0x36, (WORD8)0x37, (WORD8)0x30, (WORD8)0x2E,
      (WORD8)0x2A},
     {(WORD8)0x3C, (WORD8)0x33, (WORD8)0x33, (WORD8)0x31, (WORD8)0x33,
      (WORD8)0x30},
     {(WORD8)0x30, (WORD8)0x31, (WORD8)0x36, (WORD8)0x37, (WORD8)0x38,
      (WORD8)0x34},
     {(WORD8)0x26, (WORD8)0x27, (WORD8)0x2E, (WORD8)0x29, (WORD8)0x1C,
      (WORD8)0x16},
     {(WORD8)0x14, (WORD8)0x15, (WORD8)0x1F, (WORD8)0x17, (WORD8)0x15,
      (WORD8)0x1C},
     {(WORD8)0x38, (WORD8)0x2D, (WORD8)0x18, (WORD8)0x13, (WORD8)0x1E,
      (WORD8)0x2B},
     {(WORD8)0x30, (WORD8)0x22, (WORD8)0x17, (WORD8)0x1A, (WORD8)0x26,
      (WORD8)0x2B},
     {(WORD8)0x24, (WORD8)0x20, (WORD8)0x1F, (WORD8)0x10, (WORD8)0x0C,
      (WORD8)0x11},
     {(WORD8)0x27, (WORD8)0x1F, (WORD8)0x13, (WORD8)0x17, (WORD8)0x24,
      (WORD8)0x2A},
     {(WORD8)0x2F, (WORD8)0x13, (WORD8)0x18, (WORD8)0x13, (WORD8)0x2A,
      (WORD8)0x32},
     {(WORD8)0x31, (WORD8)0x1E, (WORD8)0x1E, (WORD8)0x1E, (WORD8)0x21,
      (WORD8)0x28},
     {(WORD8)0x2A, (WORD8)0x12, (WORD8)0x19, (WORD8)0x17, (WORD8)0x16,
      (WORD8)0x24},
     {(WORD8)0x27, (WORD8)0x0F, (WORD8)0x16, (WORD8)0x1D, (WORD8)0x17,
      (WORD8)0x1C},
     {(WORD8)0x2F, (WORD8)0x26, (WORD8)0x25, (WORD8)0x22, (WORD8)0x20,
      (WORD8)0x22},
     {(WORD8)0x1E, (WORD8)0x1B, (WORD8)0x1E, (WORD8)0x18, (WORD8)0x1E,
      (WORD8)0x24},
     {(WORD8)0x31, (WORD8)0x26, (WORD8)0x0E, (WORD8)0x15, (WORD8)0x15,
      (WORD8)0x25},
     {(WORD8)0x2D, (WORD8)0x22, (WORD8)0x1E, (WORD8)0x14, (WORD8)0x10,
      (WORD8)0x22},
     {(WORD8)0x25, (WORD8)0x1B, (WORD8)0x18, (WORD8)0x11, (WORD8)0x13,
      (WORD8)0x1F},
     {(WORD8)0x2F, (WORD8)0x1B, (WORD8)0x13, (WORD8)0x1B, (WORD8)0x18,
      (WORD8)0x22},
     {(WORD8)0x21, (WORD8)0x24, (WORD8)0x1D, (WORD8)0x1C, (WORD8)0x1D,
      (WORD8)0x1B},
     {(WORD8)0x23, (WORD8)0x1E, (WORD8)0x28, (WORD8)0x29, (WORD8)0x27,
      (WORD8)0x25},
     {(WORD8)0x2E, (WORD8)0x2A, (WORD8)0x1D, (WORD8)0x17, (WORD8)0x26,
      (WORD8)0x2D},
     {(WORD8)0x31, (WORD8)0x2C, (WORD8)0x1A, (WORD8)0x0E, (WORD8)0x1A,
      (WORD8)0x24},
     {(WORD8)0x26, (WORD8)0x16, (WORD8)0x20, (WORD8)0x1D, (WORD8)0x14,
      (WORD8)0x1E},
     {(WORD8)0x29, (WORD8)0x20, (WORD8)0x1B, (WORD8)0x1B, (WORD8)0x17,
      (WORD8)0x17},
     {(WORD8)0x1D, (WORD8)0x06, (WORD8)0x1A, (WORD8)0x1E, (WORD8)0x1B,
      (WORD8)0x1D},
     {(WORD8)0x2B, (WORD8)0x23, (WORD8)0x1F, (WORD8)0x1F, (WORD8)0x1D,
      (WORD8)0x1C},
     {(WORD8)0x27, (WORD8)0x1A, (WORD8)0x0C, (WORD8)0x0E, (WORD8)0x0F,
      (WORD8)0x1A},
     {(WORD8)0x29, (WORD8)0x1D, (WORD8)0x1E, (WORD8)0x22, (WORD8)0x22,
      (WORD8)0x24},
     {(WORD8)0x20, (WORD8)0x21, (WORD8)0x1B, (WORD8)0x18, (WORD8)0x13,
      (WORD8)0x21},
     {(WORD8)0x27, (WORD8)0x0E, (WORD8)0x10, (WORD8)0x14, (WORD8)0x10,
      (WORD8)0x1A},
     {(WORD8)0x26, (WORD8)0x24, (WORD8)0x25, (WORD8)0x25, (WORD8)0x26,
      (WORD8)0x28},
     {(WORD8)0x1A, (WORD8)0x24, (WORD8)0x25, (WORD8)0x29, (WORD8)0x26,
      (WORD8)0x24},
     {(WORD8)0x1D, (WORD8)0x1D, (WORD8)0x15, (WORD8)0x12, (WORD8)0x0F,
      (WORD8)0x18},
     {(WORD8)0x1E, (WORD8)0x14, (WORD8)0x13, (WORD8)0x12, (WORD8)0x14,
      (WORD8)0x18},
     {(WORD8)0x16, (WORD8)0x13, (WORD8)0x13, (WORD8)0x1A, (WORD8)0x1B,
      (WORD8)0x1D},
     {(WORD8)0x20, (WORD8)0x27, (WORD8)0x22, (WORD8)0x24, (WORD8)0x1A,
      (WORD8)0x19},
     {(WORD8)0x1F, (WORD8)0x17, (WORD8)0x19, (WORD8)0x18, (WORD8)0x17,
      (WORD8)0x18},
     {(WORD8)0x20, (WORD8)0x1B, (WORD8)0x1C, (WORD8)0x1C, (WORD8)0x1B,
      (WORD8)0x1A},
     {(WORD8)0x23, (WORD8)0x19, (WORD8)0x1D, (WORD8)0x1F, (WORD8)0x1E,
      (WORD8)0x21},
     {(WORD8)0x26, (WORD8)0x1F, (WORD8)0x1D, (WORD8)0x1B, (WORD8)0x19,
      (WORD8)0x1A},
     {(WORD8)0x23, (WORD8)0x1E, (WORD8)0x1F, (WORD8)0x20, (WORD8)0x1F,
      (WORD8)0x1E},
     {(WORD8)0x29, (WORD8)0x20, (WORD8)0x22, (WORD8)0x20, (WORD8)0x20,
      (WORD8)0x1F},
     {(WORD8)0x26, (WORD8)0x23, (WORD8)0x21, (WORD8)0x22, (WORD8)0x23,
      (WORD8)0x23},
     {(WORD8)0x29, (WORD8)0x1F, (WORD8)0x24, (WORD8)0x25, (WORD8)0x26,
      (WORD8)0x29},
     {(WORD8)0x2B, (WORD8)0x22, (WORD8)0x25, (WORD8)0x27, (WORD8)0x23,
      (WORD8)0x21},
     {(WORD8)0x29, (WORD8)0x21, (WORD8)0x19, (WORD8)0x0E, (WORD8)0x22,
      (WORD8)0x2D},
     {(WORD8)0x32, (WORD8)0x29, (WORD8)0x1F, (WORD8)0x1C, (WORD8)0x1B,
      (WORD8)0x21},
     {(WORD8)0x1E, (WORD8)0x1A, (WORD8)0x1E, (WORD8)0x24, (WORD8)0x25,
      (WORD8)0x25},
     {(WORD8)0x24, (WORD8)0x1D, (WORD8)0x21, (WORD8)0x22, (WORD8)0x22,
      (WORD8)0x25},
     {(WORD8)0x2C, (WORD8)0x25, (WORD8)0x21, (WORD8)0x22, (WORD8)0x23,
      (WORD8)0x25},
     {(WORD8)0x24, (WORD8)0x1E, (WORD8)0x21, (WORD8)0x26, (WORD8)0x2B,
      (WORD8)0x2C},
     {(WORD8)0x28, (WORD8)0x24, (WORD8)0x1B, (WORD8)0x1F, (WORD8)0x28,
      (WORD8)0x2D},
     {(WORD8)0x23, (WORD8)0x13, (WORD8)0x16, (WORD8)0x22, (WORD8)0x22,
      (WORD8)0x29},
     {(WORD8)0x1B, (WORD8)0x23, (WORD8)0x1C, (WORD8)0x20, (WORD8)0x14,
      (WORD8)0x0D},
     {(WORD8)0x1E, (WORD8)0x16, (WORD8)0x1A, (WORD8)0x1E, (WORD8)0x1C,
      (WORD8)0x1D},
     {(WORD8)0x2B, (WORD8)0x1C, (WORD8)0x1D, (WORD8)0x20, (WORD8)0x1B,
      (WORD8)0x1C},
     {(WORD8)0x1C, (WORD8)0x1B, (WORD8)0x23, (WORD8)0x1F, (WORD8)0x19,
      (WORD8)0x1E},
     {(WORD8)0x21, (WORD8)0x23, (WORD8)0x26, (WORD8)0x20, (WORD8)0x20,
      (WORD8)0x22},
     {(WORD8)0x1D, (WORD8)0x0B, (WORD8)0x19, (WORD8)0x1E, (WORD8)0x11,
      (WORD8)0x19},
     {(WORD8)0x18, (WORD8)0x17, (WORD8)0x16, (WORD8)0x17, (WORD8)0x14,
      (WORD8)0x16},
     {(WORD8)0x16, (WORD8)0x19, (WORD8)0x1C, (WORD8)0x20, (WORD8)0x21,
      (WORD8)0x22},
     {(WORD8)0x30, (WORD8)0x1E, (WORD8)0x22, (WORD8)0x24, (WORD8)0x25,
      (WORD8)0x26},
     {(WORD8)0x1B, (WORD8)0x1F, (WORD8)0x17, (WORD8)0x1D, (WORD8)0x1E,
      (WORD8)0x21},
     {(WORD8)0x32, (WORD8)0x2B, (WORD8)0x27, (WORD8)0x1F, (WORD8)0x1B,
      (WORD8)0x1A},
     {(WORD8)0x28, (WORD8)0x20, (WORD8)0x1A, (WORD8)0x1B, (WORD8)0x1F,
      (WORD8)0x23},
     {(WORD8)0x32, (WORD8)0x21, (WORD8)0x20, (WORD8)0x21, (WORD8)0x1D,
      (WORD8)0x1F},
     {(WORD8)0x22, (WORD8)0x18, (WORD8)0x12, (WORD8)0x15, (WORD8)0x1B,
      (WORD8)0x20},
     {(WORD8)0x27, (WORD8)0x27, (WORD8)0x2A, (WORD8)0x24, (WORD8)0x21,
      (WORD8)0x21},
     {(WORD8)0x1E, (WORD8)0x0F, (WORD8)0x0D, (WORD8)0x1A, (WORD8)0x1D,
      (WORD8)0x23},
     {(WORD8)0x28, (WORD8)0x25, (WORD8)0x27, (WORD8)0x21, (WORD8)0x17,
      (WORD8)0x25},
     {(WORD8)0x2B, (WORD8)0x27, (WORD8)0x23, (WORD8)0x19, (WORD8)0x13,
      (WORD8)0x14},
     {(WORD8)0x25, (WORD8)0x2B, (WORD8)0x22, (WORD8)0x22, (WORD8)0x20,
      (WORD8)0x21},
     {(WORD8)0x27, (WORD8)0x1B, (WORD8)0x16, (WORD8)0x17, (WORD8)0x0F,
      (WORD8)0x15},
     {(WORD8)0x29, (WORD8)0x26, (WORD8)0x23, (WORD8)0x15, (WORD8)0x1E,
      (WORD8)0x28},
     {(WORD8)0x24, (WORD8)0x1C, (WORD8)0x19, (WORD8)0x1A, (WORD8)0x18,
      (WORD8)0x19},
     {(WORD8)0x2D, (WORD8)0x15, (WORD8)0x27, (WORD8)0x2B, (WORD8)0x24,
      (WORD8)0x23},
     {(WORD8)0x2C, (WORD8)0x12, (WORD8)0x1F, (WORD8)0x23, (WORD8)0x1F,
      (WORD8)0x20},
     {(WORD8)0x25, (WORD8)0x0F, (WORD8)0x22, (WORD8)0x27, (WORD8)0x1F,
      (WORD8)0x21}};
