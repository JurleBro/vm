library ieee;
use ieee.std_logic_1164.all;

entity tb_bancregistres is
end tb_bancregistres;
architecture test of tb_bancregistres is
	signal tclk, twrEnable : std_logic;
	signal ts1, ts2, td : std_logic_vector (3 downto 0);
	signal tportA, tportB, tportw : std_logic_vector (31 downto 0);
	component bancregistres
		port
		( clk, wrEnable : in std_logic;
		  s1, s2, d : in std_logic_vector (3 downto 0);
		  portA, portB : out std_logic_vector (31 downto 0);
		  portw : in std_logic_vector (31 downto 0)
		);
	end component;
begin
	iut: bancregistres port map (clk => tclk, wrEnable => twrEnable, s1 => ts1, s2 => ts2, d => td, portA => tportA, portB => tportB, portw => tportw);
	vecteur : process
	begin 
		tportw <= "00000000000000000000000000000001";
		twrEnable <= '1';
		td <= "1010";
		tclk <= '0';
		wait for 5 ns;
		tclk <= '1';
		wait for 5 ns;
		tclk <= '0';
		ts1 <= "1010";
		wait for 5 ns;
	end process;
end test;
