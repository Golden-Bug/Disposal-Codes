import java.util.Scanner;

class Storedata {
  protected int top;
  protected int bottom;
  protected int arr[]=new int[10];
  Storedata() {
    this.top=0;
	  this.bottom=0;
  }
  protected void insert(int a) {
    arr[top]=a;
	  top++;
  }
  protected void delete() {
    int k=arr[top];
	  top--;
	  System.out.println("The value deleted is "+k);
  }
}

class Stack extends Storedata {
  Stack() {
    super();
  }
  protected void insert() {
    System.out.println("Enter the value to insert :");
    Scanner in=new Scanner(System.in);
	  int k=in.nextInt();
	  arr[top]=k;
	  top++;
  }
  protected void delete() {
    top--;
	  int k=arr[top];
    System.out.println("The value deleted is "+k);
  }
}

class Queue extends Storedata {
  Queue() {
    super();
  }
  protected void insert() {
    System.out.println("Enter the value to insert :");
    Scanner in=new Scanner(System.in);
    int k=in.nextInt();
    arr[top]=k;
    top++;
  }
  protected void delete() {
    int k=arr[bottom];
    System.out.println("The value deleted is "+k);
  }
}

class Main {
  public static void main(String[] args) {
    Stack st=new Stack();
	  Queue qu=new Queue();
Scanner in=new Scanner(System.in);

System.out.println("For Stack :");
System.out.println("Enter the numbers you want to give");
int k=in.nextInt();
for(int i = 0; i < k; ++i)
{	  st.insert();
	  
}
System.out.println("Enter the numbers you want to delete");
int m=in.nextInt();
for(int i = 0; i < m; ++i)
{
	  st.delete();
}
System.out.println("For Queue :");
System.out.println("Enter the numbers you want to give");
int n=in.nextInt();
for(int i = 0; i < n; ++i)
{
	
	  qu.insert();
}
System.out.println("Enter the numbers you want to delete");
int j =in.nextInt();
for(int i = 0; i < j; ++i)
{
	  qu.delete();
}
  }
}
