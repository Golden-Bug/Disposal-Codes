import xml.sax

class StudentDetails( xml.sax.ContentHandler ):
   def __init__(self):
      self.CurrentData = ""
      self.Class = ""
      self.Section = ""
      self.Age = ""
      self.Roll = ""
      self.AvgMarks = ""

   # Call when an element starts
   def startElement(self, tag, attributes):
      self.CurrentData = tag
      if tag == "student":
         title = attributes["name"]
         print("            ",title,end="              ")

   # Call when an elements ends
   def endElement(self, tag):
      if self.CurrentData == "class":
         print( self.Class,end="              ")
      elif self.CurrentData == "section":
         print(self.Section,end="        ")
      elif self.CurrentData == "age":
         print(self.Age,end="        ")
      elif self.CurrentData == "roll":
         print(self.Roll,end="         ")
      elif self.CurrentData == "avg_marks":
         print(self.AvgMarks,end="                                                            ")
      self.CurrentData = ""
      

   # Call when a character is read
   def characters(self, content):
      if self.CurrentData == "class":
         self.Class = content
      elif self.CurrentData == "section":
         self.Section = content
      elif self.CurrentData == "age":
         self.Age = content
      elif self.CurrentData == "roll":
         self.Roll = content
      elif self.CurrentData == "avg_marks":
         self.AvgMarks = content
  
if ( __name__ == "__main__"):
   
   # create an XMLReader
   parser = xml.sax.make_parser()
   # turn off namepsaces
   parser.setFeature(xml.sax.handler.feature_namespaces, 0)

   # override the default ContextHandler
   Handler = StudentDetails()
   parser.setContentHandler( Handler )
   print("........................................................................................")
   print("                                     Student Details")
   print("........................................................................................")
   print("    | Name                  |  Class    |  Section    |   Age  |  Roll | Avg_Marks | ")
   print("........................................................................................")
   parser.parse("sample.xml")
