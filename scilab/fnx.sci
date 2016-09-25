function y = fnx(n, x)
    l = length(x);
    for i = 1:l
        if x(i) >= 2 / n then
            y(i) = 1 / n;
        elseif x(i) >= 1 / n then
            y(i) = (1 - n * n) * x(i) + 2 * n - 1 / n;
        elseif x(i) >= 0 then
            y(i) = n * n * x(i);
        else 
            y(i) = 0;
        end
    end    
endfunction
