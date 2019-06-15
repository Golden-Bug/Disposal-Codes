// taking file and reading it from command line

public static void main(String[] args) {
  if (0 < args.length) {
    String filename = args[0];
    File file = new File(filename);
  }
}

Scanner scanner = new Scanner(System.in);
System.out.print("Enter a file name: ");
System.out.flush();
String filename = scanner.nextLine();
File file = new File(filename);