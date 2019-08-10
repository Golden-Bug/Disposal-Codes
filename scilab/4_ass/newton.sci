function[P]=newton(X,Y) //X nodes,Y values;P is the numerical Newton polynomial
n=length(X); // n is the number of nodes. (n-1) is the degree
for j=2:n,
  for i=1:n-j+1,Y(i,j)=(Y(i+1,j-1)-Y(i,j-1))/(X(i+j-1)-X(i));end,
end,
x=poly(0,"x");
P=Y(1,n);
for i=2:n, P=P*(x-X(i))+Y(i,n-i+1); end
endfunction;

//Ans: -->X=[0;2;4]; Y=[1;5;17]; P=newton(X,Y)
//          P = 1 + x^2
