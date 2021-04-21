/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * System reel handling.
 */ 

#include "cursor.h"
#include "dw.h"
#include "sysreel.h"
#include "tinsel.h"

#include "common/textconsole.h"

namespace Tinsel {
    static SCNHANDLE g_systemReels[SR_MAX];

    void SetSysReel(int index, SCNHANDLE reel) {
        if ((index < 0) || (SR_MAX < index)) {
            error("SetSysReel(): out of range identifier");
        }

        if (index == 0x1f) {
            warning("SetSysReel(%d, %08X), Miss handling", index, reel);
        }

        g_systemReels[index] = reel;

        // Call to DecCursor handled in caller

        return;
    }
}
