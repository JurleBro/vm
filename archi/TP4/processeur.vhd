-- processeur pipeline (connexion chemin de données-unité de controle)
-- TP 4 AS2, S. Rubini

library ieee;
use ieee.std_logic_1164.all;

entity processeur is
	port (
		PC  		: out std_logic_vector(31 downto 0);
		Inst  		: in std_logic_vector(31 downto 0);
		Bus_Donnees_In 	: in std_logic_vector(31 downto 0);
		Bus_Donnees_Out : out std_logic_vector(31 downto 0);
		Bus_Adresses 	: out std_logic_vector(31 downto 0);
		RW 		: out std_logic; 
		Bus_Val 	: out std_logic;
		Clk 		: in std_logic
	);
end processeur;

architecture struct of processeur is
	component datapath
	  port (	
		Clk 		: in std_logic;

		PC  		: out std_logic_vector(31 downto 0);
		Src_PC 		: in std_logic;

		Src1, Src2	: in std_logic_vector(3 downto 0);

		Imm     	: in std_logic_vector(15 downto 0);
		Src_Op_B	: in std_logic; 	
		Cmd_UAL 	: in std_logic_vector(1 downto 0);
		Z,N		: out std_logic;
	
		Src_adr_branch 	: in std_logic; 	
		Bus_donnees_in 	: in std_logic_vector(31 downto 0);
		Bus_donnees_out : out std_logic_vector(31 downto 0);
		Bus_adresses	: out std_logic_vector(31 downto 0);
	
		Banc_Src 	: in std_logic_vector(1 downto 0);
		Banc_Ecr 	: in std_logic; 
		Dest		: in std_logic_vector(3 downto 0)
	  );
	end component;

	component control_unit
	  port (	
		Clk 		: in std_logic;

		Inst 		: in std_logic_vector(31 downto 0);
		Src_PC 		: out std_logic;
	
		Src1, Src2	: out std_logic_vector(3 downto 0);

		Imm     	: out std_logic_vector(15 downto 0);
		Src_Op_B	: out std_logic; 	
		Cmd_UAL 	: out std_logic_vector(1 downto 0);
		Z,N		: in std_logic;
	
		Src_Adr_Branch 	: out std_logic; 	
		RW, Bus_Val 	: out std_logic;

		Banc_Src 	: out std_logic_vector(1 downto 0);
		Banc_Ecr 	: out std_logic; 
		Dest		: out std_logic_vector(3 downto 0)
	  );
	end component;
	
	-- liaison datapath/control unit
	signal src_PC 		: std_logic;
	signal src1, src2, dest : std_logic_vector(3 downto 0) := "0000";
	signal banc_ecr 	: std_logic; 
	signal cmd_UAL 		: std_logic_vector(1 downto 0);
	signal imm     		: std_logic_vector(15 downto 0);
	signal Z,N		: std_logic;
	
	signal src_op_B		: std_logic; 
	signal src_adr_branch 	: std_logic; 
	signal banc_src 	: std_logic_vector(1 downto 0);


begin
	dp : datapath port map (
		Clk => clk,

		Src_PC => Src_PC,
		PC => PC,

		Src1 => src1, Src2 => src2, 

		Imm => imm,
		Src_Op_B => src_op_B,
		Cmd_UAL => cmd_UAL,
		Z => Z, N => N,

		Src_Adr_branch => src_adr_branch,
		Bus_Donnees_In	=> bus_donnees_in,
		Bus_Donnees_Out	=> bus_donnees_out,
		Bus_Adresses => bus_adresses,

		Banc_Ecr => banc_ecr,
		Banc_Src => banc_src,
		Dest => dest
		);

	uc : control_unit port map(	
		Clk => clk,

		Inst => inst,
		Src_PC => src_pc,
	
		Src1 => src1, Src2=> src2, 

		Imm => imm,
		Src_Op_B => src_op_B, 
		Cmd_UAL => cmd_UAL, 
		Z => Z, N =>N,
	
		Src_Adr_Branch => src_adr_branch, 	
		Bus_Val => bus_val,
		RW => RW,

		Banc_src => banc_src,
		Banc_Ecr => banc_ecr, 
		Dest=> dest 
		);

end struct;


