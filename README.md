# Proven-Correct Trustworthy CPS Demo: Controller + CBMC + TLA+ + AI Detector

An end-to-end demo of how to build and verify safety for cyber-physical systems:
1. C++ controller with explicit safety logic
2. Code-level verification with CBMC
3. System-level verification with TLA+
4. An AI anomaly detector, with proofs that safety holds even if the AI is wrong

## Why this repo exists
Safety for real systems cannot rely on AI guesses. This project shows a layered approach where the controller enforces hard safety guarantees, verified at the code and system levels, while AI assists.

## Repository layout
```
.
├─ controller/          # C++ FSM controller and unit tests
├─ cbmc/                # Harnesses, property checks, CBMC configs
├─ tla/                 # TLA+ specs, properties, model configs
├─ ai/                  # Simple anomaly detector, fault injection demos
└─ docs/                # Diagrams, notes, results
```

## Quick start
You can start with just the controller.

```bash
# Clone
git clone https://github.com/MKapuria/verified-conveyor-controller.git
cd verified-conveyor-controller//controller

# Build with CMake (Linux or macOS)
cmake -S . -B build
cmake --build build --config Release

# Build with MSVC (Windows PowerShell)
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release

# Run
./build/bin/controller_demo    # Linux or macOS
.\build\Release\controller_demo.exe    # Windows
```

Expected output is a short log of states and safety checks. See `controller/README.md` for details.

## Roadmap
- [x] C++ FSM controller with safety interlocks and fault handling
- [ ] CBMC checks for:
  - state invariants and guarded transitions
  - array bounds, integer overflows, assertions
  - no unsafe state reachable given preconditions
- [ ] TLA+ system model:
  - plant + controller interaction
  - safety and liveness properties
  - fault and delay injection
- [ ] AI anomaly detector:
  - demonstrate false positives and false negatives
  - show controller safety still holds under AI failure
- [ ] Docs: results, diagrams, short writeups

## Tech stack
- C++
- CBMC
- TLA+
- Python for scripts and AI demo

## License
MIT
