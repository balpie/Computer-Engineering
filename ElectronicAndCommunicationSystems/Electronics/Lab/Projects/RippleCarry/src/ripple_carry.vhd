library IEEE;
use IEEE.std_logic_1164.all;


entity adder_Nbit is
    generic ( Nbit : positive := 8);
    port ( 
        n1 : in std_logic_vector(Nbit - 1 downto 0);
        n2 : in std_logic_vector(Nbit - 1 downto 0);
        c_in : in std_logic;
        c_out : out std_logic;
        s_n1_n2 : out std_logic_vector(Nbit - 1 downto 0)
    );
end entity;

architecture structural of adder_Nbit is
    Component full_adder
        port (
            a : in std_logic;
            b : in std_logic;
            cin : in std_logic;
            cout : out std_logic;
            s : out std_logic
        );
    end component;
    -- generic
    signal carry : std_logic_vector(Nbit - 2 downto 0);

begin
    -- generation of N instances of full_adder
    g_full_adder: for i in 0 to Nbit - 1 generate
        g_FIRST: if i = 0 generate -- first cell
            i_DFC: full_adder port map (
                a => n1(0), 
                b => n2(0), 
                s => s_n1_n2(0),
                cin => c_in, 
                cout => carry(0) 
           );
        end generate;
        g_INTERNAL: if i > 0 and i < Nbit-1 generate
            i_DFC: full_adder port map(
                a => n1(0), 
                b => n2(0), 
                s => s_n1_n2(i),
                cin => carry(i - 1),
                cout => carry(i)
            );
        end generate;
        g_LAST: if i = Nbit - 1 generate -- last cell
            i_DFC: full_adder port map (
                a => n1(0), 
                b => n2(0), 
                s => s_n1_n2(i),
                cin => carry(i - 1), 
                cout => c_out 
        );
        end generate;
    end generate;
end architecture;
