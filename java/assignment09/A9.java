import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.filechooser.*;

class A9 extends JFrame implements ActionListener
{
    String path;
    static JLabel l;
    static JButton b, b1, b2, b3, b4, b5, b6;
    static JTextField t1, t2, t3;
    static JLabel l1, l2, l3, l4;
    String s1, s2, s3=" ";
    String [] array = new String[1000];
    int count1, count2, count3;
    static JTextArea content;

    A9()
    {
    }

    public static void main(String args[])
    {
        JFrame f = new JFrame("file chooser");

        f.setSize(400, 400);

        f.setVisible(true);

        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton button1 = new JButton("Open");
        JButton button2 = new JButton("Capitalize");

        b = new JButton("Load File");

        content = new JTextArea(5,20);

        b1 = new JButton("Count Vowel");

        t1 = new JTextField(10);

        b2 = new JButton("Count Consonants");

        t2 = new JTextField(10);

        b3 = new JButton("Count Punctuations");

        t3 = new JTextField(10);


        A9 f1 = new A9();

        button1.addActionListener(f1);
        button2.addActionListener(f1);
        b.addActionListener(f1);
        b1.addActionListener(f1);
        b3.addActionListener(f1);
        b2.addActionListener(f1);
        JPanel p = new JPanel();

        p.add(button1);
        p.add(button2);
        p.add(b);
        p.add(b1);
        p.add(b2);
        p.add(b3);
        p.add(t1);
        p.add(t2);
        p.add(t3);
        p.add(content);
        content.setEditable(false);
        l = new JLabel("no file selected");

        p.add(l);
        f.add(p);

        f.show();
    }
    public void actionPerformed(ActionEvent g)
    {
        String com = g.getActionCommand();

        if (com.equals("Open"))
        {
            JFileChooser j = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());

            j.setAcceptAllFileFilterUsed(false);

            j.setDialogTitle("Select a .txt file");

            FileNameExtensionFilter restrict = new FileNameExtensionFilter("Only .txt files", "txt");
            j.addChoosableFileFilter(restrict);

            int r = j.showOpenDialog(null);

            if (r == JFileChooser.APPROVE_OPTION)
            {

                path = j.getSelectedFile().getAbsolutePath();
                l.setText(path);
            }
            else
                l.setText("the user cancelled the operation");
        }

        else if(com.equals("Capitalize")) {
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
            catch(Exception e)
            {
                System.out.println("File Not Found");
            }
        }

        int w=0;
        if(g.getSource()==b)
        {
            try
            {
                File file = new File(path);
                Scanner input = new Scanner(file);
                while(input.hasNext())
                {
                    s1 = input.next();
                    s3+=s1;
                    s3+=" ";
                    array[w] = s1;
                    w=w+1;
                }
                content.setText(s3);
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
            count1=0; count2=0; count3=0;
            for(int j=0;j<w;j++)
            {
                s2 = array[j];
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
            }
        }

        else if(g.getSource()==b1)
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

    }
}
