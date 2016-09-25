function P = poly_Lagrange(x, y)
    P = 0;
    n = length(x);
    X = poly([0, 1], "X" , "c");
    for i = 1:n
        Pp = 1;
        for j = 1:n
            if ~(i == j) then 
                Pp = Pp * ((X - x(j)) / (x(i) - x(j)));
            end
        end
        P = P + y(i) * Pp;
    end
endfunction

clf();

x = rand(1, 10) * 10;
y = rand(1, 10) * 10;

plot2d(x, y, style = -5);

P = poly_Lagrange(x, y);

x = 0:0.1:10;
y = horner(P, x)

plot2d(x, y);
