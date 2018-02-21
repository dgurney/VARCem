/*
 * VARCem	Virtual Archaelogical Computer EMulator.
 *		An emulator of (mostly) x86-based PC systems and devices,
 *		using the ISA,EISA,VLB,MCA  and PCI system buses, roughly
 *		spanning the era between 1981 and 1995.
 *
 *		This file is part of the VARCem Project.
 *
 *		Implementation of the Commodore PC3 system.
 *
 * Version:	@(#)m_at_commodore.c	1.0.1	2018/02/14
 *
 * Authors:	Fred N. van Kempen, <decwiz@yahoo.com>
 *		Miran Grca, <mgrca8@gmail.com>
 *		Sarah Walker, <tommowalker@tommowalker.co.uk>
 *
 *		Copyright 2017,2018 Fred N. van Kempen.
 *		Copyright 2016-2018 Miran Grca.
 *		Copyright 2008-2018 Sarah Walker.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free  Software  Foundation; either  version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is  distributed in the hope that it will be useful, but
 * WITHOUT   ANY  WARRANTY;  without  even   the  implied  warranty  of
 * MERCHANTABILITY  or FITNESS  FOR A PARTICULAR  PURPOSE. See  the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the:
 *
 *   Free Software Foundation, Inc.
 *   59 Temple Place - Suite 330
 *   Boston, MA 02111-1307
 *   USA.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include "../emu.h"
#include "../device.h"
#include "../io.h"
#include "../lpt.h"
#include "../serial.h"
#include "../floppy/fdd.h"
#include "../floppy/fdc.h"
#include "machine.h"


static void cbm_io_write(uint16_t port, uint8_t val, void *p)
{
        lpt1_remove();
        lpt2_remove();
        switch (val & 3)
        {
                case 1:
                lpt1_init(0x3bc);
                break;
                case 2:
       	        lpt1_init(0x378);
                break;
                case 3:
                lpt1_init(0x278);
                break;
        }
        switch (val & 0xc)
        {
                case 0x4:
                serial_setup(1, 0x2f8, 3);
                break;
                case 0x8:
                serial_setup(1, 0x3f8, 4);
                break;
        }
}

static void cbm_io_init()
{
        io_sethandler(0x0230, 0x0001, NULL,NULL,NULL, cbm_io_write,NULL,NULL, NULL);
}


void
machine_at_cmdpc_init(machine_t *model)
{
	machine_at_ide_top_remap_init(model);
	device_add(&fdc_at_device);

	cbm_io_init();
}