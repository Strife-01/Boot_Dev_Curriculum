class Wall:
    depth = None
    height = None
    width = None
    volume = None
    def __init__(self, depth, height, width):
        self.depth = depth
        self.height = height
        self.width = width
        self.volume = depth * height * width

