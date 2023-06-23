# PiMsimulation
PiM simulation with Gem5 &amp; Ramulator

## Introduction

This repository is for simulating PiM using Gem5 -the process simulator- and Ramulator -the memory simulator.
PiM model simulated in this repository is quite simple. It receives the address, and increases the value stored in the given address by 1.

## Environment

* **Server environment**: Ubuntu 20.04
* **Simulated CPU architecture**: RISCV
* **Simulated Memory**: DDR4

## Directory / File info

![image](https://github.com/RohSiHyun/PiMsimulation/assets/49300588/c211f90e-dc14-4f1f-a33b-0a895db7f00e)
Figure: Control & Data flow while simlating PiM using Gem5 & Ramulator

### Ramulator

* **Main.cpp:** Receive parameter in ramulator runtime & execute `get_dramtrace_request` (Processor.cpp)
* **Processor.cpp:** determine the type of request (read / write / pim)
* **Memory.h / Controller.h:** execute `memory.tick()`
* **DDR4.h:** you can adjust the variable `nPim` here
  - `nPim`: Clocks taken for executing pim calculation.

### Gem5

* **src/arch/riscv/isa/**
  - **decoder.isa:** decode instruction and generate request
  - **mem.isa:** definition for generating and operating request
* **src/cpu/**
  - **simple/atomic.hh:** definition for function of simple atomic CPU
  - **simple/timing.cc:** definition for function of simple timing CPU (definition for `pimMem`)
* **src/mem/**
  - **abstract_memory.cc:** abstraction layer for memory models
  - **ramulator.cc:** modified lines in `recvTimingReq` in order to send PIM type request
* **progs/**
  - **mem_test.c, pim_test.c, nop_test.c:** test files

### Cross compiler

* **xcompiler/riscv-opcodes/:** allocating match and mask bits for custom instruction
* **xcompiler/riscv-gnu-toolchain/:** modify compiler and build it


## Build

```
# Solve gem5 & ramulator Dependency
sudo apt install build-essential git m4 scons zlib1g zlib1g-dev \
libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \ 
python3-dev python-is-python3 libboost-all-dev pkg-config


# Solve cross compiler Dependency
sudo apt-get install autoconf automake autotools-dev curl python3 libmpc-dev \
libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc \
zlib1g-dev libexpat-dev device-tree-compiler


# Build PiM Simulator
git clone https://github.com/RohSiHyun/PiMsimulation.git
cd PiMsimulation/gem5
scons build/RISCV/gem5.opt -j 32


# Build Cross compiler
cd ../xcompiler
cd riscv-gnu-toolchain
./configure --prefix={absolute path for installing cross compiler}
make -j 32


# Execute simulation
./run.sh


# You can see more details by looking into run.sh
# run.sh builds debug_pim and debug_mem files and you can see the simulation results
```

## Error Handling

If build fails with message "**config/have_deprecated_namespace.hh: No such file or directory**", please modify `gem5/src/base/compiler.hh`
> 1. delete line 46 (#include "config/have_deprecated_namespace.hh")
> 2. add new line (#define HAVE_DEPRECATED_NAMESPACE 1)

**This version is uploaded on `NSsolution` branch**
