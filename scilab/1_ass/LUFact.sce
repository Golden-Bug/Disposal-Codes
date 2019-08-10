A = [8, -3, 2;
     4, 11, -1;
     6, 3, 12];
     
b = [20; 33; 36]

for i =1:3
    L(i,i) = 1;
end

for i =1:3
    for j =1:3
        s =0;
        if j >= i   //for upper triangular
            for k = 1:i - 1
                s = s + L(i,k) * U(k,j);
            end
            U(i,j) = A(i,j) - s;
        else        //for lower triangular
            for k = 1:j - 1
                s = s + L(i,k ) * U(k,j);
            end
            L (i,j) = ( A (i,j) - s) / U(j,j) ;
        end
    end
end

//disp("Lower triangular matrix:")
//disp(L)
//disp("Upper tringular matrix:")
//disp(U)
c=L\b;
x=U\c;
disp("Solutin using LU factorisation:")
disp (x)
