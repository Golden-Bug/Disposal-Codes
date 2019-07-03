import java.io.*;
import java.util.Scanner;
import java.lang.*; 
public class Ass4a{
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        StringBuffer s = new StringBuffer("Operation on Sentence using StringBuffer");

        while(true){ 
            System.out.println("A. New word add in existing sentence!");
            System.out.println("B. Delete any specific word!");
            System.out.println("C. Modify existing word spelling!");
            System.out.println("D. Add punctuation in the Sentence!");
            System.out.println("E. Display the Sentence!");
            System.out.println("F. For Terminating program!");
            String option = input.next();

            switch (option){
                case "A" : 
                    System.out.println("Enter The Word to insert!");
                    String str =  input.next();
                    System.out.println("Enter the index where the new Word added!");
                    int ind = input.nextInt();
                    str = str + " ";
                    if(ind == 0){
                        s.insert(ind,str);
                    }
                    else{
                        s.insert(ind + 1,str);
                    }                   
                    break;
                case "B" :
                    System.out.println("Enter the Word to delete!");
                    String str1 = input.next();
                    int ind1 = s.indexOf(str1);    
                    s.delete(ind1,str1.length() + ind1);               
                    break;
                case "C":
                    System.out.println("Enter the word for modify the spelling!");
                    String str2 = input.next();
                    System.out.println("Enter the starting index of the word!");
                    int start = input.nextInt();
                    s.replace(start, str2.length() + start,str2);
                    break;
                case "D":
                    System.out.println("Enter the punctuation to insert!");
                    char c =  input.next().charAt(0);
                    System.out.println("Enter the index for insert!");
                    int ind2 = input.nextInt();
                    s.insert(ind2,c); 
                    break;
                case "E":
                    System.out.println(s);
                    break;   
                case "F":
                    System.exit(0);
                default : 
                    System.out.println("Wrong Entry!");
                    break;
                }          
        }
    }
}