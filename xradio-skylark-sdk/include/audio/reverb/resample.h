/*
 * Copyright (C) 2017 XRADIO TECHNOLOGY CO., LTD. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the
 *       distribution.
 *    3. Neither the name of XRADIO TECHNOLOGY CO., LTD. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef AUDIO_REVERB_RESAMPLE_H
#define AUDIO_REVERB_RESAMPLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _resample_info {
	uint16_t  NumChannels;
	uint16_t  BitsPerSample;
	uint32_t  in_SampleRate;
	uint32_t  out_SampleRate;
	void*     out_buffer;
	uint32_t  out_buffer_size;
	uint32_t  out_frame_count;
	uint32_t  out_frame_indeed;
	uint32_t  mPhaseIncrement;
	uint32_t  mPhaseFraction;
	uint16_t  mInputIndex;
	int16_t   mX0L;
	int16_t   mX0R;
} resample_info;

extern void resample_init(resample_info *info);
extern void resample(resample_info *info, int16_t* in_buffer, uint32_t buffer_length);
extern void resample_release(resample_info *info);

#ifdef __cplusplus
}
#endif

#endif