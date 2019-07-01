import java.util.*;
import java.util.Scanner;


class Currency{

String currencyCode;
String currencyName;
public static double exchangeRate;

double ic,ac,pc,yc;

public Currency(){
currencyCode = "IND";
currencyName = "Rupee";
exchangeRate = 70.32;
}

public Currency(int n){
if(n == 2){
currencyCode = "IND";
currencyName = "Rupee";
exchangeRate = 81.305;

}
if(n == 3){

currencyCode = "IND";
currencyName = "Rupee";
exchangeRate = 89.67;

}

}

public static double calc(double amt){
  
  double t;
   
 t = amt*exchangeRate;
 

  return t;

}

public static void main(String[] args){
 
double amt; int n;

Scanner input = new Scanner(System.in);


System.out.print("Write the Currency code u want to give \n 1 for dollar\n2 for Yuro \n 3 for pound \n");

 n = input.nextInt();
if (n == 1){
Currency c = new Currency();
}
if (n == 2){
Currency c = new Currency(n);
}
if (n == 3){
Currency c = new Currency(n);
}



System.out.println("The currency required to change\n  ");
amt = input.nextDouble();
double i = calc(amt);

System.out.println("\nThe amount in ruppess is "+ i);

}

}
