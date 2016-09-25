deff('[y] = f(x)', 'y = sin(8 * x) - 8 * (x - 3/10) .^ 2 + 5 + x .* cos(15 * (x .^ 2))');

function I = integre_rectangles(f, a, b, n)
    k = 0:(n - 1);
    inter = f(a + k * (b - a) / n);
    I = (b -a) / n * sum(inter);        
endfunction


I = [];
N = 1:100;
for n = N
    I = [I, integre_rectangles(f, 0, 1, n)];
end
scf;
//plot2d(N, I);

function I = integre_trapezes(f, a, b, n)
    k = 1:(n - 1);
    inter = f(a + k * (b - a) / n);
    I = (b - a) / n * ((f(a) + f(b) / 2) + sum(inter));
endfunction 

deff('[y] = P(x)', 'y = -1/8 * cos(x) - 8 * (1/3 * x * x * x- 3/10 * x * x + 9 / 100 * x) + 5 * x + 1/30 * sin(15 * x * x)');

I0 = P(1) - P(0)

e = [];
N = int(logspace(1, 4, 20));
for n = N
    e1 = abs(integre_rectangles(f, 0, 1, n) - I0);
    e2 = abs(integre_trapezes(f, 0, 1, n) - I0);
    e = [e; e1, e2];
end    
//plot2d(N', e,[1, 2], logflag = 'll');

function I = integre_simpson(f, a, b, n)
    I = (b - a) / 6 * (f(a) + 4 * f((a + b) / 2) + f(b))
endfunction

integre_simpson(f, 0, 1, 100)