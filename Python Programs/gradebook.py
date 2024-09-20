class gradebook(object):
    def __init__(self):
        students = []
        grades = {}
        isSorted = True

    def addStudent(self, student):
        if student in students:
            raise ValueError("student already present in the gradebook")
        students.append(student)
        grades[student.getStudentID()] = []
        self.isSorted = False

    def addGrade(self, student, grade):
        try:
            self.grades[student.getStudentID()].append(grade)
        except KeyError:
            print("student not in gradebook")

    def getGrade(self, student):
        try:
            return self.grades[student.getStudentID()][:]
        except KeyError:
            print("student not in gradebook")

    def allStudents(self):
        if not self.isSorted:
            self.students.sort()
        self.isSorted = True
        return self.students[:]

    def getStudentID(self):
        try:
            return self.studentID
        except ValueError:
            print("student without ID number")
