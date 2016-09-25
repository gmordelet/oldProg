function H = ex3_2 ()
    A = matrix(1:144, 12, 12)';
    L = (1:12)' * ones(1, 12);
    C = ones(12, 1) * (1:12);
    B = modulo(C + L, 2) == 0;
    A2 = A';
    H = matrix(A2(B), 6, 12)'
endfunction

function H = ex3_3()
    A = matrix(1:144, 12, 12)';
    H = A([1, 2, 5, 9, 10], [1, 2, 5, 9, 10])
endfunction
