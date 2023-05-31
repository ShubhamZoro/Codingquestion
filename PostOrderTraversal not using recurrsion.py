class newNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
 
def postorder(head):
     
    temp = head
    visited = set()
    while (temp and temp not in visited):
         
       
        if (temp.left and temp.left not in visited):
            temp = temp.left
             
       
        elif (temp.right and temp.right not in visited):
            temp = temp.right
         
        else:
            print(temp.data, end = " ")
            visited.add(temp)
            temp = head
