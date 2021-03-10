-- Banc de test du processeur pipeline
-- TP 4 AS2, S. Rubini
-- 08/02/19 SR	portage ghdl
-- 17/02/20 SR  mise en forme
--	    SR	ajout de RW et bus_donnees_out dans la liste 
--		de sensibilité mémoire data

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_processeur is
end tb_processeur;

architecture test of tb_processeur is
	component processeur
       	  port (
        	Clk 		: in std_logic;
        	PC  		: out std_logic_vector(31 downto 0);
        	Inst  		: in std_logic_vector(31 downto 0);
        	Bus_Donnees_In 	: in std_logic_vector(31 downto 0);
        	Bus_Donnees_Out : out std_logic_vector(31 downto 0);
        	Bus_Adresses 	: out std_logic_vector(31 downto 0);
        	RW 		: out std_logic;
        	Bus_Val 	: out std_logic
	  );
	end component;

	signal Clk 		: std_logic := '0';

	-- interface processeur
	signal PC  		: std_logic_vector(31 downto 0);
	signal inst  		: std_logic_vector(31 downto 0);
	signal bus_donnees_in 	: std_logic_vector(31 downto 0);
	signal bus_donnees_out 	: std_logic_vector(31 downto 0);
	signal bus_adresses 	: std_logic_vector(31 downto 0);
	signal RW 		: std_logic; 
	signal bus_val 		: std_logic;

	type memoire is array(0 to 255) of std_logic_vector(31 downto 0);

	-- les instructions du programme test sont codees ici
	signal program : memoire :=
--		un seul format de codage d'instructions pour simplifier
--		codeop src1   src2   dest   immediat
		(
		"0001"&"0000"&"0000"&"0010"&"0000000001010110", -- 00 ADDI R0, 56, R2
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 04 NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 08 NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 0C NOP
		"0010"&"0000"&"0010"&"0100"&"0000000000000000", -- 10 SUB R0, R2, R4
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 14 NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 18 NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 1C NOP
		"0011"&"0010"&"0100"&"0000"&"0000000000010010", -- 20 SW R4, 12(R2) 
		"0100"&"0010"&"0000"&"0101"&"0000000000010010", -- 24 LW 12(R2), R5
		"0101"&"0000"&"0000"&"0110"&"0000000000101100", -- 28 JSR 2C, R6
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 2C NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 30 NOP 
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 34 NOP 
		"0111"&"0010"&"0100"&"0000"&"0000000000010000", -- 38 BEQ  R2, R4, 10
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 3C NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 40 NOP 
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 44 NOP 
		"1000"&"0000"&"0000"&"0000"&"1111111110110100", -- 48 BRA -4C
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 4C NOP
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 50 NOP 
		"0000"&"0000"&"0000"&"0000"&"0000000000000000", -- 54 NOP 
		"0110"&"0110"&"0000"&"0000"&"0000000001010110", -- 58 RTS R6 
		others => (others=> '0')
		);
	signal data : memoire;


begin

	cpu0 : processeur port map(
        	Clk => clk,
       		PC => PC,
        	Inst => inst,
        	Bus_Donnees_In => bus_donnees_in,
        	Bus_Donnees_Out => bus_donnees_out,
        	Bus_Adresses => bus_adresses,
        	RW => RW,
        	Bus_Val=> bus_val
	);

	-- horloge systeme
	clk <= not(clk) after 5 ns;

	-- lecture memoire d'instruction
	Inst <= program( to_integer(unsigned(pc(7 downto 2))) );  
	-- memoire 32 bits, adresses d'octets 
	-- on aligne les acces en oubliant les bits de poids faibles

	-- ecriture ou lecture memoire de donnees
	process(bus_adresses, bus_donnees_out, bus_val, RW)
	begin
		if bus_val= '1' and RW='0' then
			data( to_integer(unsigned(bus_adresses(7 downto 2))) ) <= bus_donnees_out ;
		end if;
	end process;

	bus_donnees_in <= data( to_integer(unsigned(bus_adresses(7 downto 2))) ) when  bus_val= '1' and RW='1' 
		  else (others => 'Z'); -- "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

end test;


