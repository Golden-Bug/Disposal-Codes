import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

class ReadFromFile {
  protected String readFile(String fileName) throws IOException {
      BufferedReader br = new BufferedReader(new FileReader(fileName));
      try {
          StringBuilder sb = new StringBuilder();
          String line = br.readLine();

          while (line != null) {
              sb.append(line);
              sb.append(" ");
              line = br.readLine();
          }
          return sb.toString();
      } finally {
          br.close();
      }
  }

  public static void main(String[] args) throws IOException {
    ReadFromFile obj = new ReadFromFile();
    String fileContents = obj.readFile("/home/ratna/Documents/java/7_ass/sample.txt");
    int ispol = 0;
    int iscric = 0;
    String poldict = obj.readFile("/home/ratna/Documents/java/7_ass/poldict.txt");
    String cricdict = obj.readFile("/home/ratna/Documents/java/7_ass/cricdict.txt");
    fileContents = fileContents.toLowerCase();
    System.out.println(fileContents);
    for(String str: fileContents.split(" ")) {
      for(String stra: cricdict.split(" ")) {
        //System.out.println(stra);
        if(stra.equals(str)){
          iscric++;
        }
      }
      for(String strb: poldict.split(" ")) {
        //System.out.println(strb);
        if(strb.equals(str)){
          ispol++;
        }
      }
    }
    System.out.println(ispol);
    System.out.println(iscric);
    if(ispol>iscric){
      System.out.println("This is related to politics");
      System.out.println("The statistics of matching words are " + ispol);
    }
    else if(ispol<iscric){
      System.out.println("This is related to cricket");
      System.out.println("The statistics of matching words are " + iscric);
    }
    else {
      System.out.println("This algo can't work efficiently on the provided data");
    }
  }
}
