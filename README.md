# Software Quality Project

A demo project with a C library and a Python module, built and analysed via `make`.

## Requirements

| Tool | Purpose |
|------|---------|
| CMake ≥ 3.14 | C build system |
| clang-tidy | C static analysis |
| Python ≥ 3.10 | Python runtime |
| pip | Python package manager |

## Make targets

| Target | Description |
|--------|-------------|
| `make build` | Configure and build the C project with CMake |
| `make test` | Run C unit tests (Unity via ctest) and Python tests (pytest) |
| `make check` | Static analysis: clang-tidy for C, ruff for Python |
| `make clean` | Remove all build artifacts |
| `make install-deps` | Install Python dependencies from `requirements.txt` |

## Project structure

```
.
├── c/                      # C library (CMake + Unity)
│   ├── CMakeLists.txt
│   ├── include/calculator.h
│   ├── src/calculator.c
│   └── tests/test_calculator.c
├── python/                 # Python module (pytest + ruff)
│   ├── calculator.py
│   ├── pyproject.toml
│   └── tests/test_calculator.py
├── .github/workflows/ci.yml
├── .clang-tidy
├── Makefile
└── requirements.txt
```

## CI (GitHub Actions)

Four jobs run on every push to `main` and every pull request:

- **C – Build & Test**: CMake build + ctest
- **C – Static Analysis**: clang-tidy
- **Python – Tests**: pytest
- **Python – Static Analysis**: ruff

All four must pass before a PR can be merged.
