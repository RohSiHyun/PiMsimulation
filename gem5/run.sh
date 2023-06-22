#!/bin/sh


./build/RISCV/gem5.opt ./configs/example/se.py --cmd=progs/pim_test --cpu-type=TimingSimpleCPU --mem-type=Ramulator --ramulator-config=../ramulator/configs/DDR4-config.cfg > debug_pim

./build/RISCV/gem5.opt ./configs/example/se.py --cmd=./progs/nop_test --cpu-type=TimingSimpleCPU --mem-type=Ramulator --ramulator-config=../ramulator/configs/DDR4-config.cfg > debug_mem

