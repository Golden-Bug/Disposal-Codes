import java.util.*;
import java.util.Scanner;
import java.text.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.text.ParseException;


class Validate {

public static boolean validateJavaDate(String strDate)
   {
	/* Check if date is 'null' */
	if (strDate.trim().equals(""))
	{
	    return true;
	}
	/* Date is not 'null' */
	else
	{
	   
SimpleDateFormat sdfrmt = new SimpleDateFormat("dd/mm/yyyy");
    sdfrmt.setLenient(false);
	     
	    try
	    {
	        Date javaDate = sdfrmt.parse(strDate); 
	        System.out.println("Date of Birth: "+ strDate);
	    }
	    /* Date format is invalid */
	    catch (ParseException e)
	    {
	        System.out.println("Please Enter a valid Date ");
	        return false;
	    }
	    /* Return true if date format is valid */
	    return true;
	}
   }





public static void main(String[] args){

SimpleDateFormat sdf = new SimpleDateFormat("dd/mm/yyyy");
Scanner input = new Scanner(System.in);

String fname = input.nextLine();
String lname = input.nextLine();
String date = input.nextLine();
String domain = input.nextLine();


 Pattern pattern = Pattern.compile(new String ("^[a-zA-Z\\s]*$"));
 Matcher matcher = pattern.matcher(fname);
    if(matcher.matches())
    {
         System.out.println("First Name: "+ fname);
    }
    else
    {
         System.out.println("Please enter a valid name");
    }

  matcher = pattern.matcher(lname);
    if(matcher.matches())
    {
         System.out.println("Last Name: "+ lname +"\n");
    }
    else
    {
         System.out.println("Please enter a valid name");
    }

validateJavaDate(date);

Pattern pat = Pattern.compile(new String ("^.+@.+\\..+$"));
 matcher = pat.matcher(domain);
if(matcher.matches())
    {
         System.out.println("Domain: "+ domain);
    }
    else
    {
         System.out.println("Please enter a valid domain");
    }

}

}



