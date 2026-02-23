# C Fundamentals

This folder contains foundational C exercises focused on compilation flow, modular code, debugging, and libraries.

## Structure

- `Debug_code` — debug-oriented program with several fixed bug scenarios.
- `part_1` — multi-file C project (`main.c` + `other.c/.h`).
- `part_2` — project organized with `Include/` and `src/` directories.
- `part_3` — static library workflow using `libmathlib.a`.
- `part_4` — shared library workflow using `libadvmath.so`.
- `part_5` — combined static + shared libraries in one executable.

## Prerequisites

- `gcc`
- `make`
- A Unix-like shell (`bash`, `Git Bash`, or `WSL`) since the makefiles use `rm`.

## Build and Run

Run the following from the `C-fundamentals` root.

### Debug_code

```bash
cd Debug_code
make
./program
make clean
```

### part_1

```bash
cd part_1
make program
./program
make clean
```

### part_2

```bash
cd part_2
make
./Project
make clean
```

### part_3

```bash
cd part_3
make
./program
make clean
```

### part_4

```bash
cd part_4
make
./program
make clean
```

### part_5

```bash
cd part_5
make
./program
make clean
```

## Notes

- In parts using shared libraries (`part_4`, `part_5`), runtime linking behavior can depend on environment configuration.
- If a shared library is not found at runtime, use your shell/environment loader path settings accordingly.
