/**
 * \mainpage 8x8 dotmatrix with control module
 * \author Maik Wöhl
 * \date May 2020
 *
 * \image html kicad_3d.png width=350
 */
#include <stdint.h>
#include <stddef.h>

#include "../inc/future.h"
#include "../inc/shift_register.h"
#include "../inc/dip_switch.h"
#include "../inc/matrix.h"
#include "../inc/patterns.h"


static uint8_t* pattern = NULL;

void setup(void) {
    sr_init();
    sr_clear();
    sr_flush();

    ds_init();
    matrix_init();
    uint8_t pattern_selection = ds_read();
    if (pattern_selection < MAX_PATTERNS)
        pattern = patterns[pattern_selection];
    else
        pattern = patterns[0];
}

/**
 * col_idx: 0..7 -> iterates over columns of pattern
 * col: selects every column individually by shifting a bit by 1
 *      from right to left.
 */
void loop(void) {
    static uint8_t col_idx = 0;
    uint8_t* col = matrix_scan();

    /**
     * pattern points to the base of the selected pattern array.
     * *(pattern + col_idx) will select the byte in memory what should
     * be displayed. So we pass the memory address (pointer value) to the
     * `matrix_set()` function.
     */
    uint8_t* row = pattern + col_idx;
    matrix_set(row, col);

    col_idx = (col_idx == MAX_COLUMNS-1) ? 0 : col_idx+1;
}
