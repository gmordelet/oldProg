function M = mandelbrot(x0, y0, delta, R, N)
    X = linspace(x0 - delta, x0 + delta, R);
    Y = linspace(y0 + delta, y0 - delta, R);
    C = ones(R, 1) * X + Y' * ones(1, R) * %i;
    Z = C;
    M = ones(C);
    for i = 2:N
        Z = Z .* Z + C;
        M(abs(Z) <= 2) = i;
    end
    M(M == N) = 0;
endfunction

function [x, y, i] = clicker2()
    [rep, win] = xgetmouse()
    while rep(3) ~= 0 & rep(3) ~= 2 & rep(3) ~= 3 & rep(3) ~= 5
        rep = xgetmouse();
    end
    x = rep(1);
    y = rep(2);
    i = rep(3);
    close(scf(win));
endfunction;

x0 = -0.65; y0 = 0; delta = 1.5; R = 800; N = 100;
u = mandelbrot(x0,y0,delta,R,N);
display(u);
[xM, yM, i] = clicker2();
while i ~= 2 & i ~= 5
    x0 = x0 - delta + xM * 2 * delta / (R - 1);
    y0 = y0 - delta + yM * 2 * delta / (R - 1);
    delta = delta / 4;
    u = mandelbrot(x0, y0, delta, R, N);
    display(u);
    [xM, yM, i] = clicker2();
end
