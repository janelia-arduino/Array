# Future Improvements

## Potential Follow-Up Work

- Add a clean `pixi run release-check` path for all target environments,
  including verifying whether the Teensy build should remain part of the default
  release gate.
- Decide whether the library should stay nominally source-plus-stub or become a
  clearly header-only package.
- Consider optional checked access helpers or debug assertions for
  `front()`, `back()`, and indexed access without changing the existing API.
- Expand native tests to cover more edge cases around cross-type assignment,
  capacity boundaries, and iterator use.
- Align the example set with the `Vector` repository so both libraries keep the
  same documentation and demo structure over time.
