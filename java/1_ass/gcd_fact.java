public class gcd_fact {

    public static void main(String[] args) {
   
     int n1 = 81, n2 = 153;
     int k;
    
        k = gcd(n1,n2);
        System.out.printf("GCD of %d and %d is: %d\n", n1, n2, k);
       
     int f; int n = 5;
     f = fact(n);
     System.out.println("Factorial of "+n+" is: "+f);   
   
     }
    public static int gcd(int num1,int num2){
   
    int gcd=1;
    for(int i = 1; i <= num1 && i <= num2; i++)
        {
            if(num1%i==0 && num2%i==0)
                gcd = i;
        }

       return gcd;
       
    }
   
   public static int fact(int number){
   
     int i,fact=1;
      for(i=1;i<=number;i++){   
          fact=fact*i;   
      }
      return fact;  
     
     } 
  
   }
   


