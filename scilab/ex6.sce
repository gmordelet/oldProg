S = 1 / 6
lim = 10^(-3)
Rn = 1 - S
n = 1
while Rn > lim
    S = S + 1/((n + 1) * (n + 2));
    Rn = 1 - S;
    n = n + 1;
end
n
