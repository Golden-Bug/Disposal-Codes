import java.io.*; 
import javax.swing.*; 
import java.awt.event.*; 
import javax.swing.filechooser.*;
 
class A9Q1 extends JFrame implements ActionListener
{ 
    String path;
    static JLabel l; 
  
    A9Q1() 
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
		JButton button5 = new JButton("Count Punctuation");
		

        A9Q1 f1 = new A9Q1(); 
  
        button1.addActionListener(f1); 
        button2.addActionListener(f1); 
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
        
		else if(com.equals("Capitalize")) { 
			try{
             
             path = path.substring(path.lastIndexOf('/')+1);
             System.out.println(path);
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

    } 
} 
