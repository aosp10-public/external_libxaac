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
#ifndef IXHEAACD_SBRQMFTRANS_H
#define IXHEAACD_SBRQMFTRANS_H

VOID ixheaacd_qmf_hbe_apply(ia_esbr_hbe_txposer_struct *h_hbe_txposer,
                            FLOAT32 qmf_buf_real[][64],
                            FLOAT32 qmf_buf_imag[][64], WORD32 num_columns,
                            FLOAT32 pv_qmf_buf_real[][64],
                            FLOAT32 pv_qmf_buf_imag[][64],
                            WORD32 pitch_in_bins);

VOID ixheaacd_qmf_hbe_data_reinit(
    ia_esbr_hbe_txposer_struct *ptr_hbe_transposer_str,
    WORD16 *ptr_freq_band_tbl[MAX_FREQ_COEFFS + 1], WORD16 *ptr_num_sf_bands,
    WORD32 upsamp_4_flag);

VOID ixheaacd_hbe_post_anal_process(ia_esbr_hbe_txposer_struct *ptr_hbe_txposer,
                                    WORD32 pitch_in_bins,
                                    WORD32 sbr_upsamp_4_flg);

#endif