import java.applet.*;  
import java.awt.*;  
import java.awt.event.*;  
import java.util.Scanner;
import java.io.*;
public class A8Q1 extends Applet implements ActionListener{  
Button b1,b2,b3,b,b4,b5,b6;  
TextField tf;  
Label l1,l2,l3;
TextArea area;
public void init()
{  
  setBackground(Color.YELLOW);
  tf=new TextField("Enter file name");  
  l1=new Label("Vowels: ");  
    l1.setBounds(30,360,100,20);  
    l2=new Label("Consonants: ");  
    l2.setBounds(30,390,100,20);
    l3=new Label("Punctuations: ");  
    l3.setBounds(30,420,100,20);  
    area=new TextArea("Enter text");  
    area.setBounds(30,150,300,150); 
    add(l1);add(l2);add(l3);add(area);add(tf);
  tf.setBounds(100,40,150,20);
  b1=new Button("Vowels");  
  b1.setBounds(30,100,100,20); 
  b2=new Button("Consonants");  
  b2.setBounds(140,100,100,20); 
  b3=new Button("Punctuations");  
  b3.setBounds(260,100,100,20);
  
  add(b1);add(b2); add(b3); 
  b4=new Button("Vowels");  
  b4.setBounds(30,320,100,20); 
  b5=new Button("Consonants");  
  b5.setBounds(140,320,100,20); 
  b6=new Button("Punctuations");  
  b6.setBounds(260,320,100,20);
  
  add(b4);add(b5); add(b6); 
b1.addActionListener(this); b2.addActionListener(this); b3.addActionListener(this);  
b4.addActionListener(this); b5.addActionListener(this); b6.addActionListener(this);
setLayout(null);  
}  

 public void paint(Graphics g)
 {
  g.drawString("Browse: ",30,55);
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
  
  String fp=tf.getText();
  FileReader inputStream = null;
  try 
  {
        inputStream = new FileReader(fp);
        int ch;
        while ((ch = inputStream.read()) != -1) 
        {
           
      ch = (char)ch;
        if(ch=='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u')
          v2+=1;
        else if(ch=='A' || ch=='E'||ch=='I'||ch=='O'||ch=='U')
          v2+=1;
        else if(ch==','||ch=='.'||ch=='!'||ch=='?')
          p2+=1;
        else if(Character.isLetter(ch)) 
          c2+=1;
            
        } 
    }
    catch(IOException ie)
    {
      Label l;
      l=new Label("File not Found.");
      l.setBounds(30,450,100,20);       
    }
    finally 
      {
            if (inputStream != null) {
              try{inputStream.close();}
              catch(IOException ex)
              { Label l4;
            l4=new Label("File not Found.");
            l4.setBounds(30,400,100,20);}
            }
        }
    if(e.getSource()==b4)
    l1.setText("Vowels: " + Integer.toString(v1)); 
  else if(e.getSource()==b5)
    l2.setText("Consonants: " + Integer.toString(c1)); 
  else if(e.getSource()==b6)
    l3.setText("Punctuations: " + Integer.toString(p1)); 
  if(e.getSource()==b1)
    l1.setText("Vowels: " + Integer.toString(v2)); 
  else if(e.getSource()==b2)
    l2.setText("Consonants: " + Integer.toString(c2)); 
  else if(e.getSource()==b3)
    l3.setText("Punctuations: " + Integer.toString(p2)); 
 }   
}  

 /*
<applet code="A8Q1.class" width="600" height="600">  
</applet>  
*/
