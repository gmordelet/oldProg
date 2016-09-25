function t = test_premier(n)
    t(1, 1:n) = %T
    for i = 2:sqrt(n)
        if t(i) == %T then
            t((2 * i):i:n) = %F
        end
    end
endfunction

