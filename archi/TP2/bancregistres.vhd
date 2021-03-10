library ieee;
use ieee.std_logic_1164.all, ieee.numeric_std.all;

entity bancregistres is
	port
	( clk, wrEnable : in std_logic;
	  s1, s2, d : in std_logic_vector (3 downto 0);
	  portA, portB : out std_logic_vector (31 downto 0);
	  portw : in std_logic_vector (31 downto 0)
	);
end bancregistres;
architecture beh of bancregistres is
type registres is array(0 to 15) of std_logic_vector(31 downto 0);
signal banc : registres;
begin
	portA <= banc(to_integer(unsigned(s1)));
	portB <= banc(to_integer(unsigned(s2)));
	ecriture : process(clk)
	begin
		if clk'event and clk='0' and wrEnable='1' then
			banc(to_integer(unsigned(d))) <= portw;
		end if;
	end process;
end beh;
