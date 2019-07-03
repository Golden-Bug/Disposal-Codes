package Match;

interface Player{

  void setName(String name);
  String getName();
  void setStatistics(int a);
  int getStatistic();
}

interface Game{
  void playGame();
}
