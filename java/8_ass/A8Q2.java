import java.applet.*;  
import java.awt.*;  
import java.awt.event.*;  
import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;
public class A8Q2 extends Applet implements ActionListener{  
Button b1,b2,b3,b;  
TextField tf1,tf2;  
Label l1,l2,l3;
TextArea area;
public void init()
{  
	setBackground(Color.YELLOW);
	tf1=new TextField("Enter input file path");
	tf2=new TextField("Enter output file path");  
	l1=new Label("Vowels: ");  
    l1.setBounds(30,360,100,20);  
    l2=new Label("Consonants: ");  
    l2.setBounds(30,390,100,20);
    l3=new Label("Punctuations: ");  
    l3.setBounds(30,420,100,20);  
    area=new TextArea("Enter text");  
    area.setBounds(30,150,300,150); 
    add(l1);add(l2);add(l3);add(area);add(tf1);add(tf2);
	tf1.setBounds(90,40,400,20);
	tf2.setBounds(90,65,400,20);
	
	b=new Button("Capitalise");  
	b.setBounds(30,100,100,20);
	b1=new Button("Vowels");  
	b1.setBounds(30,320,100,20); 
	b2=new Button("Consonants");  
	b2.setBounds(140,320,100,20); 
	b3=new Button("Punctuations");  
	b3.setBounds(260,320,100,20);
	
	add(b1);add(b2); add(b3); add(b);
b1.addActionListener(this); b2.addActionListener(this); b3.addActionListener(this);  
b.addActionListener(this);
setLayout(null);  
}  

 public void paint(Graphics g)
 {
 	g.drawString("Input file: ",30,55);
 	g.drawString("Output file: ",30,80);
 }
 public void actionPerformed(ActionEvent e) 
 {  	
 	int p1=0,v1=0,c1=0,p2=0,v2=0,c2=0;
 	String text=area.getText();  
 	for(int i=0;i<text.length();i++)
 	{
 		if(text.charAt(i)=='a' || text.charAt(i)=='e'||text.charAt(i)=='i'||text.charAt(i)=='o'||text.charAt(i)=='u')
 			v1+=1;
 		else if(text.charAt(i)=='A' || text.charAt(i)=='E'||text.charAt(i)=='I'||text.charAt(i)=='O'||text.charAt(i)=='U')
 			v1+=1;
 		else if(text.charAt(i)=='.'||text.charAt(i)==','||text.charAt(i)=='!'||text.charAt(i)=='?')
 			p1+=1;
 		else if(Character.isLetter(text.charAt(i))) 
 			c1+=1;
 	}
 	if(e.getSource()==b)
 	{
 	String fp1=tf1.getText();
 	String fp2=tf2.getText();
 	File file = new File(fp1);
		try 
 		{
 			Scanner input = new Scanner(file); 
 			BufferedWriter writer=new BufferedWriter(new FileWriter(fp2));
        	String word,str;
        	int ch;
        	while (input.hasNext()) 
        	{
         		word=input.next();
         		str=Character.toUpperCase(word.charAt(0))+word.substring(1)+" ";
        		writer.write(str);
       		} 
        	writer.close();
        	if (input!= null) {
            	{input.close();}
            }
        }
    	catch(IOException ie)
    	{
    		Label l;
    		l=new Label("File not Found.");
    		l.setBounds(30,450,100,20);   	  
    	}
    	
    }
    if(e.getSource()==b1)
    l1.setText("Vowels: " + Integer.toString(v1)); 
	else if(e.getSource()==b2)
    l2.setText("Consonants: " + Integer.toString(c1)); 
	else if(e.getSource()==b3)
    l3.setText("Punctuations: " + Integer.toString(p1));
 }   
}  

 /*
<applet code="A8Q2.class" width="600" height="600">  
</applet>  
*/