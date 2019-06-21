 
class Graph():
 
    def __init__(self, V):
        self.V = V
        self.graph = [[0 for column in range(V)] \
                                for row in range(V)]
 
    def isBipartite(self, src):
 
        colorArr = [-1] * self.V
 
        # Assign first color to source
        colorArr[src] = 1
 
        # Create a queue (FIFO) of vertex numbers and 
        # enqueue source vertex for BFS traversal
        queue = []
        queue.append(src)
 
        # Run while there are vertices in queue 
        # (Similar to BFS)
        while queue:
 
            u = queue.pop()
 
            # Return false if there is a self-loop
            if self.graph[u][u] == 1:
                return False;
 
            for v in range(self.V):
 
                # An edge from u to v exists and destination 
                # v is not colored
                if self.graph[u][v] == 1 and colorArr[v] == -1:
 
                    # Assign alternate color to this 
                    # adjacent v of u
                    colorArr[v] = 1 - colorArr[u]
                    queue.append(v)
 
                # An edge from u to v exists and destination 
                # v is colored with same color as u
                elif self.graph[u][v] == 1 and colorArr[v] == colorArr[u]:
                    return False
 
        # If we reach here, then all adjacent 
        # vertices can be colored with alternate 
        # color
        return True
 
n=int(input("Enter the value of row/column"))
g = Graph(n)
#scanning


g.graph = [[0, 1, 0, 1],
            [1, 0, 1, 0],
            [0, 1, 0, 1],
            [1, 0, 1, 0]
            ]
             
print "Yes" if g.isBipartite(0) else "No"
 

