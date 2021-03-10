-- Banc de test du chemin de donnees
-- TP AS2, L3 informatique, UBO
-- S. Rubini
-- 

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity tb_datapath is
end tb_datapath;

architecture test of tb_datapath is

	-- declaration de l'interface du composant chemin de donnees
	component datapath
	port (	Clk : in std_logic;
		PC  : out std_logic_vector(31 downto 0);
		Src_PC : in std_logic;

		Bus_donnees_in : in std_logic_vector(31 downto 0);
		Bus_donnees_out : out std_logic_vector(31 downto 0);
		Bus_adresses : out std_logic_vector(31 downto 0);
	
		Src1, Src2, Dest : in std_logic_vector(3 downto 0);
		Banc_Ecr : in std_logic; 

		cmd_ual : in std_logic_vector(1 downto 0);
		imm     : in std_logic_vector(15 downto 0);
		Z,N	: out std_logic;
	
		Src_Op_B, Src_adr_branch : in std_logic; 	
		Banc_src : in std_logic_vector(1 downto 0));
	end component;

	signal clk    : std_logic := '0';
	signal PC     : std_logic_vector(31 downto 0);
	signal Src_PC :  std_logic;
	
	signal Src1, Src2, Dest : std_logic_vector(3 downto 0) := "0000";
	signal Banc_Ecr :  std_logic; 

	signal Cmd_ual :  std_logic_vector(1 downto 0);
	signal Imm     :  std_logic_vector(15 downto 0);
	signal Z,N     :  std_logic;
	
	signal Src_Op_B, Src_adr_branch : std_logic; 
	signal Banc_src        :  std_logic_vector(1 downto 0);

	signal Bus_Donnees_In  : std_logic_vector(31 downto 0);
	signal Bus_Donnees_Out : std_logic_vector(31 downto 0);
	signal Bus_Adresses    : std_logic_vector(31 downto 0);

begin
	-- generation du signal d'horloge 100MHz
	clk <= not(clk) after 5  ns;

	-- instanciation du chemin de données sequentiel	
	dp : datapath port map (
		Clk => Clk,
		PC => PC,
		Src_PC => Src_PC,
		Bus_Donnees_In	=> Bus_Donnees_In,
		Bus_Donnees_Out	=> Bus_Donnees_Out,
		Bus_Adresses    => Bus_Adresses,
		Src1 => Src1,
		Src2 => Src2,
		Dest => Dest,
		Banc_Src => Banc_Src,
		Banc_Ecr => Banc_Ecr,
		Z => Z,
		N => N,
		Src_Op_B => Src_Op_B,
		Cmd_UAL => Cmd_UAL,
		Src_Adr_branch => Src_Adr_Branch,
		imm => Imm);
		

	-- generation des signaux de contrôle pour chacune des instructions du programme
	program  : process
		begin	
		-- PC=0, R0=0 t=0
		-- ADDI R0, 56, R2
		Src_PC 		<= '1';
		Banc_Src 	<= "01";
		Src1 		<= "0000";
		Src2 		<= "0000";
		Dest 		<= "0010";
		Banc_Ecr	<= '1';
		Cmd_Ual         <= "00";     -- Z=0, N=0;
		Src_Op_B        <= '0';
		Src_adr_branch  <= '-';
		Bus_Donnees_in  <= "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
		imm             <= std_logic_vector(to_signed(16#56#, 16));
		wait for 10 ns;
	
		--  PC=4, R0=0, R2=56 t=10ns
		--  SUB  R0, R2, R4

		Src_PC 	<= '1';
		Banc_Src 	<= "01";
		Src1 		<= "0000";
		Src2 		<= "0010";
		Dest 		<= "0100";
		Banc_Ecr	<= '1';
		Cmd_Ual         <= "01";     -- Z=0, N=0;
		Src_Op_B        <= '1';
		Src_adr_branch  <= '-';
		Bus_Donnees_in  <= "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
		imm             <= "----------------";
		wait for 10 ns;
		
		--  PC=8, R0=0, R2=56, R4=-56 t=20ns
		--  SW R4, 100(R2)

		Src_PC 	<= '1';
		Banc_Src 	<= "--";
		Src1 		<= "0010";
		Src2 		<= "0100";
		Dest 		<= "----";
		Banc_Ecr	<= '0';
		Cmd_Ual         <= "00";     -- Z=0, N=0;
		Src_Op_B        <= '1';
		Src_adr_branch  <= '-';
		Bus_Donnees_in  <= "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
		imm             <= std_logic_vector(to_signed(16#100#, 16));
		wait for 10 ns;
		
		--  PC=12, R0=0, R2=56, R4=-56, R156=-56 t=30ns
		--  LW 104(R2), R4

		Src_PC 	<= '1';
		Banc_Src 	<= "--";
		Src1 		<= "0010";
		Src2 		<= "----";
		Dest 		<= "0100";
		Banc_Ecr	<= '0';
		Cmd_Ual         <= "00";     -- Z=0, N=0;
		Src_Op_B        <= '1';
		Src_adr_branch  <= '-';
		Bus_Donnees_in  <= "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
		imm             <= std_logic_vector(to_signed(16#104#, 16));
		wait for 10 ns;
		
		--  PC=12, R0=0, R2=56, R4=160, R156=-56 t=40ns
		--  JSR 66,R6

		Src_PC 	<= '1';
		Banc_Src 	<= "--";
		Src1 		<= "0010";
		Src2 		<= "----";
		Dest 		<= "0100";
		Banc_Ecr	<= '0';
		Cmd_Ual         <= "00";     -- Z=0, N=0;
		Src_Op_B        <= '1';
		Src_adr_branch  <= '-';
		Bus_Donnees_in  <= "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
		imm             <= std_logic_vector(to_signed(16#104#, 16));
		wait for 10 ns;
		
		--  PC=12, R0=0, R2=56, R4=160, R156=-56 t=40ns
		wait;

	end process;


end test;

