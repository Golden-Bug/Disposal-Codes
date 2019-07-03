interface Player{

  void setName(String name);
  void setStatistics(Statistics obj);
  String getName();
  Statistics getStatistics();
}
interface Game{
  void playGame();
}
class Football implements Player, Game{
  private String playerName;
  private Statistics obj;
  public void setName(String playerName){
    this.playerName = playerName;
  }
  public void setStatistics(Statistics obj){
    this.obj = obj;
  }
  public String getName(){
    return this.playerName;
  }
  public Statistics getStatistics(){
    return this.obj;
  }
  public void playGame(){
    System.out.println(this.playerName + " is playing Football!");
  }
}
class Cricket implements Player, Game{
  private String playerName;
  private Statistics obj;
  public void setName(String playerName){
    this.playerName = playerName;
  }
  public void setStatistics(Statistics obj){
    this.obj = obj;
  }
  public String getName(){
    return this.playerName;
  }
  public Statistics getStatistics(){
    return this.obj;
  }
  public void playGame(){
    System.out.println(this.playerName + " is playing Cricket!");
  }
}
class Statistics{

  public int matchesWon;
  public int matchesLost;
  public double winningRatio;

  public Statistics(int matchesWon, int matchesLost){
    this.matchesWon = matchesWon;
    this.matchesLost = matchesLost;
    this.winningRatio = (double) matchesWon/((double)matchesWon+(double)matchesLost);
  }

  public int getMatchesWon(){
    return matchesWon;
  }

  public int getMatchesLost(){
    return matchesLost;
  }

  public double getWinningRatio(){
    return winningRatio;
  }
}
public class Ass4b{
  public static void main(String[] args){
    Football football = new Football();
    football.setName("Leonardo Messi");
    football.setStatistics(new Statistics(20,5));
    System.out.println("Detail of Football Player:");
    football.playGame();
    Statistics footballStats = football.getStatistics();
    String playerName = football.getName();
    System.out.println("Player Name: " + playerName);
    System.out.println("<---- Football Player Statistics ---->");
    System.out.println("Matches Won: " + footballStats.getMatchesWon());
    System.out.println("Matches Lost: " + footballStats.getMatchesLost());
    System.out.println("Winning Ratio: " + footballStats.getWinningRatio());
    Cricket cricket = new Cricket();
    cricket.setName("MS Dhoni");
    cricket.setStatistics(new Statistics(30,7));
    System.out.println("\nDetail of Cricket Player:");
    cricket.playGame();
    Statistics cricketStats = cricket.getStatistics();
    String cricketPlayerName = cricket.getName();
    System.out.println("Player Name: " + cricketPlayerName);
    System.out.println("<---- Cricket Player Statistics ---->");
    System.out.println("Matches Won: " + cricketStats.getMatchesWon());
    System.out.println("Matches Lost: " + cricketStats.getMatchesLost());
    System.out.println("Winning Ratio: " + cricketStats.getWinningRatio());
  }
}