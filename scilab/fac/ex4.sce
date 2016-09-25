function A = matComp(P)
    c = coeff(P);
    c($) = [];
    a = -c;
    d = length(a);
    A = [zeros(d-1, 1), eye(d - 1, d - 1); a];
endfunction