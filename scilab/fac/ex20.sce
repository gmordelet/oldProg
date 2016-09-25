function P = poly_Lagrange(x, y)
    P = 0;
    n = length(x);
    for i = 1:n
        r = x;
        r(i) = [];
        Q = poly(r, "X");
        L = Q / horner(Q, x(i));
        P = P + y(i) * L;
    end
endfunction

clf();

x = rand(1, 5);
y = rand(1, 5);

x(1) = 0;
y(1) = 0;

x(5) = 1;
y(5) = 1;

plot2d(x, y, style = -2);

P = poly_Lagrange(x, y);

x = 0:0.01:1;
y = horner(P, x);

plot2d(x, y);