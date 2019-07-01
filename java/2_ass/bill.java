import java.util.Scanner;

class bill
    {
    int phno;
    String name;
    double hire_charge;
    double bill_amount;
    double unit_consumed;
    
    bill(int a,String b,double c)
        {
        
        phno=a;
        name=b;
        unit_consumed=c;
        }
        public void cal(double hire_charge)
     
        {if (unit_consumed<=100)
		{
		  bill_amount=hire_charge+1*unit_consumed;
		}
		else if(unit_consumed<=200 &&  unit_consumed>100)
		{
		bill_amount=hire_charge+1*100+1.50*(unit_consumed-100);		
		}
		else 
		 bill_amount=hire_charge+1*100+1.50*100+2*(unit_consumed-200);
		  System.out.println( bill_amount);
	}
        
    public static void main(String[] args)
     {
     Scanner sc = new Scanner(System.in);
     System.out.println("enter the phno");
     int a = sc.nextInt();
     System.out.println("enter the name");
     String b =sc.next();
     System.out.println("enter the units consumed");
     double c=sc.nextDouble();
     System.out.println("enter the hire charge");
     double hire=sc.nextDouble();
     bill d=new bill(a,b,c);
     d.cal(hire);
     
     }
    }
