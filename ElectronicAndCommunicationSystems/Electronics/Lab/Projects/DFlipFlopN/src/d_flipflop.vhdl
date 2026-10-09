library IEEE;
use IEEE.std_logic_1164.all;


entity d_flipflop is
    generic (
        N: positive := 8
    );
    port (
        clk : in std_logic;
        resetn : in std_logic; 
        en : in std_logic;
        di : in std_logic_vector(N-1 downto 0); 
        do : out std_logic_vector(N-1 downto 0)
    );
end entity;


architecture DFF of d_flipflop is
    -- internal signals
    signal di_s : std_logic_vector(N-1 downto 0);
    signal do_s : std_logic_vector(N-1 downto 0);

    component d_latch
        port(
            clock   : in std_logic;   
            reset   : in std_logic;   
            d       : in std_logic_vector(N-1 downto 0);   
            q       : out std_logic_vector(N-1 downto 0)
        );
    end component;
    -- TODO ARCHITECTURE ????

    port map(
        clk => clock;
        resetn => reset;
        di_s => di when en = '1' else do_s;
        do => do_s
    )
end architecture;
