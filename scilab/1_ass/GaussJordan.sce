A = [1 1 1;4 3 -1;3 5 3]
b = [1;6;4]

function f = gaussJordan(A,b)
    n = length(b)
    A = [A b]
    for k = 1:n
        for j = n+1:-1:k
            A(k,j) = A(k,j)/A(k,k)
        end
        for i=1:n
            if(i~=k)
                for j = n+1:-1:k
                    A(i,j) = A(i,j)-A(k,j)*A(i,k)
                end
            end
        end
    end
    f = A(:,n+1)
endfunction
disp(gaussJordan(A,b))
