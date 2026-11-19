# Push_swap — Medium Chunk Sort (Learning Project)

This is a simple, runnable **Medium strategy only** example for the 42 Push_swap v1.2 subject. It uses approximately sqrt(n) rank-based chunks and only the standard Push_swap stack instructions to change the order of values.

**This is not a complete 42 submission.** Your subject also requires Simple, Complex, and Adaptive strategies, all 11 stack operations, `--bench`, initial disorder measurement, a README listing both students and their contributions, and final 42 Norm and benchmark verification.

## Build and run

```bash
make
./push_swap --medium 8 3 6 1 9 2 5 7 4
./push_swap 8 3 6 1 9 2 5 7 4
./push_swap 1 2 3    # Already sorted: no output
make fclean
```

The example reads each integer from a separate argument. One quoted string like `"8 3 6"` is not supported by this learning parser.

## How it works — without complex tricks

1. `parse.c` and `parse_value.c`: validate all integer arguments, rejecting duplicates and out-of-range numbers.
2. `rank.c`: give each value a rank from 0 to n-1. The smallest has rank 0. This avoids worrying about negative numbers and large value gaps.
3. `chunk_sort.c` (`chunk_width`): pick a chunk width of `ceil(sqrt(n))`. The number of chunks is also approximately `sqrt(n)`.
4. `collect_chunk`: scan stack A. Move a value in the current rank interval to stack B using `pb`. Otherwise use `ra` to look at the next value.
5. `align_stack`: use `ra` or `rra` so the previously completed values remain in ascending order at the bottom of A. We find the last completed rank (`low - 1`) and rotate it to the bottom.
6. `chunk_return.c`: find the smallest value in B, rotate B using `rb` or `rrb` to bring it to the top, then `pa` it to A and `ra` to append it to the sorted portion.
7. Repeat until all chunks have been processed. A is ascending; B is empty.

Example with n=9: chunk width = 3. The three rank intervals are `[0,3)`, `[3,6)`, and `[6,9)`.

### Why this targets O(n * sqrt(n)) Push_swap operations

There are approximately `sqrt(n)` chunks, with at most approximately `sqrt(n)` values per chunk. Collecting and realigning A costs O(n) emitted instructions per chunk. Returning each small chunk from B requires at most O(width^2) rotation instructions, which is O(n) per chunk. So across the chunks the number of emitted instructions is O(n * sqrt(n)).

Rank assignment here uses a clear O(n^2) C comparison loop for teaching purposes. The 42 v1.2 subject specifically measures the sorting *complexity class* using the number of emitted Push_swap operations; you can optimize the rank preprocessing separately later.

## Files

- `main.c` — start program, process optional `--medium`, free memory
- `parse.c`, `parse_value.c` — validate integers
- `rank.c` — assign ranks and detect already-sorted input
- `ops_push.c` — `pa`, `pb` directly (no `move_top()` helper)
- `ops_rotate.c` — `ra`, `rb` directly (no rotation helper)
- `ops_reverse.c` — `rra`, `rrb` directly (no rotation helper)
- `chunk_sort.c` — chunk size, collect, align, main sorting loop
- `chunk_return.c` — select minimum from B and return it to A
- `push_swap.h`, `Makefile`

## Testing status

Compiled using `cc -Wall -Wextra -Werror`. Randomized instruction-level correctness tests passed for sizes 1–40 and for samples of sizes 100, 200, and 500. In the tested 500-number random samples, operation counts ranged around 10,350–10,620 (the subject's minimum passing threshold is fewer than 12,000). This is not a guarantee for every input and is not an official 42 evaluation.

Norminette is **not installed in this testing environment**, so run it on your 42 Mac. Add your own 42 file headers and check your campus's exact Norm requirements before integrating the code.

## Operations implementation

This revised version implements `pa`, `pb`, `ra`, `rb`, `rra`, and `rrb` directly inside their named functions. It does not define `move_top`, `rotate_up`, or `rotate_down`. Only the recognized Push_swap instructions are emitted. The algorithm helpers (`collect_chunk`, `align_stack`, `bring_min_to_top`) calculate or organize legal moves; their names are **not** printed as instructions.

## Small-input optimization added in this revision

This revision improves the number of moves generated for small inputs while leaving
`chunk_sort.c` and `chunk_return.c` unchanged. The main function checks sorted
input first, then:

- For 2 values, `sort_small()` emits `sa` only if necessary.
- For 3 values, `sort_three()` uses a minimal sequence of `sa`, `ra`, or `rra`.
- For 4–12 values, `sort_small()` brings the smallest value to the top using
  the shorter rotation direction, pushes it to B, sorts the final 3 values,
  and returns the saved minimums with `pa`.
- For 13 or more values, the previous rank-based sqrt(n) chunk algorithm runs.

This constant-size exception does not change the asymptotic O(n sqrt(n)) bound
of the Medium strategy. The small-input code is an optimization, not an
additional official Push_swap instruction. `min_index`, `push_smallest`, and
`sort_three` are internal algorithm helpers; the only emitted instructions
remain official ones (`sa`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`).

Files added in this revision:
- `ops_swap.c`: direct implementation of the official `sa` operation.
- `small_sort.c`: small-input handling using existing official operations.

The `main.c` strategy dispatcher, `push_swap.h`, and `Makefile` were updated to
include them. This still is a Medium-only learning prototype; the final 42
submission must include the other required strategies and benchmark features.
As with the previous version, Norminette has not been verified.
