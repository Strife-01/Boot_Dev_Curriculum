class Unit:
    def __init__(self, name, pos_x, pos_y):
        self.name = name
        self.pos_x = pos_x
        self.pos_y = pos_y

    def in_area(self, x_1, y_1, x_2, y_2):
        """
        Determines if the unit is within the given rectangular area.

        Args:
            x_1 (int/float): The x-coordinate of the bottom-left corner.
            y_1 (int/float): The y-coordinate of the bottom-left corner.
            x_2 (int/float): The x-coordinate of the top-right corner.
            y_2 (int/float): The y-coordinate of the top-right corner.

        Returns:
            bool: True if the unit's position falls inside or on the edge of the
                  rectangle, False otherwise.
        """
        # Ensure x_1 <= x_2 and y_1 <= y_2, as the problem statement implies
        # bottom-left and top-right, but coordinates might be given out of order.
        min_x = min(x_1, x_2)
        max_x = max(x_1, x_2)
        min_y = min(y_1, y_2)
        max_y = max(y_1, y_2)

        return (min_x <= self.pos_x <= max_x) and \
               (min_y <= self.pos_y <= max_y)


class Dragon(Unit):
    def __init__(self, name, pos_x, pos_y, fire_range):
        super().__init__(name, pos_x, pos_y)
        self.__fire_range = fire_range

    def breathe_fire(self, x, y, units):
        """
        Causes the dragon to breathe fire at a target area, hitting units within it.

        The target area is centered at (x, y) and stretches for __fire_range
        in both directions inclusively.

        Args:
            x (int/float): The x-coordinate of the center of the fire blast.
            y (int/float): The y-coordinate of the center of the fire blast.
            units (list): A list of Unit objects to check for hits.

        Returns:
            list: A list of Unit objects hit by the blast.
        """
        hit_units = []

        # Calculate the bounding box of the fire blast
        # The area stretches for __fire_range in both directions inclusively.
        # This means from (x - fire_range) to (x + fire_range) and similarly for y.
        fire_x1 = x - self.__fire_range
        fire_y1 = y - self.__fire_range
        fire_x2 = x + self.__fire_range
        fire_y2 = y + self.__fire_range

        for unit in units:
            if unit.in_area(fire_x1, fire_y1, fire_x2, fire_y2):
                hit_units.append(unit)

        return hit_units
