import java.io.*; 
import javax.swing.*; 
import java.awt.event.*; 
import javax.swing.filechooser.*;
 
class filechooser extends JFrame implements ActionListener
{ 
    String path;
    static JLabel l; 
  
    filechooser() 
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
        JButton button3 = new JButton("Count Vowels");
        JButton button4 = new JButton("Count Consonants");
        JButton button5 = new JButton("Count Punctuations");

        filechooser f1 = new filechooser(); 
  
        button1.addActionListener(f1); 
        button2.addActionListener(f1);
		button3.addActionListener(f1);
		button4.addActionListener(f1);
		button5.addActionListener(f1);
 
        JPanel p = new JPanel(); 
  
        p.add(button1);
        p.add(button2);
		p.add(button3);
		p.add(button4);
		p.add(button5);

        l = new JLabel("no file selected"); 
  
        p.add(l); 
        f.add(p); 
  
        f.show(); 
    } 
    public void actionPerformed(ActionEvent evt) 
    { 
        String com = evt.getActionCommand(); 
  
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
        
		else if(com.equals("Capitalize"))
		{ 
			try
			{
             
            	path = path.substring(path.lastIndexOf('/')+1);
             	File file1 = new File(path);
            	File file2 = new File("U"+path); 
            	BufferedReader in = (new BufferedReader(new FileReader(file1)));
            	PrintWriter out = (new PrintWriter(new FileWriter(file2)));

            	int ch;
            	while ((ch = in.read()) != -1)
				{
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

		else if(com.equals("Count Vowels"))
		{ 
			try
			{
             
            	path = path.substring(path.lastIndexOf('/')+1);
             	File file1 = new File(path);
            	BufferedReader in = (new BufferedReader(new FileReader(file1)));
            	
            	int ch,count=0;
            	while ((ch = in.read()) != -1)
				{
	                if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
	                    count++;
				}
            	in.close();
                l.setText(count +"");
			}
			catch(Exception e)
			{
				System.out.println("File Not Found");
			}
        }

		else if(com.equals("Count Consonants"))
		{ 
			try
			{
             
            	path = path.substring(path.lastIndexOf('/')+1);
             	File file1 = new File(path);
            	BufferedReader in = (new BufferedReader(new FileReader(file1)));
            	
            	int ch,countvow=0,count=0;
            	while ((ch = in.read()) != -1)
				{
	                if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
	                    countvow++;
					if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))				
						count++;
				}
            	in.close();
                l.setText((count-countvow)+"");
			}
			catch(Exception e)
			{
				System.out.println("File Not Found");
			}
        }

		else
		{ 
			try
			{
             
            	path = path.substring(path.lastIndexOf('/')+1);
             	File file1 = new File(path);
            	BufferedReader in = (new BufferedReader(new FileReader(file1)));
            	
            	int ch,countpunc=0;
            	while ((ch = in.read()) != -1)
				{
	                if (ch==','||ch=='.'||ch=='!'||ch=='?'||ch==':'||ch==';')
	                    countpunc++;
				}
            	in.close();
                l.setText(countpunc+"");
			}
			catch(Exception e)
			{
				System.out.println("File Not Found");
			}
        } 
    } 
} 

