//Euler's Formula

deff('g=f(x,y)','g=2*y+x')
xo=input("Enter initial value of xo: ")
yo=input("Enter the value of yo: ")
h=input("Enter value of h: ")
xn=input("Enter Final value of xn: ")
n=(xn-xo)/h
for i=1:n
    y1=yo+h*f(xo,yo)
    xo=xo+h
    disp([xo y1])
    yo=y1
end

//Enter initial value of xo: 0
//
//Enter the value of yo: 1
//
//Enter value of h: 0.2
//
//Enter Final value of xn: 0.8
//
//
//   0.2   1.4
//
//   0.4   2.
//
//   0.6   2.88
//
//   0.8   4.152
//
