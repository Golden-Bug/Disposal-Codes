interface shape {
  public double perimeter();
  public double area();
}

class square implements shape {
  double side;
  square(double a) {
    side = a;
  }

  public double area() {
    double area;
    area = side*side;
    return area;
  }

  public double perimeter() {
    double perimeter;
    perimeter = 4*side;
    return perimeter;
  }
}

class rectangle implements shape {
  double a;
  double b;
  rectangle(double m, double n) {
    a = m;
    b = n;
  }

  public double area() {
    double area;
    area = a*b;
    return area;
  }

  public double perimeter() {
    double perimeter;
    perimeter = 2*(a+b);
    return perimeter;
  }
}

class isorttri implements shape {
  double a;
  isorttri(double m) {
    a = m;
  }

  public double area() {
    double area;
    area = 0.5*a*a;
    return area;
  }

  public double perimeter() {
    double perimeter;
    perimeter = 2*a + 1.41*a;
    return perimeter;
  }
}

class circle implements shape {
  double r;
  circle(double m) {
    r = m;
  }

  public double area() {
    double area;
    area = 3.14*r*r;
    return area;
  }

  public double perimeter() {
    double perimeter;
    perimeter = 2*3.14*r;
    return perimeter;
  }
}

class main {
  public static void main(String args[]) {
    shape[] s = new shape[8];
    s[0] = new square(4);
    s[1] = new square(6);
    s[2] = new rectangle(4, 9);
    s[3] = new rectangle(4, 6);
    s[4] = new circle(4);
    s[5] = new circle(3);
    s[6] = new isorttri(5);
    s[7] = new isorttri(7);
    double maxarea = 0.0;
    double maxperi = 0.0;
    double max2area = 0.0;
    double max2peri = 0.0;
    double minarea = 9999.999;
    double minperi = 9999.999;
    int smaxa = 0;
    int smaxp = 0;
    int smax2a = 0;
    int smax2p = 0;
    int smina = 0;
    int sminp = 0;
    int i = 0;
    while (i < 8) {
      System.out.println("Perimeter of shape "+i+" is "+s[i].perimeter());
      if(s[i].perimeter() > maxperi) {
        maxperi = s[i].perimeter();
        smaxp = i;
      }
      if(s[i].area() > maxarea) {
        maxarea = s[i].area();
        smaxa = i;
      }
      if(s[i].perimeter() < minperi) {
        minperi = s[i].perimeter();
        sminp = i;
      }
      if(s[i].area() < minarea) {
        minarea = s[i].area();
        smina = i;
      }
      i = i+1;
    }
    i = 0;
    while (i < 8) {
      System.out.println("Area of shape "+i+" is "+s[i].area());
      if(s[i].perimeter() > max2peri && s[i].perimeter() < maxperi) {
        max2peri = s[i].perimeter();
        smax2p = i;
      }
      if(s[i].area() > max2area && s[i].area() < maxarea) {
        max2area = s[i].area();
        smax2a = i;
      }
      i = i+1;
    }
    System.out.println("Shape with max area is "+smaxa);
    System.out.println("Shape with 2nd max area is "+smax2a);
    System.out.println("Shape with max perimeter is "+smaxp);
    System.out.println("Shape with 2nd max perimeter is "+smax2p);
    System.out.println("Shape with min perimeter is "+sminp);
    System.out.println("Shape with min area is "+smina);
    double dams = maxarea - max2area;
    double dpms = maxperi - max2peri;
    //dams = 0; //Uncomment this to see ArithmeticException()
    i = 0;
    while (i < 8) {
      try{
        double aa = s[i].area()/dams;
        double bb = s[i].perimeter()/dpms;
        if(aa == Double.POSITIVE_INFINITY || aa == Double.NEGATIVE_INFINITY || bb == Double.POSITIVE_INFINITY || bb == Double.NEGATIVE_INFINITY) {
          throw new ArithmeticException();
        }
        System.out.println("shape_area/dams of shape "+i+" is "+aa);
        System.out.println("shape_perimeter/dpms of shape "+i+" is "+bb);
      }
      catch(ArithmeticException ae) {
        System.out.println("ArithmeticException occured!");
      }
      i = i+1;
    }


  }
}
