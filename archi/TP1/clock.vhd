library ieee;
use ieee.std_logic_1164.all;

entity clock is
end clock;
architecture comport of clock is
signal clk : std_logic;
begin
	clock : process
	begin
		clk <= '0';
		wait for 5 ns;
		clk <= '1';
		wait for 5 ns;
	end process;
end comport;
