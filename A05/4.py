class Person:
    name: str
    age: int
    gender: str

    def __init__ (self, name, age, gender):
        self.name = name
        self.age = age
        
        if gender not in {"Male", "Female"}:
            raise ValueError("Invalid gender!")
        
        self.gender = gender

    def get_name (self):
        return self.name
    
    def get_age (self):
        return self.age
    
    def get_gender (self):
        return self.gender
    
    def __str__ (self):
        return f"Name: {self.name}, Age: {self.age}, Gender: {self.gender}"
    
class Student (Person):
    student_id: str
    courses: list

    def __init__ (self, name, age, gender, student_id):
        super().__init__(name, age, gender)
        self.student_id = student_id
        self.courses = []
    
    def add_course (self, course):
        self.courses.append(course)
    
    def remove_course (self, course):
        self.courses.remove(course)

    def __str__ (self):
        return f"Name: {self.name}, Age: {self.age}, Gender: {self.gender}, Student ID: {self.student_id}, Courses: {self.courses}"

name, age, gender, student_id = input().split()

student = Student(name, int(age), gender, student_id)

n = int(input())

for _ in range(n):
    student.add_course(input())

print(student)