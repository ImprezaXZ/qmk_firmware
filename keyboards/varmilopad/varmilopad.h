/* Copyright 2021 ImprezaXZ
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, k04, \
    k25, k15, k24, k14, \
    k20, k10, k12, k34, \
    k21, k11, k22,     \
    k42, k52, k32, k54, \
    k23, k13           \
) \
{ \
    { k00, k01, k02, k04 }, \
    { k25, KC15, k24, k14 }, \
    { k20, k10, k12, k34 }, \
    { k21, k11, k22, KC_NO }, \
    { k42, k52, k32, k54 }, \
    { k23, k13, KC_NO, KC_NO }, \
}
