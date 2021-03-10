#!/bin/bash

ghdl -a datapath.vhd
ghdl -a tb_datapath.vhd
ghdl -e tb_datapath
ghdl -r tb_datapath --stop-time=100ns --wave=tb_datapath.ghw
gtkwave tb_datapath.ghw
