library IEEE;
use IEEE.std_logic_1164.all;

entity d_latch is
    generic (
        N: positive := 8
    );
    port (
        clock   : in std_logic;   
        resetn   : in std_logic;   
        d       : in std_logic_vector(N-1 downto 0);   
        q       : out std_logic_vector(N-1 downto 0)
    );
end entity;

architecture dlatch of d_latch is
begin
    p_DFC: process(clock)
        begin
            if rising_edge(clock) then
                    if resetn = '0' then
                        q <= (others => '0');
                    else
                        q <= d;
                    end if;
            end if;
        end process;
end architecture;

