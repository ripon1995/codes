/**
 * 1. Precalculate the # of consecutive ones (vertically) in the matrix,
 *    --> which we are actually calculating the height of each column/histogram
 *
 * [0,0,1]      [0,0,1]
 * [1,1,1] -->  [1,1,2]
 * [1,0,1]      [2,0,3]
 *
 * 2. Sort each row in decreasing order (Theoretically)
 *    We need to do this, so that we are ensuring the taller
 *    histograms are always before the shorter ones, which
 *    allows us to calculate the area later as (current height) * (current width)
 *                             Row 0:    Row 1:      Row 2:
 * [0,0,1]      [0,0,1]       [1,0,0]   [0,0,1]     [1,0,0]
 * [1,1,1] -->  [1,1,2]  -->  [2,1,1]   [1,1,2]     [2,1,1]
 * [1,0,1]      [2,0,3]       [3,0,2]   [2,0,3]     [3,2,0]
 *
 * And actually, we don't need to sort the entire matrix everytime when we
 * sort a single row. We can just sort the single row to get the largest submatrix
 * as if the entire matrix is sorted, because we are able to calculate the largest matrix
 * with the information from that singly sorted row.
 *
 * For example, if we only sort row 2 (last row):
 *                           Row 2:
 * [0,0,1]      [0,0,1]     [0,0,1]
 * [1,1,1] -->  [1,1,2]     [1,1,2]
 * [1,0,1]      [2,0,3] --> [3,2,0]
 *
 * At row=2, col=0,
 *      --> we know there are 3 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=3) * (width=1)=3
 * At row=2, col=1,
 *      --> we know there are 2 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=2) * (width=2)=4
 *          --> which you may notice, width=(col+1)
 * At row=2, col=2
 *      --> we know there are 0 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=0) * (width=3)=0
 *
 * Let's go back and sort just row 0, and row 1
 *                           Row 0:
 * [0,0,1]      [0,0,1] --> [1,0,0]
 * [1,1,1] -->  [1,1,2]     [1,1,2]
 * [1,0,1]      [2,0,3]     [2,0,3]
 * - At row=0, col=0,
 *      --> we know there is only 1 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=1)*(width=1)=1
 * - At row=0, col=1 & col=2
 *      --> we know there are 0 consecutive '1' vertically from the top
 *      --> there are submatrix/rectangle of (height=0)*(width=2,3)=0 for both
 *
 *                           Row 1:
 * [0,0,1]      [0,0,1]     [0,0,1]
 * [1,1,1] -->  [1,1,2] --> [2,1,1]
 * [1,0,1]      [2,0,3]     [2,0,3]
 * - At row=1, col=0
 *      --> we know there are 2 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=2)*(width=1)=2
 * - At row=1, col=0
 *      --> we know there is only 1 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=1)*(width=2)=2
 * - At row=1, col=1,
 *      --> we know there is only 1 consecutive '1's vertically from the top
 *      --> there is a submatrix/rectangle of (height=1)*(width=3)=3
 *
 */