# -*- mode:python -*-
from m5.params import *
from m5.objects.AbstractMemory import *

# A wrapper for Ramulator multi-channel memory controller
class Ramulator(AbstractMemory):
    type = 'Ramulator'
    cxx_header = "mem/ramulator.hh"
    cxx_class = 'gem5::memory::Ramulator'
    # A single port for now
    port = SlavePort("Slave port")

    config_file = Param.String("", "configuration file")
    num_cpus = Param.Unsigned(1, "Number of cpu")

    def controller(self):
        # src/mem/DRAMInterface.py have control MemCtrl example to reference
        return self