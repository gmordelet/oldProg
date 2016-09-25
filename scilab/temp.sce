function M = MatSymetrique(n)
    M = rand(n, n);
    t1 = triu(M);
    t2 = t1' - diag(diag(M));
    M = t1 + t2;
    M = floor(100 * M);
endfunction