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
#include "ixheaacd_sbr_common.h"
#include <ixheaacd_type_def.h>
#include "ixheaacd_constants.h"
#include <ixheaacd_basic_ops32.h>
#include <ixheaacd_basic_ops16.h>
#include <ixheaacd_basic_ops40.h>
#include "ixheaacd_common_rom.h"
#include "ixheaacd_basic_funcs.h"
#include "ixheaacd_bitbuffer.h"
#include "ixheaacd_defines.h"
#include <ixheaacd_aac_rom.h>
#include "ixheaacd_pulsedata.h"

#include "ixheaacd_pns.h"
#include "ixheaacd_drc_data_struct.h"

#include "ixheaacd_lt_predict.h"

#include "ixheaacd_channelinfo.h"
#include "ixheaacd_drc_dec.h"
#include "ixheaacd_sbrdecsettings.h"
#include "ixheaacd_sbrdecoder.h"
#include "ixheaacd_sbr_scale.h"
#include "ixheaacd_lpp_tran.h"
#include "ixheaacd_env_extr_part.h"

#include <ixheaacd_sbr_rom.h>
#include "ixheaacd_hybrid.h"
#include "ixheaacd_ps_dec.h"
#include "ixheaacd_env_extr.h"
#include "ixheaacd_env_calc.h"
#include "ixheaacd_qmf_dec.h"
#include "ixheaacd_sbr_const.h"

#include "ixheaacd_pvc_dec.h"
#include "ixheaacd_sbr_dec.h"
#include "ixheaacd_pulsedata.h"

#include "ixheaacd_block.h"
#include "ixheaacd_channel.h"
#include "ixheaacd_audioobjtypes.h"
#include "ixheaacd_latmdemux.h"
#include "ixheaacd_aacdec.h"

