function t = test_premier(n)
    t = ones(1, n) > 0;
    t(1) = %f;
    for i = 2:sqrt(n)
        if(t(i))
            t(2*i:i:n) = %F;
        end
    end
endfunction

function l = premiers(n)
    l = (1:n);
    t = test_premier(n);
    l = l(t);
endfunction

function N = compte_premiers(n)
    N = cumsum(test_premier(n));
endfunction

function k = tnp(n)
    k = compte_premiers(n) * log(n) / n;
endfunction

function N = goldbach_ok(n)
    N = ones(1, n) < 0;
    p = premiers(2 * n);
    Size = size(p, 'c')
    C = ones(Size,1) * p;
    S = C + C';
    for i = 1:n
        for x = 1:(Size)
            y = 1;
            while(y <= x)
                if S(x, y) == 2 * i then
                    N(i) = %T;
                    break;
                end
                y = y + 1;
            end
        end
    end
endfunction

function N = comete_goldbach(n)
    N = zeros(1, n);
    p = premiers(2 * n);
    Size = size(p, 'c')
    C = ones(Size,1) * p;
    S = C + C';
    for i = 1:n
        for x = 1:(Size)
            y = 1;
            for y = 1:x
                if S(x, y) == 2 * i then
                    N(i) = N(i) + 1;
                end
            end
        end
    end
endfunction

function N = comete_goldbach2(n)
    N = zeros(1, n);
    p = premiers(2 * n);
    Size = size(p, 'c')
    C = ones(Size,1) * p;
    S = C + C';
    S = triu(S);
    for i = 1:n
        N(i) = sum(S == 2 * i);
    end
            
endfunction

function void = graph_comete(n)
    N = comete_goldbach(n);
    clf;
    plot(N,'.','markersize',1);
endfunction
