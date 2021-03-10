#!/bin/bash

ghdl -a clock.vhd
ghdl -e clock
ghdl -r clock --stop-time=500ns --vcd=clock.vcd
gtkwave clock.vcd
