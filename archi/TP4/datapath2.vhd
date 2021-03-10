-- Chemin de donnees pipeline
-- TP4 AS2, L3 informatique, UBO
-- S. Rubini
-- 08/02/19 SR	portage pour ghdl 
-- 18/02/20 SR	mise en forme

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity datapath is
port(
	Clk 		: in std_logic;

	PC  		: out std_logic_vector(31 downto 0);
	Src_PC 		: in std_logic;

	Src1, Src2	: in std_logic_vector(3 downto 0);

	Imm     	: in std_logic_vector(15 downto 0);
	Src_Op_B	: in std_logic; 
	Cmd_UAL 	: in std_logic_vector(1 downto 0);
	Z,N		: out std_logic;

	Src_Adr_Branch 	: in std_logic; 
	Bus_Donnees_In 	: in std_logic_vector(31 downto 0);
	Bus_Donnees_Out : out std_logic_vector(31 downto 0);
	Bus_Adresses 	: out std_logic_vector(31 downto 0);
	
	Banc_Src 	: in std_logic_vector(1 downto 0);
	Dest 		: in std_logic_vector(3 downto 0);
	Banc_Ecr 	: in std_logic 
);
end datapath;

architecture behavior of datapath is
	-- banc de registres
	type registres is array (0 to 15) of std_logic_vector(31 downto 0);
	signal banc		 : registres;
	signal s_banc_A, s_banc_B, e_banc : std_logic_vector(31 downto 0);
	signal A, B 		: std_logic_vector(31 downto 0) := std_logic_vector( to_unsigned(0,32) );

	-- calcul d'adresses instruction
	-- pas de reset ! pc =0 a l'intialisation
	signal pc_int, e_pc 	: std_logic_vector(31 downto 0) := std_logic_vector( to_unsigned(0,32) );
	signal e_adr_bra 	: std_logic_vector(31 downto 0);
	signal return_branch 	: std_logic_vector(31 downto 0); -- return ou branch
	signal e_pc1 		: std_logic_vector(31 downto 0);
	signal PC1, PC2, PC3, PC4 : std_logic_vector(31 downto 0) := std_logic_vector( to_unsigned(0,32) );
	signal adr_bra 		: std_logic_vector(31 downto 0);

	-- ual
	signal ual_A, ual_B 	: std_logic_vector(31 downto 0);
	signal s_ual 		: std_logic_vector(31 downto 0);
	signal s, s1 		: std_logic_vector(31 downto 0);

	-- acces memoire
	signal RDM_in, RDM_out 	: std_logic_vector(31 downto 0);

begin
	-- registre PC
	PC <= pc_int;
	e_pc <= return_branch when Src_PC = '0'
		else e_pc1;
	process(Clk)
	begin
		if Clk'event and Clk='0' then
			pc_int <= e_pc;
			pc1 <= e_pc;
		end if; 
	end process;
	e_pc1 <= std_logic_vector( unsigned(pc_int) + to_unsigned(4,32) );

	
	-- banc de registres
	process(Clk)
	begin
		if Clk'event and Clk='0' and banc_Ecr='1' then
			banc( to_integer(unsigned(Dest)) ) <= e_banc;
		end if; 
	end process;
	
	s_banc_A <= banc( to_integer(unsigned(Src1)) ) when Src1 /= "0000" 
		else std_logic_vector(to_unsigned(0,32));
	s_banc_B <= banc( to_integer(unsigned(Src2)) ) when Src2 /= "0000" 
		else std_logic_vector( to_unsigned(0,32) );
	
	-- registre pipeline DI/EX
	DI_EX : process(Clk)
	begin
		if Clk'event and Clk='0' then
			A <= s_banc_A;
			B <= s_banc_B;
			PC2 <= PC1;
		end if;
	end process;

      -- UAL
	ual_B <= B when Src_OP_B = '1'
            else std_logic_vector( resize( signed(Imm), 32) );

	ual_A <= A;

	s_ual <= std_logic_vector( unsigned(ual_A) + unsigned(ual_B) ) when Cmd_UAL="00"
	   else	 std_logic_vector( unsigned(ual_A) - unsigned(ual_B) ) when Cmd_UAL="01"
	   else	 ual_A;
	Z <= '1' when s_ual=std_logic_vector( to_unsigned(0, 32) )
	  else '0';
	N <= s_ual(31);

	e_adr_bra <= std_logic_vector( signed(PC2) + resize(signed(imm), 32) );
 
	-- registres pipelines EX_MEM
	EX_MEM : process(Clk)
	begin
		if Clk'event and Clk='0' then
			S <= s_ual;
			RDM_out <= B;
			PC3 <= PC2;
			adr_bra <= e_adr_bra;
		end if;
	end process;

	return_branch <= adr_bra when Src_Adr_Branch='1' else S;

	-- bus memoire
	Bus_Adresses <= S;
	Bus_Donnees_Out <= RDM_out;

	-- registres pipelines MEM/ER
	MEM_ER: process(Clk)
	begin
		if Clk'event and Clk='0' then
			S1 <= S;
			RDM_in <= Bus_Donnees_In;
			PC4 <= PC3;
		end if;
	end process;

	e_banc <= S1  when Banc_Src="01" 
	     else PC4 when Banc_Src="10"
	     else RDM_in;
end behavior;
