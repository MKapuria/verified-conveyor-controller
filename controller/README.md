# Controller (C++ FSM)

A safety-critical controller implemented as a finite state machine with explicit interlocks, limits, and a fault stop path. Designed to be verified with CBMC and TLA+.

## Features
- States: Idle, Running, FaultStop
- Inputs: commands, sensor values, fault flags
- Safety logic:
  - do not enter Running unless preconditions hold
  - immediate transition to FaultStop on hard fault
  - bounded outputs and simple rate limits
- Deterministic transitions with clear logs

<p align="center">
  <img src="main/docs/controllerFSM.png" alt="controllerFSM" width="500"/>
</p>


## Build and run
1. Clone or download this repository.
2. Open the `controller` folder in any C++17-compatible IDE (Visual Studio, CLion, Xcode, Code::Blocks, etc.).
3. Set `main.cpp` as the entry point.
4. Build and run.

## Example output
```
[t=0] state=Idle  cmd=Start  sensors=ok  -> checking preconditions
[t=1] state=Running  outputs=enabled
[t=2] state=Running  sensors=ok
[t=3] HARD_FAULT detected -> transitioning to FaultStop
[t=4] state=FaultStop  outputs=disabled  latched=true
```

Your output will vary depending on the scenario in `main.cpp`.

## Next steps in this repo
This controller is used by:
- `cbmc/` to verify code-level properties and memory safety
- `tla/` to verify system-level properties with the plant model
- `ai/` to test that safety holds when the anomaly detector fails
