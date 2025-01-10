class Student:
    def __init__(self, name):
        self.name = name
        self.__courses = {}

    def calculate_letter_grade(self, score):
        match score:
            case _ if score >= 90:
                return "A"
            case _ if score >= 80:
                return "B"
            case _ if score >= 70:
                return "C"
            case _ if score >= 60:
                return "D"
            case _:
                return "F"

    def add_course(self, course_name, score):
        self.__courses[course_name] = self.calculate_letter_grade(score)

    def get_courses(self):
        return self.__courses

