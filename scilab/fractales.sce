stacksize('max');

function tracer(z)
    x = [0, cumsum(cos(cumsum(z)))];
    y = [0, cumsum(sin(cumsum(z)))];
    plot2d(x, y, axesflag = 0, frameflag = 4);
endfunction

function y = iter_dragon(x)
    y =[x, 1, -x($:-1:1)];
endfunction

function z = dragon(n)
    z = []
    for i=1:n
         z = iter_dragon(z)
    end
endfunction

function y = iter_koch2(x)
    l = length(x);
    y = [1, -2, 1];
    for i = 1:l
        y = [y, x(i), [1, -2, 1]];
    end
endfunction

function y = iter_koch(x)
    y = [x, 1, x, -1, -1, x, 1, x];
endfunction

function z = koch(n)
    z = []
    for i = 1:n
        z = iter_koch(z)
    end
endfunction

tic(),tracer(%pi / 3 * koch(11)),toc()
