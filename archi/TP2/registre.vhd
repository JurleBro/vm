library ieee;
use ieee.std_logic_1164.all;

entity registre is
	port
	( clk : in std_logic;
	  e : in std_logic_vector (7 downto 0);
	  e : in std_logic_vector (7 downto 0)
	);
end registre;
architecture comp of registre is
begin
	reg : process(clk)
	begin
		if clk'event and clk='0' then
			s<=e;
		end if;
	end process;
end comp;
