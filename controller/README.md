# Controller (C++ FSM)

A safety-critical controller implemented as a finite state machine with explicit interlocks, limits, and a fault stop path. Designed to be verified with CBMC and exercised in a TLA+ system model.

## Features
- States: Idle, Running, FaultStop
- Inputs: commands, sensor values, fault flags
- Safety logic:
  - do not enter Running unless preconditions hold
  - immediate transition to FaultStop on hard fault
  - bounded outputs and simple rate limits
- Deterministic transitions with clear logs

## Build and run

### Prerequisites
- CMake 3.20+
- A C++17 compiler

### Configure and build

Linux or macOS:
```bash
cmake -S . -B build
cmake --build build --config Release
```

Windows (PowerShell, MSVC):
```powershell
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release
```

### Execute
```bash
# Linux or macOS
./build/bin/controller_demo

# Windows
.\build\Release\controller_demo.exe
```

### Example output
```
[t=0] state=Idle  cmd=Start  sensors=ok  -> checking preconditions
[t=1] state=Running  outputs=enabled
[t=2] state=Running  sensors=ok
[t=3] HARD_FAULT detected -> transitioning to FaultStop
[t=4] state=FaultStop  outputs=disabled  latched=true
```

Your output will vary slightly depending on the demo scenario.

## Project structure
```
controller/
├─ include/
│  ├─ Controller.hpp
│  ├─ States.hpp
│  └─ Sensors.hpp
├─ src/
│  ├─ main.cpp            # demo harness with a simple scenario
│  ├─ Controller.cpp
│  ├─ States.cpp
│  └─ Sensors.cpp
├─ tests/                 # optional: unit tests
│  └─ test_controller.cpp
├─ CMakeLists.txt
└─ README.md
```

## How to run tests
If you use Catch2:
```bash
cmake -S . -B build -DBUILD_TESTS=ON
cmake --build build --config Debug
./build/bin/controller_tests
```

Or GoogleTest:
```bash
cmake -S . -B build -DGOOGLETEST=ON
cmake --build build --config Debug
ctest --test-dir build
```

## Coding guidance
- Keep state logic small and explicit
- Centralize guards and invariants
- Use assertions for developer checks
- Log transitions and reasons
- No dynamic allocation in the hot path

## Next steps in this repo
This controller is used by:
- `cbmc/` to verify code-level properties and memory safety
- `tla/` to verify system-level properties with the plant model
- `ai/` to test that safety holds when the anomaly detector fails

## License
MIT
