import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
import java.io.*;
class solution extends JFrame {

    static JFrame f;

    static JButton b, b1, b2, b3, flc;

    static JTextField l, o1, o2, o3, o4;

    static JLabel l1;

    public static void main(String[] args)
    {
        f = new JFrame("String Manipulator");
        l = new JTextField("");
        o1 = new JTextField("");
        o2 = new JTextField("");
        o3 = new JTextField("");
        o4 = new JTextField("");
        b = new JButton("Count Vowels");
        b1 = new JButton("Count Punctuations");
        b2 = new JButton("Count Consonants");
        b3 = new JButton("Capitalize");
        l1 = new JLabel("Input String");
        flc = new JButton("Load from File");
        b1.addActionListener(new MyHandler());
        b2.addActionListener(new MyHandler());
        b3.addActionListener(new MyHandler());
        b.addActionListener(new MyHandler());
        flc.addActionListener(new MyHandler());
        f.setLayout(null);
        l.setBounds(120, 20, 200, 20);
        b.setBounds(20, 50, 200, 20);
        b1.setBounds(20, 80, 200, 20);
        b2.setBounds(20, 110, 200, 20);
        b3.setBounds(20, 140, 300, 20);
        l1.setBounds(20, 20, 100, 20);
        o1.setBounds(240, 50, 80, 20);
        o2.setBounds(240, 80, 80, 20);
        o3.setBounds(240, 110, 80, 20);
        o4.setBounds(20, 180, 300, 20);
        flc.setBounds(20, 210, 300, 20);
        f.add(l1);
        f.add(l);
        f.add(b);
        f.add(b1);
        f.add(b2);
        f.add(b3);
        f.add(o1);
        f.add(o2);
        f.add(o3);
        f.add(o4);
        f.add(flc);
        f.setBackground(Color.green);
        f.setSize(340, 300);
        f.show();
    }

    public static class MyHandler implements ActionListener
    {
      public void actionPerformed(ActionEvent e) {
        String s1, s2, cap;
        String path="";

        int count1, count2, count3;
        String com = e.getActionCommand(); 
        JFileChooser j = new JFileChooser();
        count1 = 0;
        count2 = 0;
        count3 = 0;
        s1 = l.getText();        l.setBounds(120, 20, 200, 20);

        s2 = s1.toLowerCase();
        cap = s1.toUpperCase();
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
        if(e.getSource()==b)
        {
          o1.setText(Integer.toString(count1));
        }
        else if(e.getSource()==b1)
        {
          o2.setText(Integer.toString(count3));
        }
        else if(e.getSource()==b2)
        {
          o3.setText(Integer.toString(count2));
        }
        else if(e.getSource()==b3)
        {
          o4.setText(cap);
        }
        else if(e.getSource()==flc)
        {
          String strr = "";
          int r = j.showOpenDialog(null);
          if (r == JFileChooser.APPROVE_OPTION)
            {
              File file = j.getSelectedFile();
              path = j.getSelectedFile().getAbsolutePath(); 
                
              try {
                BufferedReader in;
                in = new BufferedReader(new FileReader(file));
                String line = in.readLine();
                while (line != null) {
                  strr = strr + line + "\n";
                  line = in.readLine();
                }
              } catch (FileNotFoundException ex) {
                System.out.print("FNF");
              }
              catch (IOException ex) {
               System.out.print("IOE");
             }
            }
          l.setText(strr);
        }

        if(com.equals("Capitalize")) { 
      try{
             
             path = path.substring(path.lastIndexOf('/')+1);
             File file1 = new File(path);
            File file2 = new File("U"+path); 
            BufferedReader in = (new BufferedReader(new FileReader(file1)));
            PrintWriter out = (new PrintWriter(new FileWriter(file2)));

            int ch;
            while ((ch = in.read()) != -1){

                if (ch>=97 && ch <=122)
                    ch = ch - 32;
                out.write(ch);

            }
            in.close();
            out.close();
      }
      catch(Exception en)
      {
        System.out.println("File Not Found");
      }
        } 



        }
    }
}
