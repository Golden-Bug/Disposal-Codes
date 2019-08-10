function [e] = Error(x, y)
    z = x - y;
    z = abs(z);
    [r c] = size(z);
    e = -1;
    for i = 1:c
        if z(i) > e then
            e = z(i);
        end,
    end
endfunction

function [X] = GaussSeidel(A, b, x);
    a = [A b];
    [r c] = size(a);
    n = 100;
    t = 0.00005;
    k = 0;
    X = zeros(1, c-1)
    for i=1:c-1
        X(1,i)=x(1,i);
    end
    while k < n
        k = k+1;
        for i = 1:c-1
            val = a(i, c);
            for j = 1:c-1
                if j==i then
                    continue;
                end,
                val = val - a(i, j) * X(1, j);
            end
            X(1, i) = val/a(i,i);
        end    
        e = Error(x, X);
        if(e < t) then
            break
        end
        for i=1:c-1
            x(1, i) = X(1, i);
        end        
    end
endfunction

A = [8, -3,  2;
     4, 11, -1;
     6,  3, 12;]

b = [20; 33; 35]

x = [0, 0, 0];
disp(GaussSeidel(A, b, x));



