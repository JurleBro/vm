-- Unite de controle processeur pipeline
-- Version à compléter
-- Auteur : 
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity control_unit is
port (	Clk 		: in std_logic;

	Inst 		: in std_logic_vector(31 downto 0);
	Src_PC 		: out std_logic;

	Src1, Src2	: out std_logic_vector(3 downto 0);

	Imm     	: out std_logic_vector(15 downto 0);
	Src_Op_B 	: out std_logic; 	
	Cmd_UAL 	: out std_logic_vector(1 downto 0);
	Z,N		: in std_logic;
	
	Src_Adr_Branch 	: out std_logic; 	
	RW, Bus_Val 	: out std_logic;

	Banc_Src 	: out std_logic_vector(1 downto 0);
	Dest 		: out std_logic_vector(3 downto 0);
	Banc_Ecr 	: out std_logic 
);
end control_unit;

architecture beh of control_unit is

signal di_ri :  std_logic_vector(31 downto 0) := "00000000000000000000000000000000";
signal di_src_PC, ex_src_pc, mem_src_pc : std_logic := '1';
...
	
begin

	-- registre RI
	ri : process(clk)
	begin
		if Clk'event and Clk='0' then
			di_ri <= Inst;
		end if;
	end process;

	-- decodeur
	---------------------
	-- a vous
	---------------------
	case di_ri(31 downto 28) is
		when "0001" => --addi
			Src_PC 	<= '1';
			Banc_Src 	<= "01";
			Banc_Ecr	<= '1';
			Cmd_UAL         <= "00";
			Src_Op_B        <= '0';
			Src_Adr_Branch  <= '-';
		when "0010" => --sub
		
		when "0011" => --sw
		
		when "0100" => --lw
		
		when "0101" => --jsr
		
		when "0110" => --beq
		
		when "0111" => --bra
		
		when "1000" => --rts
		
	end case;
	codeop <= di_ri(31 downto 28);
	Src_1 <= di_ri(27 downto 24);
	Src_2 <= di_ri(23 downto 20);
	Dest <= di_ri(19 downto 16);
	Imm <= di_ri(15 downto 0);

	-- registres pipeline
	---------------------
	-- a vous
	---------------------

end beh;
