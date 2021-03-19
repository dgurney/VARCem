/*
 * VARCem	Virtual ARchaeological Computer EMulator.
 *		An emulator of (mostly) x86-based PC systems and devices,
 *		using the ISA,EISA,VLB,MCA  and PCI system buses, roughly
 *		spanning the era between 1981 and 1995.
 *
 *		This file is part of the VARCem Project.
 *
 *		Definitions for the centralized PNG image handler.
 *
 * Version:	@(#)png.h	1.0.4	2021/03/18
 *
 * Author:	Fred N. van Kempen, <decwiz@yahoo.com>
 *
 *		Copyright 2018-2021 Fred N. van Kempen.
 *
 *		Redistribution and  use  in source  and binary forms, with
 *		or  without modification, are permitted  provided that the
 *		following conditions are met:
 *
 *		1. Redistributions of  source  code must retain the entire
 *		   above notice, this list of conditions and the following
 *		   disclaimer.
 *
 *		2. Redistributions in binary form must reproduce the above
 *		   copyright  notice,  this list  of  conditions  and  the
 *		   following disclaimer in  the documentation and/or other
 *		   materials provided with the distribution.
 *
 *		3. Neither the  name of the copyright holder nor the names
 *		   of  its  contributors may be used to endorse or promote
 *		   products  derived from  this  software without specific
 *		   prior written permission.
 *
 * THIS SOFTWARE  IS  PROVIDED BY THE  COPYRIGHT  HOLDERS AND CONTRIBUTORS
 * "AS IS" AND  ANY EXPRESS  OR  IMPLIED  WARRANTIES,  INCLUDING, BUT  NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE  ARE  DISCLAIMED. IN  NO  EVENT  SHALL THE COPYRIGHT
 * HOLDER OR  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL,  EXEMPLARY,  OR  CONSEQUENTIAL  DAMAGES  (INCLUDING,  BUT  NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE  GOODS OR SERVICES;  LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON  ANY
 * THEORY OF  LIABILITY, WHETHER IN  CONTRACT, STRICT  LIABILITY, OR  TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  IN ANY  WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef EMU_PNG_H
# define EMU_PNG_H


typedef struct {
    uint8_t     r, g, b;
} rgb_pal_t;

typedef rgb_pal_t RGB_PAL[256];


#ifdef __cplusplus
extern "C" {
#endif

extern int	png_load(void);
extern void	png_unload(void);

extern int	png_write_gray(const wchar_t *path, int invert,
			       uint8_t *pix, int16_t w, int16_t h);

extern int	png_write_rgb(const wchar_t *fn, int flip, uint8_t *pix,
			      int16_t w, int16_t h);

extern int	png_write_pal(const wchar_t *fn, uint8_t *pix,
			      int16_t w, int16_t h,
			      uint16_t pitch, RGB_PAL pal);

#ifdef __cplusplus
}
#endif


#endif	/*EMU_PNG_H*/
