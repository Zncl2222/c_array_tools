/*
 * Copyright 1996 - 2002, Makoto Matsumoto and Takuji Nishimura,
 * All rights reserved.
 *
 * Copyright 2022, Jian Yu, Chen
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. The names of its contributors may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

# include <stdlib.h>
# include <math.h>
# include "c_array.h"


void mt19937_init(mt19937_state* state, unsigned int seed) {
    state->state[0] = seed;

    for (int i = 1; i < MT_N; i++) {
        state->state[i] = (1812433253 * (state->state[i-1] ^ (state->state[i-1] >> 30)) + i);
    }

    state->index = MT_N;
}

unsigned int mt19937_generate(mt19937_state* state) {
    if (state->index >= MT_N) {
        for (int i = 0; i < MT_N-MT_M; i++) {
            unsigned int x = (state->state[i] & MT_UPPER_MASK) | (state->state[i+1] & MT_LOWER_MASK);
            state->state[i] = state->state[i+MT_M] ^ (x >> 1) ^ ((x & 1) * MT_MATRIX_A);
        }

        for (int i = MT_N-MT_M; i < MT_N-1; i++) {
            unsigned int x = (state->state[i] & MT_UPPER_MASK) | (state->state[i+1] & MT_LOWER_MASK);
            state->state[i] = state->state[i+(MT_M-MT_N)] ^ (x >> 1) ^ ((x & 1) * MT_MATRIX_A);
        }

        unsigned int x = (state->state[MT_N-1] & MT_UPPER_MASK) | (state->state[0] & MT_LOWER_MASK);
        state->state[MT_N-1] = state->state[MT_M-1] ^ (x >> 1) ^ ((x & 1) * MT_MATRIX_A);

        state->index = 0;
    }

    unsigned int y = state->state[state->index++];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);

    return y;
}

double random_normal(mt19937_state* state) {
    double x = mt19937_generate(state) / 4294967296.0f;
    double y = mt19937_generate(state) / 4294967296.0f;
    double z = sqrtf(-2 * log(x)) * cosf(2 * M_PI * y);
    return z;
}
