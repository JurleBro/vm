#!/bin/bash

ghdl -a bancregistres.vhd
ghdl -a tb_bancregistres.vhd
ghdl -e tb_bancregistres
ghdl -r tb_bancregistres --stop-time=500ns --vcd=tb_bancregistres.vcd
gtkwave tb_bancregistres.vcd
