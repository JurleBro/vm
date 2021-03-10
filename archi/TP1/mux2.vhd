library ieee;
use ieee.std_logic_1164.all;

entity mux2 is
port (
	a,b,c : in std_logic;
	s	  : out std_logic
);
end mux2;
architecture beh of mux2 is
begin
	s <= a when c='0' else b;
end beh;
