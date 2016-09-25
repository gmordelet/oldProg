function Pxi = HP(P, xi)
    c = coeff(P);
    l = length(c);
    Pxi = c(l);
    for i = 2:l
        Pxi = xi .* Pxi + c(l - i + 1);
    end
endfunction

function y2 = test()
    c = coeff((%s - 2)^15);
    y2 = zeros(x);
    for i = 1:16
        y2 = y2 + c(i) * x.^(i - 1);
    end
endfunction
