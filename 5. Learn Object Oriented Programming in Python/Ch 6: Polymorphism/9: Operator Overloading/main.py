class Sword:
    def __init__(self, sword_type):
        self.sword_type = sword_type

    def __add__(self, other):
        if self.sword_type == other.sword_type == "bronze":
            return Sword("iron")
        if self.sword_type == other.sword_type == "iron":
            return Sword("steel")
        raise Exception("can not craft")

