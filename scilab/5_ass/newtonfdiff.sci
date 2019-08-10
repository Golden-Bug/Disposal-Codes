x=input("Enter value of x as row matrix:")
y=input("Enter value of y as row matrix:")
xg=input("Enter xg at which we want to interpolate:")
n=length(x)
h=x(2)-x(1)
u=(xg-x(1))/h
disp("Forward difference table is:")
for i=1:n-1
    disp(diff(y,i))
end
yg=y(1)
p=u
for i=1:n-1
    d=diff(y,i)
    yg=yg+p*d(1)
    p=p*((u-i)/(i+1))
end
disp(yg,"The interpolation by forward difference table is :")

// Giving  multiple comments - ctrl+D
//--> exec('/home/ratna/Documents/scilab/5_ass/newtonfdiff.sci', -1)
//Enter value of x as row matrix:[20 30 40 50 60]
//
//Enter value of y as row matrix:[25 30 58 70 98]
//
//Enter xg at which we want to interpolate:18
//
//
// Forward difference table is:
//
//   5.   28.   12.   28.
//
//   23.  -16.   16.
//
//  -39.   32.
//
//   71.
//
// The interpolation by forward 
//  difference table is :      
//   35.1904
//