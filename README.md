# Proven-Correct Trustworthy CPS Demo: Controller + CBMC + TLA+ + AI Detector

An end-to-end demo of how to build and verify safety for cyber-physical systems:
1. C++ controller with explicit safety logic
2. Code-level verification with CBMC
3. System-level verification with TLA+
4. An AI anomaly detector, with proofs that safety holds even if the AI is wrong

![ProjectDiagram][Project diagram]

## Why this repo exists
Safety for real systems cannot rely on AI monitoring systems alone. This project shows a layered approach where the controller enforces hard safety guarantees, verified at the code and system levels, while AI assists as an anomaly detector.

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

1. **Clone or download** this repository.
2. Open the `controller` folder in any C++17-compatible IDE (Visual Studio, CLion, Xcode, Code::Blocks, etc.).
3. Set `main.cpp` as the entry point.
4. Build and run.

Expected output is a short log of states and safety checks. See `controller/README.md` for details.

## Roadmap
- [x] C++ FSM controller with safety interlocks and fault handling
- [ ] CBMC code-level verification
- [ ] TLA+ system-level modeling
- [ ] AI anomaly detector and safety validation under AI failure
- [ ] Documentation and results

## Tech stack
- C++17
- CBMC
- TLA+
- Python

## License
MIT
