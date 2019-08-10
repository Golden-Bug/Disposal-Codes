A = [1 3 2; 2 -1 1; 1 2 3]
b = [5; -1; 2]

function[x] = gaussElimination(A,b)
    [nA,mA] = size(A)
    [nb,mb] = size(b)
    
    if nA <> mA then
        error('A is not square matrix!')
        abort;
    elseif mA <> nb then
        error('Incompatible dimensions for A and b matrix!')
        abort;
    end
    
    a = [A b]
    
    // forward elimination 
    n = nA
    for k=1:n-1
        for i=k+1:n
            for j=k+1:n+1
                a(i,j) = a(i,j) - a(k,j)*a(i,k)/a(k,k)
            end
        end
    end
    
    // backward substitution
    x(n) = a(n, n+1)/a(n,n)
    for i=n-1:-1:1
        sumK = 0
        for k = i+1:n
            sumK = sumK + a(i,k)*x(k)
        end
        x(i) = (a(i,n+1) - sumK)/a(i,i)
    end
    
endfunction

disp(gaussElimination(A,b))
