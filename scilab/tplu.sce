function d = determinant(A) 
    if size(A, 1) == 2 then
        d = A(1,1) * A(2, 2) - A(1,2) * A(2, 1);
    else
        d = 0;
        for i = 1:size(A,1)
            d = d + A(1,i) * (-1) ^ (i + 1) * determinant(A(2:$, [1:(i - 1), (i + 1):size(A,1)]));
        end
    end  
endfunction

function x = cramer(A, b)
    detA = determinant(A);
    for i = 1:size(b, 'r')
        M = A;
        M(:, i) = b;
        x(i) = det(M) / detA;
    end
endfunction

function [L, U] = mon_lu(A)
    U = zeros(A);
    L = eye(A);
    n = size(A, 1);
    for i = 1:(n - 1)
        L((i + 1):n, i) = A((i + 1):n, i) / A(i, i);
        U(i, i:n) = A(i, i:n);
        A((i + 1):n, (i + 1):n) = A((i + 1):n, (i + 1):n) - L((i + 1):n, i) * U(i, (i + 1):n);
    end
    U($, $) = A($, $);
endfunction

function x = linsolve_triu(U, y)
    n = size(y, 1);
    x = zeros(y);
    for i = n:-1:1
        x(i) = (y(i) - U(i, (i + 1):n) * x((i + 1):n)) / U(i, i);
    end
endfunction

function x = linsolve_tril(L, y)
    n = size(y, 1)
    x = zeros(y);
    for i = 1:(n - 1)
        x(i) = (y(i) - L(i, 1:(i - 1)) * y(1:(i - 1))) / L(i, i)
    end
    x(n) = 1;
endfunction

function x = lu_linsolve(A, b)
    [L, U] = mon_lu(A);
    y = linsolve_tril(L, b);
    x = linsolve_triu(U, y);
endfunction

A = round(10 * rand(4, 4))
b = round(10 * rand(4, 1))
x = lu_linsolve(A, b)