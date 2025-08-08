# verified-conveyor-controller
This repository is to formally verify the safety of an ICS controller with an integrated AI monitoring system

THere are 4 parts to this project. 
1) Build a controller in C++ in a finite-state machine format
2) Verify the controller on the code level using CBMC
3) Verify the controller on the system design level using TLA+
4) Apply an AI monitoring system and prove that the controller remains safe even if the AI is wrong
