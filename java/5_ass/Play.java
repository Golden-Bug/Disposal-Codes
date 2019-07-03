package Payroll;

class playdetail implements Salary{
	String club;
	int pay;
 public void Clubname(String club)
    {
      this.club=club;
    }
  public int pay(int pay){
    this.pay =pay;
  	return pay;
  }
  public void display()
    {
      System.out.println(club + " is the club of player \n" + pay + " is the payment of player");
    }
}

class Play{
	public static void main(String args[]){
		playdetail p = new playdetail();
        p.Clubname("Royal");
        p.pay(0);
        p.display();
	}
}