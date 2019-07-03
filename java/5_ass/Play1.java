package Match;

class football implements Player,Game{
    String name;
    int statistics;

    public void setName(String name)
    {
      this.name=name;
    }

    public String getName()
    {
      return name;
    }

    public void setStatistics(int statistics)
    {
      this.statistics=statistics;
    }

    public int getStatistic()
    {
      return statistics;
    }

    public void playGame()
    {
      System.out.println(name + " has scored " + statistics);
    }
}

class cricket implements Player,Game{
   String name;
    int statistics;

    public void setName(String name)
    {
      this.name=name;
    }

    public String getName()
    {
      return name;
    }

    public void setStatistics(int statistics)
    {
      this.statistics=statistics;
    }

    public int getStatistic()
    {
      return statistics;
    }

    public void playGame()
    {
      System.out.println(name + " has scored " + statistics);
    }
}

class basketball extends football{

   public void Use()
   {
     super.setName("Shayan");
     super.getName();
     super.setStatistics(55);
     super.getStatistic();
     super.playGame();
   }

}

class Play1{
   public static void main(String args[])
    {
      football f = new football();
       f.setName("Sheena");
       f.getName();
       f.setStatistics(38);
       f.getStatistic();
       f.playGame();

      cricket c = new cricket();
       c.setName("Shlok");
       c.getName();
       c.setStatistics(18);
       c.getStatistic();
       c.playGame();

      basketball b = new basketball();
       b.Use();

}
}
