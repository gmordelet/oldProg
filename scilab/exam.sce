function An = calcul(F,n)
    somme = sum(F((1:(n - 1)) / n))
    An = 1 / (2 * n) * (F(0) + F(1) + 2 * somme)
endfunction

function v = morse(n)
    v(1) = 0  
    for i = 2:n
        reste = modulo(i, 2);
        if reste == 0 then
            k = (i - 2) / 2
            v(1, i) = 1 - v(1, k + 1)
        else
            k = (i - 1) / 2
            v(1, i) = v(1, k + 1)
        end
    end
endfunction

function C = binome(k, n)
    if k == 0 & n == 0 then
        C = 1;
    elseif k > n then
        C = 0;
    else   
        num = prod((n - k + 1):n); 
        C = num / factorial(k);
    end
endfunction

function A = matrice(v, w)
    A = diag(w) + diag(v, 1)
endfunction

function x = solution(v, w, b)
    n = size(v, 'c');
    x(n + 1) = b(n + 1) / w(n + 1);
    for i = n:-1:1
        x(i) = (b(i) - v(i) * x(i + 1)) / w(i);
    end
endfunction


