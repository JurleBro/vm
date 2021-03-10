library ieee;
use ieee.std_logic_1164.all;

entity tb_mux2 is
end tb_mux2;
architecture test of tb_mux2 is
signal ta, tb, tc, ts : std_logic;
component mux2
port (
	a,b,c : in std_logic;
	s	  : out std_logic
);
end component;
begin
	iut: mux2 port map (a => ta, b => tb, c => tc, s => ts );
	ta <= '0', '0' after 10 ms, '0' after 20 ms, '0' after 30 ms, '1' after 40 ms, '1' after 50 ms, '1' after 60 ms, '0' after 70 ms;
	tb <= '0', '0' after 10 ms, '1' after 20 ms, '1' after 30 ms, '0' after 40 ms, '0' after 50 ms, '1' after 60 ms, '0' after 70 ms;
	tc <= '0', '1' after 10 ms, '0' after 20 ms, '1' after 30 ms, '0' after 40 ms, '1' after 50 ms, '1' after 60 ms, '0' after 70 ms;
end test;
