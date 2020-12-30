- SWD (Serial Wire Debug): Use for M3 or upper
2 pin (debug) + 1 pin (Trace)

- The physical layer of SWD consists of two lines
  + SWDIO: a bidirectional data line
  + SWCLK: a clock driven by the host


- JTAG: is the tranditional mechanisc for debuf connection for ARM7/9 family

- Cach debug khi dung printf:
  1. Debug as -> Debug Configurations -> Debugger -> Check enable Serial Wire Viewer
  2. Run Debug -> Window -> Show View -> SWV -> SWV ITM Data console
  3. In SWV ITM Data console -> Confuge trace -> check in bit 0
  4. Stop debug -> Resume


- Open OCD Debugger
