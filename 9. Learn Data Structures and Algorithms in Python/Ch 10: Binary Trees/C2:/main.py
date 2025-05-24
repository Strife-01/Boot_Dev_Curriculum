class BSTNode:
    def height(self):
        if self.val is None:
            return 0
        height_left = None
        height_right = None
        if self.left:
            height_left = 1 + self.left.height()
        if self.right:
            height_right = 1 + self.right.height()
        
        if height_left and height_right:
            return max(height_left, height_right)
        if height_left:
            return height_left
        if height_right:
            return height_right
        return 1
    # don't touch below this line

    def __init__(self, val=None):
        self.left = None
        self.right = None
        self.val = val

    def insert(self, val):
        if not self.val:
            self.val = val
            return

        if self.val == val:
            return

        if val < self.val:
            if self.left:
                self.left.insert(val)
                return
            self.left = BSTNode(val)
            return

        if self.right:
            self.right.insert(val)
            return
        self.right = BSTNode(val)

