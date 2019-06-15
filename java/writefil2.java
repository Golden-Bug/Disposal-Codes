// WRite a file
public void whenWriteStringUsingBufferedWritter_thenCorrect() 
  throws IOException {
    String str = "Hello";
    BufferedWriter writer = new BufferedWriter(new FileWriter(fileName));
    writer.write(str);
     
    writer.close();
}

// WRinting method 2

@Test
public void givenWritingStringToFile_whenUsingPrintWriter_thenCorrect() 
  throws IOException {
    FileWriter fileWriter = new FileWriter(fileName);
    PrintWriter printWriter = new PrintWriter(fileWriter);
    printWriter.print("Some String");
    printWriter.printf("Product name is %s and its price is %d $", "iPhone", 1000);
    printWriter.close();
}