function M = f(n, a, b)
    A = eye(n, n) * (a - b);
    B = ones(n, n) * b;
    M = A + B;
endfunction

function M = g(n, a, b, c)
    A = eye(n, n) * a;
    B = diag(ones(n - 1, 1), -1) * b;
    C = diag(ones(n - 1, 1), 1) * c;
    M = A + B + C;
endfunction

function M = h(x)
    l = length(x) - 1;
    A = ones(x)' * x;
    B = (0:l)' * ones(x);
    M = A .^ B;
endfunction
