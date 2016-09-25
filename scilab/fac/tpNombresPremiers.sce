function t = test_premier(n)
    t = %T * ones(1, n);
    for i = 2:sqrt(n)
        if(t(i))
            t(i*2:i:n) = %F;
        end
    end
endfunction

function l = premiers(n)
    A = test_premier(n);
    l = [];
    for i = 2:n
        if(A(i))
            l = [l, i];
         end
    end
endfunction

function N = compte_premiers(n)
    A = premiers(n);
    taille = size(A);
    somme = 0;
    N = [0];
    j = 1;
    for i = 2:n
        while(A(j) <= i & j <= taille)
            somme = somme + A(j);
            j = j + 1;
        end
        N = [N, somme];
    end
endfunction
