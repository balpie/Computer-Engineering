library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity test_bench is
    -- generic (...);
end entity;

architecture test_bench of test_bench is

    constant clk_period : time := 100 ns;
    constant N : positive := 8;


    component adder_Nbit
        generic (
            Nbit : positive
        );
        port (
            n1 : in std_logic_vector(Nbit-1 downto 0);
            n2 : in std_logic_vector(Nbit-1 downto 0);
            c_in : in std_logic;
            s_n1_n2 : out std_logic_vector(Nbit-1 downto 0);
            c_out : out std_logic
        );
    end component;
    signal clk : std_logic := '0';
    signal a_ext : std_logic_vector(N-1 downto 0) := (others => '0');
    signal b_ext : std_logic_vector(N-1 downto 0) := (others => '0');
    signal cin_ext : std_logic := '0';
    signal s_ext : std_logic_vector(N-1 downto 0);
    signal cout_ext : stadder_Nbit;
    signal testing : boolean := true;
    begin
        clk <= not clk after clk_period/2 when testing else '0';
        i_DUT: adder_Nbit
            generic map (
                Nbit => N
            )
            port map (
                n1 => a_ext,
                n2 => b_ext,
                c_in => cin_ext,
                s_n1_n2 => s_ext,
                c_out => cout_ext
            );
        p_STIMULUS: process begin
            a_ext <= (others => '0');
            b_ext <= (others => '0');
            cin_ext <= '0';
            wait for 200 ns;
            a_ext <= "00000110";
            b_ext <= "00100110";
            cin_ext <= '0';
            wait until rising_edge(clk);
            a_ext <= x"76"; -- means "0111_0110"
            b_ext <= x"14"; -- means "0001_0100"
            cin_ext <= '1';
            wait until rising_edge(clk);
            a_ext <= (others => '0');
            b_ext <= (others => '0');
            cin_ext <= '0';
            wait for 1008 ns;
            a_ext <= "11111111";
            b_ext <= "11111111";
            cin_ext <= '0';
            wait for 500 ns;
            testing <= false;
            wait until rising_edge(clk); -- blocked here
        end process;
end architecture;

