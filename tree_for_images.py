from PIL import Image
import imagehash
class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
            else:
                self.data = data
    def findval(self, lkpval):
        if lkpval < self.data:
            if self.left is None:
                return str(lkpval)+"Not Found"
            return self.left.findval(lkpval)
        elif lkpval > self.data:
            if self.right is None:
                return str(lkpval)+"Not Found"
            return self.right.findval(lkpval)
        else:
            print('image is found')
    def deleteNode(root, data):
        # Base Case
        if root is None:return root
        # If the key to be deleted is smaller than the root's
        # key then it lies in left subtree
        if data < root.data:
            root.left = root.left.deleteNode(data)
        # If the kye to be delete is greater than the root's key
        # then it lies in right subtree
        elif(data > root.data):
            root.right = root.right.deleteNode(data)
        # If key is same as root's key, then this is the node
        # to be deleted
        else:
        # Node with only one child or no child
            if root.left is None :
                temp = root.right
                root = None
                return temp
            elif root.right is None :
                temp = root.left
                root = None
                return temp
        # Node with two children: Get the inorder successor
        # (smallest in the right subtree)
        temp = root.right.minValueNode()
        # Copy the inorder successor's content to this node
        root.data = temp.data
        # Delete the inorder successor
        root.right = root.right.deleteNode(temp.data)
        return root
    def minValueNode( node):
        current = node
            # loop down to find the leftmost leafwhile(current.left is not None):
        current = current.left
        return current
def main():
    root = Node(None)
    c=0
while c!=4:
    c=int(input("menu:\n1)insert an image\n2)remove a image\n3)search for a image\n4)exit\n"))
    if(c==1):
        name=input("enter image name: ")
        try:
            data = str(imagehash.average_hash(Image.open(name)))
        except FileNotFoundError:
            print("that image does not exist,try again")
        else:
            root.insert(data)
    elif(c==2):
        name=input("enter image name to be remove:")
        try:
            data = str(imagehash.average_hash(Image.open(name)))
        except FileNotFoundError:
            print("that image does not exist,try again")
        else:
            root = root.deleteNode(data)
    elif(c==3):
        name=input("enter image to be searched in the binary search tree:")
        try:
            data = str(imagehash.average_hash(Image.open(name)))
        except FileNotFoundError:
            print("that image does not exist,try again")
        else:
            root.findval(data)
    elif(c!=4):
        print("invalid choice")
        print("thank you")
if __name__ == "__main__":
    main()