/* const - has been removed to verify table relocatability */
const ixheaacd_misc_tables ixheaacd_str_fft_n_transcendent_tables = {

    // const WORD16 cos_sin_lookup_tab[513] =
    {0x0000, 0x0065, 0x00c9, 0x012e, 0x0192, 0x01f7, 0x025b, 0x02c0, 0x0324,
     0x0389, 0x03ed, 0x0452, 0x04b6, 0x051b, 0x057f, 0x05e3, 0x0648, 0x06ac,
     0x0711, 0x0775, 0x07d9, 0x083e, 0x08a2, 0x0906, 0x096b, 0x09cf, 0x0a33,
     0x0a97, 0x0afb, 0x0b60, 0x0bc4, 0x0c28, 0x0c8c, 0x0cf0, 0x0d54, 0x0db8,
     0x0e1c, 0x0e80, 0x0ee4, 0x0f47, 0x0fab, 0x100f, 0x1073, 0x10d6, 0x113a,
     0x119e, 0x1201, 0x1265, 0x12c8, 0x132b, 0x138f, 0x13f2, 0x1455, 0x14b9,
     0x151c, 0x157f, 0x15e2, 0x1645, 0x16a8, 0x170b, 0x176e, 0x17d1, 0x1833,
     0x1896, 0x18f9, 0x195b, 0x19be, 0x1a20, 0x1a83, 0x1ae5, 0x1b47, 0x1ba9,
     0x1c0c, 0x1c6e, 0x1cd0, 0x1d31, 0x1d93, 0x1df5, 0x1e57, 0x1eb8, 0x1f1a,
     0x1f7b, 0x1fdd, 0x203e, 0x209f, 0x2101, 0x2162, 0x21c3, 0x2224, 0x2284,
     0x22e5, 0x2346, 0x23a7, 0x2407, 0x2467, 0x24c8, 0x2528, 0x2588, 0x25e8,
     0x2648, 0x26a8, 0x2708, 0x2768, 0x27c7, 0x2827, 0x2886, 0x28e5, 0x2945,
     0x29a4, 0x2a03, 0x2a62, 0x2ac1, 0x2b1f, 0x2b7e, 0x2bdc, 0x2c3b, 0x2c99,
     0x2cf7, 0x2d55, 0x2db3, 0x2e11, 0x2e6f, 0x2ecc, 0x2f2a, 0x2f87, 0x2fe5,
     0x3042, 0x309f, 0x30fc, 0x3159, 0x31b5, 0x3212, 0x326e, 0x32cb, 0x3327,
     0x3383, 0x33df, 0x343b, 0x3497, 0x34f2, 0x354e, 0x35a9, 0x3604, 0x365f,
     0x36ba, 0x3715, 0x3770, 0x37ca, 0x3825, 0x387f, 0x38d9, 0x3933, 0x398d,
     0x39e7, 0x3a40, 0x3a9a, 0x3af3, 0x3b4c, 0x3ba5, 0x3bfe, 0x3c57, 0x3caf,
     0x3d08, 0x3d60, 0x3db8, 0x3e10, 0x3e68, 0x3ec0, 0x3f17, 0x3f6f, 0x3fc6,
     0x401d, 0x4074, 0x40cb, 0x4121, 0x4178, 0x41ce, 0x4224, 0x427a, 0x42d0,
     0x4326, 0x437b, 0x43d1, 0x4426, 0x447b, 0x44d0, 0x4524, 0x4579, 0x45cd,
     0x4621, 0x4675, 0x46c9, 0x471d, 0x4770, 0x47c4, 0x4817, 0x486a, 0x48bd,
     0x490f, 0x4962, 0x49b4, 0x4a06, 0x4a58, 0x4aaa, 0x4afb, 0x4b4d, 0x4b9e,
     0x4bef, 0x4c40, 0x4c91, 0x4ce1, 0x4d31, 0x4d81, 0x4dd1, 0x4e21, 0x4e71,
     0x4ec0, 0x4f0f, 0x4f5e, 0x4fad, 0x4ffb, 0x504a, 0x5098, 0x50e6, 0x5134,
     0x5181, 0x51cf, 0x521c, 0x5269, 0x52b6, 0x5303, 0x534f, 0x539b, 0x53e7,
     0x5433, 0x547f, 0x54ca, 0x5515, 0x5560, 0x55ab, 0x55f6, 0x5640, 0x568a,
     0x56d4, 0x571e, 0x5767, 0x57b1, 0x57fa, 0x5843, 0x588c, 0x58d4, 0x591c,
     0x5964, 0x59ac, 0x59f4, 0x5a3b, 0x5a82, 0x5ac9, 0x5b10, 0x5b57, 0x5b9d,
     0x5be3, 0x5c29, 0x5c6f, 0x5cb4, 0x5cf9, 0x5d3e, 0x5d83, 0x5dc8, 0x5e0c,
     0x5e50, 0x5e94, 0x5ed7, 0x5f1b, 0x5f5e, 0x5fa1, 0x5fe4, 0x6026, 0x6068,
     0x60aa, 0x60ec, 0x612e, 0x616f, 0x61b0, 0x61f1, 0x6232, 0x6272, 0x62b2,
     0x62f2, 0x6332, 0x6371, 0x63b0, 0x63ef, 0x642e, 0x646c, 0x64ab, 0x64e9,
     0x6526, 0x6564, 0x65a1, 0x65de, 0x661b, 0x6657, 0x6693, 0x66d0, 0x670b,
     0x6747, 0x6782, 0x67bd, 0x67f8, 0x6832, 0x686d, 0x68a7, 0x68e0, 0x691a,
     0x6953, 0x698c, 0x69c5, 0x69fd, 0x6a36, 0x6a6e, 0x6aa5, 0x6add, 0x6b14,
     0x6b4b, 0x6b82, 0x6bb8, 0x6bee, 0x6c24, 0x6c5a, 0x6c8f, 0x6cc4, 0x6cf9,
     0x6d2e, 0x6d62, 0x6d96, 0x6dca, 0x6dfe, 0x6e31, 0x6e64, 0x6e97, 0x6ec9,
     0x6efb, 0x6f2d, 0x6f5f, 0x6f90, 0x6fc2, 0x6ff2, 0x7023, 0x7053, 0x7083,
     0x70b3, 0x70e3, 0x7112, 0x7141, 0x7170, 0x719e, 0x71cc, 0x71fa, 0x7228,
     0x7255, 0x7282, 0x72af, 0x72dc, 0x7308, 0x7334, 0x735f, 0x738b, 0x73b6,
     0x73e1, 0x740b, 0x7436, 0x7460, 0x7489, 0x74b3, 0x74dc, 0x7505, 0x752d,
     0x7556, 0x757e, 0x75a6, 0x75cd, 0x75f4, 0x761b, 0x7642, 0x7668, 0x768e,
     0x76b4, 0x76d9, 0x76fe, 0x7723, 0x7748, 0x776c, 0x7790, 0x77b4, 0x77d8,
     0x77fb, 0x781e, 0x7840, 0x7863, 0x7885, 0x78a6, 0x78c8, 0x78e9, 0x790a,
     0x792a, 0x794a, 0x796a, 0x798a, 0x79aa, 0x79c9, 0x79e7, 0x7a06, 0x7a24,
     0x7a42, 0x7a60, 0x7a7d, 0x7a9a, 0x7ab7, 0x7ad3, 0x7aef, 0x7b0b, 0x7b27,
     0x7b42, 0x7b5d, 0x7b78, 0x7b92, 0x7bac, 0x7bc6, 0x7bdf, 0x7bf9, 0x7c11,
     0x7c2a, 0x7c42, 0x7c5a, 0x7c72, 0x7c89, 0x7ca0, 0x7cb7, 0x7cce, 0x7ce4,
     0x7cfa, 0x7d0f, 0x7d25, 0x7d3a, 0x7d4e, 0x7d63, 0x7d77, 0x7d8a, 0x7d9e,
     0x7db1, 0x7dc4, 0x7dd6, 0x7de9, 0x7dfb, 0x7e0c, 0x7e1e, 0x7e2f, 0x7e3f,
     0x7e50, 0x7e60, 0x7e70, 0x7e7f, 0x7e8e, 0x7e9d, 0x7eac, 0x7eba, 0x7ec8,
     0x7ed6, 0x7ee3, 0x7ef0, 0x7efd, 0x7f0a, 0x7f16, 0x7f22, 0x7f2d, 0x7f38,
     0x7f43, 0x7f4e, 0x7f58, 0x7f62, 0x7f6c, 0x7f75, 0x7f7e, 0x7f87, 0x7f90,
     0x7f98, 0x7fa0, 0x7fa7, 0x7fae, 0x7fb5, 0x7fbc, 0x7fc2, 0x7fc8, 0x7fce,
     0x7fd3, 0x7fd9, 0x7fdd, 0x7fe2, 0x7fe6, 0x7fea, 0x7fed, 0x7ff1, 0x7ff4,
     0x7ff6, 0x7ff8, 0x7ffa, 0x7ffc, 0x7ffe, 0x7fff, 0x7fff, 0x7fff, 0x7fff},

    // const WORD16 sine_table8_16[8] =
    {
        -0x0000, -0x18f9, -0x30fc, -0x471d, -0x5a82, -0x6a6e, -0x7642, -0x7d8a,
    },

    // const WORD16 log_dual_is_table[LOG_2_TABLE_SIZE] =
    {(WORD16)(-0x8000),
     0x0000,
     0x1000,
     0x195c,
     0x2000,
     0x2527,
     0x295c,
     0x2ceb,
     0x3000,
     0x32b8,
     0x3527,
     0x375a,
     0x395c,
     0x3b35,
     0x3ceb,
     0x3e83,
     0x4000,
     0x4166,
     0x42b8,
     0x43f8,
     0x4527,
     0x4647,
     0x475a,
     0x4861,
     0x495c,
     0x4a4d,
     0x4b35,
     0x4c14,
     0x4ceb,
     0x4dba,
     0x4e83,
     0x4f44,
     0x5000,
     0x50b6,
     0x5166,
     0x5212,
     0x52b8,
     0x535a,
     0x53f8,
     0x5491,
     0x5527,
     0x55b9,
     0x5647,
     0x56d2,
     0x575a,
     0x57df,
     0x5861,
     0x58e0,
     0x595c,
     0x59d6,
     0x5a4d,
     0x5ac2,
     0x5b35,
     0x5ba6,
     0x5c14,
     0x5c80,
     0x5ceb,
     0x5d54,
     0x5dba,
     0x5e1f,
     0x5e83,
     0x5ee4,
     0x5f44,
     0x5fa3,
     0x6000},

    /*WORD32 down_mix_martix[4][2][8] = */
    {
        {/*	Q30 */ /* 5.0 Channel to Stereo */
         {405185594, 0, 315041546, 315041546, 0, 0, 0, 0},
         {0, 405185594, 315041546, 0, 315041546, 0, 0, 0}},
        {/*  Q30 */ /* 5.1 Channel to Stereo */
         {405185594, 0, 286509481, 95503160, 286509481, 0, 0, 0},
         {0, 405185594, 286509481, 95503160, 0, 286509481, 0, 0}},
        {/*	Q30 */ /* 7.0 Channel to Stereo */
         {405185594, 0, 244131873, 244131873, 0, 244131873, 0, 0},
         {0, 405185594, 244131873, 0, 244131873, 0, 244131873, 0}},
        {/*	Q30 */ /* 7.1 Channel to Stereo */
         {405185594, 0, 226641828, 75547276, 226641828, 0, 226641828, 0},
         {0, 405185594, 75547276, 226641828, 0, 226641828, 0, 226641828}},

    }

    /*	Q29  */
    /*const WORD32 cc_gain_scale[4] = */,
    {585461881, 638450708, 759250125, 1073741824},

    // const WORD16 inv_table[INV_TABLE_SIZE ] =
    {

        0x7f80, 0x7f02, 0x7e84, 0x7e08, 0x7d8c, 0x7d12, 0x7c98, 0x7c1f, 0x7ba7,
        0x7b30, 0x7aba, 0x7a45, 0x79d0, 0x795d, 0x78ea, 0x7878, 0x7808, 0x7797,
        0x7728, 0x76ba, 0x764c, 0x75df, 0x7573, 0x7507, 0x749d, 0x7433, 0x73ca,
        0x7361, 0x72fa, 0x7293, 0x722d, 0x71c7, 0x7162, 0x70fe, 0x709b, 0x7038,
        0x6fd6, 0x6f75, 0x6f14, 0x6eb4, 0x6e54, 0x6df6, 0x6d98, 0x6d3a, 0x6cdd,
        0x6c81, 0x6c25, 0x6bca, 0x6b70, 0x6b16, 0x6abc, 0x6a64, 0x6a0c, 0x69b4,
        0x695d, 0x6907, 0x68b1, 0x685b, 0x6807, 0x67b2, 0x675e, 0x670b, 0x66b9,
        0x6666, 0x6615, 0x65c4, 0x6573, 0x6523, 0x64d3, 0x6484, 0x6435, 0x63e7,
        0x6399, 0x634c, 0x62ff, 0x62b3, 0x6267, 0x621c, 0x61d1, 0x6186, 0x613c,
        0x60f2, 0x60a9, 0x6060, 0x6018, 0x5fd0, 0x5f89, 0x5f41, 0x5efb, 0x5eb5,
        0x5e6f, 0x5e29, 0x5de4, 0x5d9f, 0x5d5b, 0x5d17, 0x5cd4, 0x5c91, 0x5c4e,
        0x5c0c, 0x5bca, 0x5b88, 0x5b47, 0x5b06, 0x5ac5, 0x5a85, 0x5a45, 0x5a06,
        0x59c6, 0x5988, 0x5949, 0x590b, 0x58cd, 0x5890, 0x5853, 0x5816, 0x57da,
        0x579d, 0x5762, 0x5726, 0x56eb, 0x56b0, 0x5676, 0x563b, 0x5601, 0x55c8,
        0x558e, 0x5555, 0x551d, 0x54e4, 0x54ac, 0x5474, 0x543d, 0x5405, 0x53ce,
        0x5398, 0x5361, 0x532b, 0x52f5, 0x52bf, 0x528a, 0x5255, 0x5220, 0x51ec,
        0x51b7, 0x5183, 0x514f, 0x511c, 0x50e9, 0x50b6, 0x5083, 0x5050, 0x501e,
        0x4fec, 0x4fba, 0x4f89, 0x4f57, 0x4f26, 0x4ef6, 0x4ec5, 0x4e95, 0x4e64,
        0x4e35, 0x4e05, 0x4dd5, 0x4da6, 0x4d77, 0x4d48, 0x4d1a, 0x4cec, 0x4cbd,
        0x4c90, 0x4c62, 0x4c34, 0x4c07, 0x4bda, 0x4bad, 0x4b81, 0x4b54, 0x4b28,
        0x4afc, 0x4ad0, 0x4aa4, 0x4a79, 0x4a4e, 0x4a23, 0x49f8, 0x49cd, 0x49a3,
        0x4979, 0x494e, 0x4925, 0x48fb, 0x48d1, 0x48a8, 0x487f, 0x4856, 0x482d,
        0x4805, 0x47dc, 0x47b4, 0x478c, 0x4764, 0x473c, 0x4715, 0x46ed, 0x46c6,
        0x469f, 0x4678, 0x4651, 0x462b, 0x4604, 0x45de, 0x45b8, 0x4592, 0x456c,
        0x4547, 0x4521, 0x44fc, 0x44d7, 0x44b2, 0x448d, 0x4469, 0x4444, 0x4420,
        0x43fc, 0x43d8, 0x43b4, 0x4390, 0x436d, 0x4349, 0x4326, 0x4303, 0x42e0,
        0x42bd, 0x429a, 0x4277, 0x4255, 0x4233, 0x4211, 0x41ee, 0x41cd, 0x41ab,
        0x4189, 0x4168, 0x4146, 0x4125, 0x4104, 0x40e3, 0x40c2, 0x40a2, 0x4081,
        0x4061, 0x4040, 0x4020, 0x4000

    },
    // const WORD16 sqrt_table[SQRT_TABLE_SIZE] =
    {0x5a82, 0x5ab0, 0x5add, 0x5b0a, 0x5b37, 0x5b64, 0x5b90, 0x5bbd, 0x5bea,
     0x5c16, 0x5c43, 0x5c6f, 0x5c9b, 0x5cc8, 0x5cf4, 0x5d20, 0x5d4c, 0x5d77,
     0x5da3, 0x5dcf, 0x5dfb, 0x5e26, 0x5e52, 0x5e7d, 0x5ea8, 0x5ed3, 0x5eff,
     0x5f2a, 0x5f55, 0x5f80, 0x5fab, 0x5fd5, 0x6000, 0x602b, 0x6055, 0x6080,
     0x60aa, 0x60d4, 0x60ff, 0x6129, 0x6153, 0x617d, 0x61a7, 0x61d1, 0x61fb,
     0x6225, 0x624e, 0x6278, 0x62a1, 0x62cb, 0x62f4, 0x631e, 0x6347, 0x6370,
     0x6399, 0x63c2, 0x63ec, 0x6414, 0x643d, 0x6466, 0x648f, 0x64b8, 0x64e0,
     0x6509, 0x6531, 0x655a, 0x6582, 0x65ab, 0x65d3, 0x65fb, 0x6623, 0x664b,
     0x6673, 0x669b, 0x66c3, 0x66eb, 0x6713, 0x673a, 0x6762, 0x678a, 0x67b1,
     0x67d9, 0x6800, 0x6827, 0x684f, 0x6876, 0x689d, 0x68c4, 0x68eb, 0x6912,
     0x6939, 0x6960, 0x6987, 0x69ae, 0x69d4, 0x69fb, 0x6a22, 0x6a48, 0x6a6f,
     0x6a95, 0x6abc, 0x6ae2, 0x6b08, 0x6b2f, 0x6b55, 0x6b7b, 0x6ba1, 0x6bc7,
     0x6bed, 0x6c13, 0x6c39, 0x6c5f, 0x6c84, 0x6caa, 0x6cd0, 0x6cf5, 0x6d1b,
     0x6d41, 0x6d66, 0x6d8b, 0x6db1, 0x6dd6, 0x6dfb, 0x6e21, 0x6e46, 0x6e6b,
     0x6e90, 0x6eb5, 0x6eda, 0x6eff, 0x6f24, 0x6f49, 0x6f6d, 0x6f92, 0x6fb7,
     0x6fdb, 0x7000, 0x7025, 0x7049, 0x706e, 0x7092, 0x70b6, 0x70db, 0x70ff,
     0x7123, 0x7147, 0x716b, 0x7190, 0x71b4, 0x71d8, 0x71fc, 0x721f, 0x7243,
     0x7267, 0x728b, 0x72af, 0x72d2, 0x72f6, 0x731a, 0x733d, 0x7361, 0x7384,
     0x73a8, 0x73cb, 0x73ee, 0x7412, 0x7435, 0x7458, 0x747b, 0x749e, 0x74c2,
     0x74e5, 0x7508, 0x752b, 0x754e, 0x7570, 0x7593, 0x75b6, 0x75d9, 0x75fc,
     0x761e, 0x7641, 0x7664, 0x7686, 0x76a9, 0x76cb, 0x76ee, 0x7710, 0x7733,
     0x7755, 0x7777, 0x7799, 0x77bc, 0x77de, 0x7800, 0x7822, 0x7844, 0x7866,
     0x7888, 0x78aa, 0x78cc, 0x78ee, 0x7910, 0x7932, 0x7953, 0x7975, 0x7997,
     0x79b9, 0x79da, 0x79fc, 0x7a1d, 0x7a3f, 0x7a60, 0x7a82, 0x7aa3, 0x7ac5,
     0x7ae6, 0x7b07, 0x7b29, 0x7b4a, 0x7b6b, 0x7b8c, 0x7bad, 0x7bce, 0x7bef,
     0x7c11, 0x7c32, 0x7c52, 0x7c73, 0x7c94, 0x7cb5, 0x7cd6, 0x7cf7, 0x7d18,
     0x7d38, 0x7d59, 0x7d7a, 0x7d9a, 0x7dbb, 0x7ddb, 0x7dfc, 0x7e1c, 0x7e3d,
     0x7e5d, 0x7e7e, 0x7e9e, 0x7ebe, 0x7edf, 0x7eff, 0x7f1f, 0x7f3f, 0x7f60,
     0x7f80, 0x7fa0, 0x7fc0, 0x7fe0, 0x7fff},
    0,

    /*WORD32 start_band[10][16] =*/
    {/*sampling frequency = 96000*/
     {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 19, 23, 27},

     /*sampling Frequency = 88200*/
     {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 20, 24, 28},

     /*sampling Frequency = 64000*/
     {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 21, 25},

     /*sampling Frequency = 48000*/
     {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 21, 25},

     /*sampling Frequency = 44100*/
     {2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 17, 19, 22, 26},

     /*sampling Frequency = 40000*/
     {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 23, 25},

     /*sampling Frequency = 32000*/
     {2, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 24},

     /*sampling Frequency = 24000*/
     {3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 24},

     /*sampling Frequency = 22050*/
     {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 22},

     /*sampling Frequency = 16000*/
     {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}},

    /*WORD32 stop_band[10][16] = */
    {/*sampling Frequency = 96000*/
     {7, 8, 10, 12, 14, 16, 19, 23, 27, 32, 38, 46, 54, 64, 78, 86},

     /*sampling Frequency = 88200*/
     {7, 8, 10, 12, 14, 16, 19, 23, 27, 32, 38, 46, 54, 64, 78, 86},

     /*sampling Frequency = 64000*/
     {10, 11, 13, 15, 17, 20, 23, 27, 31, 36, 42, 48, 55, 64, 78, 89},

     /*sampling Frequency = 48000*/
     {11, 12, 14, 16, 19, 22, 25, 28, 32, 37, 43, 49, 56, 64, 78, 90},

     /*sampling Frequency = 44100*/
     {12, 14, 16, 18, 20, 23, 26, 30, 34, 38, 43, 49, 56, 64, 78, 91},

     /*sampling Frequency = 40000*/
     {13, 15, 17, 19, 21, 24, 27, 31, 35, 39, 44, 50, 57, 64, 78, 92},

     /*sampling Frequency = 32000*/
     {16, 18, 20, 22, 24, 27, 30, 34, 38, 42, 46, 52, 58, 64, 78, 95},

     /*sampling Frequency = 24000*/
     {16, 18, 20, 22, 24, 27, 30, 34, 38, 42, 46, 52, 58, 64, 78, 95},

     /*sampling Frequency = 22050*/
     {17, 19, 21, 23, 25, 28, 31, 34, 38, 42, 47, 52, 58, 64, 78, 96},

     /*sampling Frequency = 16000*/
     {24, 26, 28, 30, 32, 35, 38, 41, 44, 47, 51, 55, 59, 64, 78, 10}},
    /*WORD32 stop_freq_table_fs40k_2[13] = */
    {26, 28, 30, 32, 34, 36, 39, 42, 45, 48, 52, 56, 60, 0},
    /*WORD32 stop_freq_table_fs40k_4[13] = */
    {19, 21, 23, 25, 27, 30, 33, 36, 40, 44, 48, 53, 58, 0}

};
