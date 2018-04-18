/*
Copyright © 2018 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
     that you wrote the original software. If you use this software in a
     product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include "rnd.h"

static uint32_t get_random(uint32_t *seed)
{
	uint32_t result;
	uint32_t *z = seed;
	uint32_t *w = &seed[1];
	*z = 36969 * (*z & 65535) + (*z >> 16);
	*w = 18000 * (*w & 65535) + (*w >> 16);
	result = (*z << 16) + *w;
	return result;
}

static uint32_t random_in_range(uint32_t *seed, uint32_t low, uint32_t high)
{
	uint32_t range = high - low + 1;
	uint32_t rand_num = get_random(seed);
	return (rand_num % range) + low;
}

inline uint64_t rnd_uint64(uint64_t *seed)
{
	return random_in_range((uint32_t *)seed, 0, 100);
}

