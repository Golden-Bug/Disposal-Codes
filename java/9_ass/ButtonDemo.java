import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
 
public class ButtonDemo extends Frame implements ActionListener
{
  Button action,countv,countc,countp,cap,fn;		            // three Button reference variables
  public ButtonDemo()	                    // constructor to set the properties to a button
  {
    FlowLayout fl = new FlowLayout();	    // set the layout to frame
    setLayout(fl);
 
    action = new Button("Action Buttons");		    // convert reference variables into objects
    countv = new Button("Count Vowels");
    countc = new Button("Count Consonants");
    countp = new Button("Count Punctuations");
    cap = new Button("Capitalize");
    fn = new Button("Other Component");
 
    action.addActionListener(this);		    // link the Java button with the ActionListener
    countv.addActionListener(this);
    countc.addActionListener(this);
    countp.addActionListener(this);
    cap.addActionListener(this);
    fn.addActionListener(this);

    add(action);			            // add each Java button to the frame
    add(countv);
    add(countc);
    add(countp);
    add(cap);
    add(fn);   
 
    setTitle("Ass_9");
    setSize(200, 300);                      // frame size, width x height
    setVisible(true);			    // to make frame visible on monitor, default is setVisible(false)
  }
			                    // override the only abstract method of ActionListener interface
  public void actionPerformed(ActionEvent e)
  {
    String str = e.getActionCommand();	    // to know which Java button user clicked
    System.out.println("You clicked " + str + " button");  // just beginner's interest
 
    if(str.equals("Action"))
    {
      //setBackground(Color.red);
    }
    else if(str.equals("Count Vowels"))
    {
      
    }
    else if(str.equals("Count Consonants"))
    {
      
    }
    else if(str.equals("Count Punctuations"))
    {
      
    }
    else if(str.equals("Capitalize"))
    {
      
    }
    else if(str.equals("Other Component"))
    {
      JFileChooser openfile = new JFileChooser();
      openfile.showOpenDialog(null);

      if(str.equals("Capitalize")){
        setBackground(Color.red);
      }
    }
  }
  public static void main(String args[])
  {
    new ButtonDemo();                       // anonymous object of ButtonDemo just to call the constructor
  }			                    // as all the code is in the constructor
}