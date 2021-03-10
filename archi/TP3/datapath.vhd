-- Chemin de donnees sequentiel
-- TP AS2, L3 informatique, UBO
-- S. Rubini
-- 09/01/19	SR	portage pour ghdl

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity datapath is
port(
	Clk : in std_logic;

	PC     : out std_logic_vector(31 downto 0);
	Src_PC : in std_logic;

	Bus_donnees_in  : in std_logic_vector(31 downto 0);
	Bus_donnees_out : out std_logic_vector(31 downto 0);
	Bus_adresses    : out std_logic_vector(31 downto 0);
	
	Src1, Src2, Dest : in std_logic_vector(3 downto 0);
	Banc_ecr : in std_logic; 

	Cmd_UAL : in std_logic_vector(1 downto 0);
	Imm     : in std_logic_vector(15 downto 0);
	Z,N	: out std_logic;
	
	Src_op_B, Src_adr_branch : in std_logic; 
	Banc_src : in std_logic_vector(1 downto 0)
);
end datapath;

architecture behavior of datapath is
	-- registres
	type registres is array (0 to 15) of std_logic_vector(31 downto 0);
	signal banc : registres;

	signal s_pc_int, e_pc : std_logic_vector(31 downto 0) 
					:= "00000000000000000000000000000000";
	signal s_banc_A, s_banc_B, e_banc : std_logic_vector(31 downto 0);

	-- calcul d'adresses
	signal adr_bra      : std_logic_vector(31 downto 0);
	signal pc_suivant   : std_logic_vector(31 downto 0);
	
	-- ual
	signal ual_A, ual_B : std_logic_vector(31 downto 0);
	signal s_ual        : std_logic_vector(31 downto 0);	

begin
	-- registre PC
	PC <= s_pc_int;
	process(Clk)
	begin
		if Clk'event and Clk='0' then
			s_pc_int <= e_pc;
		end if; 
	end process;
	pc_suivant <= std_logic_vector( unsigned(s_pc_int) + to_unsigned(4,32) );
	adr_bra <= std_logic_vector(signed(pc_suivant) + 
			resize(signed(Imm), 32)) when Src_adr_branch='1'
		else s_ual;
	
	e_pc <= adr_bra when src_pc = '0'
		else pc_suivant;

	-- banc de registres
	process(Clk)
	begin
		if Clk'event and Clk='0' and Banc_ecr='1' then
			banc(to_integer(unsigned(Dest))) <= e_banc;
		end if; 
	end process;
	e_banc <= s_ual      when Banc_src="01" 
	     else pc_suivant when Banc_src="10"
	     else Bus_donnees_in;
	s_banc_A <= banc(to_integer(unsigned(src1))) when Src1 /= "0000" 
	       else std_logic_vector(to_signed(0,32));
	s_banc_B <= banc(to_integer(unsigned(src2))) when Src2 /= "0000" 
	       else std_logic_vector(to_signed(0,32));

	
        -- UAL
	ual_B <= s_banc_B when Src_op_B = '1'
            else std_logic_vector( resize( signed(Imm), 32) );
	ual_A <= s_banc_A;

	s_ual <= std_logic_vector(signed(ual_A)+signed(ual_B)) when Cmd_UAL="00"
	   else	 std_logic_vector(signed(ual_A)-signed(ual_B)) when Cmd_UAL="01"
	   else	 ual_A;
	Z   <= '1' when s_ual=std_logic_vector(to_signed(0, 32))
	  else '0';
	N <= s_ual(31);

	-- bus memoire
	Bus_adresses <= s_ual;
	Bus_donnees_out <= s_banc_B;


end behavior;


