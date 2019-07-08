import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/*<applet code ="CounterApplet.class" width=200 height=300>
  </applet>
  */
  public class CounterApplet extends Applet implements ActionListener
  {
    TextArea txt;
    Button b1, b2, b3, b4;
    String s1, s2;
    Label l1, l2;
    TextField t1, t2, t3;
    int count1, count2, count3;
    public void init()
    {
      setBackground(Color.YELLOW);
      l2 = new Label("Text Area");
      add(l2);
      txt = new TextArea(5, 30);
      add(txt);
      l1 = new Label("Functions");
      add(l1);

      b1 = new Button("Count Vowel");
      add(b1);
      b1.addActionListener(this);
      t1 = new TextField(10);
      add(t1);

      b2 = new Button("Count Consonants");
      add(b2);
      b2.addActionListener(this);
      t2 = new TextField(10);
      add(t2);

      b3 = new Button("Count Punctuations");
      add(b3);
      b3.addActionListener(this);
      t3 = new TextField(10);
      add(t3);

      b4 = new Button("Clear");
      add(b4);
      b4.addActionListener(this);
    }
    public void actionPerformed(ActionEvent g)
    {
      s1 = txt.getText();
      s2 = s1.toLowerCase();
      count1=0; count2=0; count3=0;
      for(int i=0;i<s2.length();i++)
      {
        if(s2.charAt(i)>='a' &&s2.charAt(i)<='z')
        {
         if(s2.charAt(i)=='a' || s2.charAt(i)=='e'|| s2.charAt(i)=='i'|| s2.charAt(i)=='o'|| s2.charAt(i)=='u')
         {
          count1+=1;
         }
        else
         {
          count2+=1;
        }
       }
       else if(s2.charAt(i)=='.' || s2.charAt(i)=='?'||s2.charAt(i)=='"' || s2.charAt(i)==',' ||(int)s2.charAt(i)==39  ||s2.charAt(i)=='!' ||s2.charAt(i)==':')
       {
         count3+=1;
       }
      }
      if(g.getSource()==b1)
      {
        t1.setText(Integer.toString(count1));
      }
      else if(g.getSource()==b2)
      {
        t2.setText(Integer.toString(count2));
      }
      else if(g.getSource()==b3)
      {
        t3.setText(Integer.toString(count3));
      }
      else if(g.getSource()==b4)
      {
        txt.setText("");
        t3.setText("");
        t1.setText("");
        t2.setText("");
      }
    }
  }
